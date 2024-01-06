#include <bits/stdc++.h>
using namespace std;
char alpha[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

const int MM = 1e6+5;
const int INF = 0x3F3F3F3F;
const long long INFL = 0x3F3F3F3F3F3F3F3FLL;
typedef long long ll;
typedef pair <ll, int> pli;
typedef pair <int, int> pii;
typedef pair <int, pii> piii;
typedef pair <string, int> psi;
#define endl '\n';
#define FILL(a, b) memset(a, b, sizeof(a))
#define ALL(x) x.begin(), x.end()

//Prime related algorithms
/*
//Crossed off is true (comp)
//Not crossed off is false (prime)
const int limit = 1e6+2;
bool prime[limit];
void sieve(){
    prime[0] = prime[1] = true;
    for(int i = 2; i <= limit; i++) if(!prime[i]) for(int j = 2*i; j <= limit; j+=i) prime[ j ] = true;
}

void primefactorize(ll n){
    for(ll i = 2; i*i <= n; i++){
        while(n%i == 0){
            n /= i;
            cout<<i<<endl;
        }
    }
    if (n != 1) cout<<n<<endl;
}
*/

//Binary Index Tree
/*
int bit[MM][MM];

void update (int r, int c, int val) {
	for(int i=r; i <= MM;  i += i&-i)
		for(int j=c; j<=MM;  j += j & - j)
			bit[i][j] += val;
}
long long query(int r,  int c ) {
	long long sum = 0;
	for(int i=r; i >0; i -= i&-i)
		for(int j=c; j>0; j-= j&-j)
			sum += bit[i][j];
	return sum;
}
*/

//Spare table
/*
void sparse(){
    // base case
    for(int i=1; i<=n; i++)st[0][i] = a[i];
    //fill up sparse table
    for(int k=1; k<= log2(n); k++)for(int i = 1; i + (1<<k) - 1 <= n; i++)st[k][i] = min(st[k-1][i], st[k-1][i+(1<<k-1)]);

}

int query(int L, int R) {
	int k  = log2(R - L + 1 );
	return min(st[k][L], st[k][R - (1<<k) + 1]);
}
*/


//Seg tree

/*
//Seg tree structure, left and right idx, and v is the "val", can be max, min, etc.
struct node{
    int left, right, v, gcd, cnt;
};

//Size 4 * N is enough for seg tree
node seg[4*MM];

//Array to store input values
int a[MM];

//L and R are ranges, idx is the index of the current node: I.E. root node has idx 1
//Build in O(n) time
void build(int l, int r, int idx){
    seg[idx].left = l;
    seg[idx].right = r;

    //Leaf node, is itself
    if(l == r){
        seg[idx].v = a[l];
        seg[idx].cnt = 1;
        seg[idx].gcd = a[l];
        return;
    }


    int mid = (l+r)/2;
    //left seg tree
    build(l, mid, 2*idx);
    //right seg tree
    build(mid+1, r, 2*idx+1);

    //"push up", join left and right answer together for the parent
    seg[idx].v = min(seg[2*idx].v, seg[2*idx+1].v);
    seg[idx].gcd = __gcd(seg[2*idx].gcd, seg[2*idx+1].gcd);
    seg[idx].cnt = 0;
    if(seg[idx].gcd == seg[2*idx].gcd){
        seg[idx].cnt += seg[2*idx].cnt;
    }
    if(seg[idx].gcd == seg[2*idx+1].gcd){
        seg[idx].cnt += seg[2*idx+1].cnt;
    }

}


//Update
//Suppose I have pos = 4, val = 2
//Start from root node (suppose l = 1, r = 6).
//Compare with midpoint of node (1+6)/2
//<= go to left, > go the right
void update(int pos, int val, int idx){

    //Found leaf node when both pointers are equal
    if(seg[idx].left == pos && seg[idx].right == pos){
        seg[idx].v = val;
        seg[idx].gcd = val;
        seg[idx].cnt = 1;
        return;
    }

    int mid = (seg[idx].left + seg[idx].right)/2;
    //Go bother my left child
    if(pos <= mid)update(pos, val, 2*idx);
    //Go bother my right child
    else update(pos, val, 2*idx + 1);

    //Once updated the leaf, fix/update the rest of the parents
    seg[idx].v =  min(seg[2*idx].v, seg[2*idx+1].v);
    seg[idx].gcd = __gcd(seg[2*idx].gcd, seg[2*idx+1].gcd);
    seg[idx].cnt = 0;
    if(seg[idx].gcd == seg[2*idx].gcd){
        seg[idx].cnt += seg[2*idx].cnt;
    }
    if(seg[idx].gcd == seg[2*idx+1].gcd){
        seg[idx].cnt += seg[2*idx+1].cnt;
    }
}

//Query
//L, R for range. Check if they all fall into left child, right child, or both
int query(int l, int r, int idx){

    //Found leaf
    if(seg[idx].left == l && seg[idx].right == r)return seg[idx].v;

    int mid = (seg[idx].left + seg[idx].right)/2;
    //All in left
    if(r <= mid)return query(l, r, 2*idx);
    //All in right
    else if (l>mid)return query(l, r, 2*idx +1);
    //Look in both children
    else return min(query(l, mid, 2*idx), query(mid+1, r, 2*idx + 1));
}

int gcdquery(int l, int r, int idx){

    //Found leaf
    if(seg[idx].left == l && seg[idx].right == r)return seg[idx].gcd;

    int mid = (seg[idx].left + seg[idx].right)/2;
    //All in left
    if(r <= mid)return gcdquery(l, r, 2*idx);
    //All in right
    else if (l>mid)return gcdquery(l, r, 2*idx +1);
    //Look in both children
    else return __gcd(gcdquery(l, mid, 2*idx), gcdquery(mid+1, r, 2*idx + 1));
}
int rgcdquery(int l, int r, int idx, int g){

    //Found leaf
    if(seg[idx].left == l && seg[idx].right == r){
        if(seg[idx].gcd == g)return seg[idx].cnt;
        else return 0;
    }
    int mid = (seg[idx].left + seg[idx].right)/2;
    //All in left
    if(r <= mid)return rgcdquery(l, r, 2*idx, g);
    //All in right
    else if (l>mid)return rgcdquery(l, r, 2*idx +1, g);
    //Look in both children
    else return  rgcdquery(l, mid, 2*idx, g) + rgcdquery(mid+1, r, 2*idx + 1, g);
}
*/
int n, m;
struct edge{
    int u, v, w;
    bool operator<(edge const& other){
        return w > other.w;
    }
};
vector<edge> e;
 //dsu
int parent[MM];
void ms(int v){
    parent[v] = v;
}
 bool vis[MM];

int fs(int v){
    if(v == parent[v])return v;
    return parent[v] = fs(parent[v]);
}

void us(int a, int b){
    a = fs(a);
    b = fs(b);
    if(a != b) parent[b] = a;
}
void init(int n){
    for(int i = 1; i<=n; i++)ms(i);
}


int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int k;
    cin>>n>>m>>k;
    init(n);
    for(int i = 0; i<m; i++){
        int a, b;
        cin>>a>>b;
        int w;
        cin>>w;
        e.push_back({a, b, w});
    }
    sort(e.begin(), e.end());
    memset(vis, 1, sizeof(vis));
    for(int i = 0; i<k; i++){
        int d;
        cin>>d;
        vis[d] = false;
    }
    int cou = 0;
    for(auto nxt : e){
        if(fs(nxt.u) != fs(nxt.v)){
            if(!vis[nxt.u]){
                vis[nxt.u] = 1;
                cou++;
            }
            if(!vis[nxt.v]){
                vis[nxt.v] = 1;
                cou++;

            }
            if(cou == k){
                cout<<nxt.w;
                return 0;
            }
            us(nxt.u, nxt.v);
        }
    }

}
