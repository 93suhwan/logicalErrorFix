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
        long long int n;
        cin>>n;
        long long int b[n+1]={0};
        for(int i=1;i<=n;i++){
            cin>>b[i];
        }
        long long int sum=0;
        for(int i=1;i<=n;i++){
            sum=sum+b[i];
        }
        if((sum%((n*(n+1))/2))==0){
            sum=(sum/((n*(n+1))/2));
        }
        else{
            cout<<"NO"<<endl;
            continue;
        }
        if(sum<n){
            cout<<"NO"<<endl;
            continue;
        }
        long long int ans[n+1]={0};
        long long int flag=0;
        for(int i=2;i<=n;i++){
            if(((b[i-1]-(b[i]-sum))%n)==0){
                ans[i]=((b[i-1]-(b[i]-sum))/n);
                if(ans[i]<0){
                    flag=1;
                }
            }
            else{
                flag=1;
                break;
            }
        }
        if(((b[n]-(b[1]-sum))%n)==0){
            ans[1]=((b[n]-(b[1]-sum))/n);
            if(ans[1]<0){
                flag=1;
            }
        }
        else{
            flag=1;
        }
        if(flag){
            cout<<"NO"<<endl;
            continue;
        }
        long long int check=0;
        for(int i=1;i<=n;i++){
            check=check+ans[i];
        }
        if(check!=sum){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
            for(int i=1;i<=n;i++){
                cout<<ans[i]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}