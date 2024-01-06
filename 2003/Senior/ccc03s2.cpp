#include <bits/stdc++.h> 
using namespace std;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); 
     int n;
     cin>>n;
     for(int j = 0; j<n; j++){
         string arr[4];
          for(int l = 0; l<4; l++){
         string s1;
        // cin.ignore();
                 cin>>ws;

         getline(cin, s1);
         string prev = "";
         for(char c : s1){
             c = tolower(c);

             if(c == ' '){
                 prev = "";
             }
             else{
                 prev += c;
             }
         }
         int v = 0;
         for(int i = prev.size()-1; i>=0; i-- ){
             if(prev[i] == 'a'||prev[i] == 'e'||prev[i] == 'i'||prev[i] == 'o'||prev[i] == 'u'){
                 v = i;
                 break;
             }
         }
         for(int k = v; k<prev.size(); k++){
             arr[l] += prev[k];
         }
         //cout<<arr[l];
         
      }
        // cout<<arr[0]<<arr[1]<<arr[2]<<arr[3];
         if(arr[0]==arr[1] && arr[1] == arr[2] && arr[2] == arr[3]){
             if(arr[0] != ""){
             cout<<"perfect"<<"\n";
             }
         }
         else if(arr[0]==arr[2] && arr[1] == arr[3]){
             cout<<"cross"<<"\n";
         }
            else if(arr[0]==arr[1] && arr[2] == arr[3]){
             cout<<"even"<<"\n";
         }  
        else if(arr[0]==arr[3] && arr[2] == arr[1]){
             cout<<"shell"<<"\n";
         } 
         else{
             cout<<"free"<<"\n";
         }
     }
      
}
