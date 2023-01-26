#include<bits/stdc++.h>
using namespace std;
 
 
int main(){
 
 int t;
 cin>>t;
 while(t--){
     int n;
     cin>>n;
     int arr[n] = {0};
     for(int i = 0;i<n;i++){
         cin>>arr[i];
     };
     int start = 1;
     int end = n-1;
     int s1 = 0;
     int s2 = 0;
     while(start< end){
         s1+=arr[start];
         s2+=arr[end];
         start++;
         end--;
     }
     cout<<max(s1,s2)-min(s1,s2)<<endl;
     
 }
 
    return 0;

}