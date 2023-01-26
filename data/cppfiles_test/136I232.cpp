#include<bits/stdc++.h>
using namespace std;
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    #endif

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int b[n+1]={0};
        for(int i=1;i<=n;i++){
            cin>>b[i];
        }
        int sum=0;
        for(int i=1;i<=n;i++){
            sum=sum+b[i];
        }
        // cout<<sum<<endl;
        if(sum%((n*(n+1))/2)==0){
            sum=sum/((n*(n+1))/2);
        }
        else{
            cout<<"NO"<<endl;
            continue;
        }
        // cout<<sum<<endl;
        if(sum<n){
            cout<<"NO"<<endl;
            continue;
        }
        int ans[n+1]={0};
        for(int i=2;i<=n;i++){
            ans[i]=((b[i-1]-(b[i]-sum))/n);
        }
        ans[1]=((b[n]-(b[1]-sum))/n);
        // for(int i=1;i<=n;i++){
        //         cout<<ans[i]<<" ";
        //     }
        //     cout<<endl;
        int check=0;
        for(int i=1;i<=n;i++){
            check=check+ans[i];
        }
        if(check!=sum){
            cout<<"NO"<<endl;
        }
        else{
            for(int i=1;i<=n;i++){
                cout<<ans[i]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}