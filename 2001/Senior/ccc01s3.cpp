#include <bits/stdc++.h>
using namespace std;
char alpha[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

const int MM = 1002;
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


int main() {
    bool adj[26][26];
    string arr[MM];
    string s;
    int a, b;
    int n, C;
    n = 0;
    C = 0;
    while(true){
        cin>>s;
        if(s == "**"){
            break;
        }
        arr[n++] = s;
    }

    for(int i = 0; i < n; i++){
         for(int j = 0; j < 26; j++){
            for(int k = 0; k < 26; k++){
                if(k == j){
                    adj[j][k] = true;
                }
                else{
                    adj[j][k] = false;
                }
            }
        }

         for(int j = 0; j < n; j++){
            if(j != i){
                a = arr[j][0] - 'A';
                b = arr[j][1] - 'A';
                adj[a][b] = true;
                adj[b][a] = true;
            }
        }

      for(int y = 0; y < 26; y++){
            for(int x = 0; x < 26; x++){
                if(adj[x][y]){
                    for(int j = 0; j < 26; j++){
                        if(adj[y][j]){
                            adj[x][j] = true;
                        }
                    }
                }
            }
        }

        if(!adj[0][1]){
            cout<<arr[i]<<endl;
            C++;
        }
    }

    cout<<"There are "<<C<<" disconnecting roads."<<endl;


}
