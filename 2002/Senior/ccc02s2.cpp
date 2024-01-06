#include <bits/stdc++.h> 
using namespace std;
char alpha[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    
    
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);  
     int n, d;
     cin>>n>>d;
     int num = n%d;
     if((n-num)/d != 0){
     cout<<(n-num)/d;
     }
     if((n-num)/d != 0 && num != 0 ){
     cout<<" ";
     }
     if(num != 0 ){
         for(int i = 2; i<=num; i++){
             if(num%i == 0 && d%i == 0){
                 num /=i;
                 d /=i;
             }
         }
         cout<<num<<"/"<<d;
     }
     cout<<endl;
}
