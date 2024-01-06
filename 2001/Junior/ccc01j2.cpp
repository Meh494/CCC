#include <bits/stdc++.h>
using namespace std;
char alpha[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
//const int MM;
typedef long long ll;
typedef pair <ll, int> pli;
typedef pair <int, int> pii;
typedef pair <string, int> psi;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int x,m;
    cin>>x>>m;
    bool found = false;
    for(int i = 0; i<=m; i++){
        if(i*x %m == 1){
            found = true;
            cout<<i;
            break;
        }
    }
    if(!found)cout<<"No such integer exists.";


}
