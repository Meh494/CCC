#include <bits/stdc++.h>
using namespace std;
char alpha[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

const int MM = 26;
const int INF = 0x3F3F3F3F;
const long long INFL = 0x3F3F3F3F3F3F3F3FLL;
typedef long long ll;
typedef pair <ll, int> pli;
typedef pair <int, int> pii;
typedef pair <string, int> psi;
#define endl '\n';
#define f first
#define s second
#define FILL(a, b) memset(a, b, sizeof(a))
#define ALL(x) x.begin(), x.end()

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
int r, c, n, k;
int arr[MM][MM];
int rm[500];
void bfs(int i, int j, int k){
    if(i >= 0 && i<r && j>= 0 && j<c && arr[i][j] == 0){
        arr[i][j] = k;
        bfs(i-1, j, k);
        bfs(i+1, j, k);
        bfs(i, j-1, k);
        bfs(i, j+1, k);
    }
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);


    cin>>n>>r>>c;
    for(int i = 0; i<r; i++){
        string in;
        cin>>in;
        for(int j = 0; j<c; j++){
            if(in[j] == 'I')arr[i][j] = -1;
            else arr[i][j] = 0;
        }
    }
    k = 1;
    for(int i = 0; i<r; i++){
        for(int j = 0; j<c; j++){
            if(arr[i][j] == 0){
                bfs(i, j, k);
                k++;
            }
        }
    }

    for(int i = 0; i<r; i++){
        for(int j = 0; j<c; j++){
            if(arr[i][j] > 0){
                rm[arr[i][j]]++;
                //cout<<'r';
            }
        }
    }
    bool ch = 0;
    int counter = 0;
    while(!ch && n>0){
           // cout<<'r';
        int m = 0;
        for(int i = 0; i<500; i++){
            if(rm[i] > rm[m]) m = i;
        }
        if(rm[m] > 0){
            if(rm[m] <= n){
                n -= rm[m];
                rm[m] = -1;
                counter++;

            }
            else{
                ch = 1;

            }
        }
        else{
            ch = 1;
        }
    }
    if(counter == 1)cout<<counter<<" room, "<<n<<" square metre(s) left over";
    else cout<<counter<<" rooms, "<<n<<" square metre(s) left over";
}
