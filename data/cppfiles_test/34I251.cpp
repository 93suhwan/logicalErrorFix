#include<bits/stdc++.h>
using namespace std;
long long int max_(long long int a,long long int b){
    if(a>b){
        return a;
    }
    return b;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        long long int arr[n+1]={0};
        for(int i=1;i<=n;i++){
            cin>>arr[i];
        }
        long long int ans=0;
        for(int i=1;i<n;i++){
            ans=max_(arr[i]*arr[i+1],ans);
        }
        cout<<ans<<endl;
    }    
    return 0;
}  
                          