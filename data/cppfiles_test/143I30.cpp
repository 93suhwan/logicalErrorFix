#include <bits/stdc++.h>
#define int long long
using namespace std;
#define pb push_back
#define mod 1000000007
#define INF 1000000000000000003

 

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        int count[n+1]={0};
        int mex[n+1];
        for (int i=0;i<n;i++){
            cin>>a[i];
            count[a[i]]++;
        }
        int prefix[n+1];
        prefix[0]=0;
        for (int i=1;i<=n;i++){
            prefix[i]=prefix[i-1]+count[i-1];
        }
        
        mex[0]=count[0];
        mex[1]=count[1];
        
        
        
        
        
        int dp[n];
        dp[0]=0;
        vector<int> usable;
        for (int i=0;i<count[0]-1;i++){
            usable.pb(0);
        }
        
        for (int i=1;i<=n;i++){
            if (mex[i]==-1){
                mex[i+1]=-1;
                continue;
            }
            if (count[i]>0){
                dp[i]=dp[i-1];
                
                while(count[i]>1){
                    usable.pb(i);
                    count[i]--;
                }
            }
            else{
                if (usable.size()==0){
                    mex[i+1]=-1;
                    continue;
                }
                dp[i]=dp[i-1]+i-usable.back();
                usable.pop_back();
            }
            mex[i+1]=dp[i]+count[i+1];
            
            

        }
        for (int i=0;i<=n;i++){
            cout<<mex[i]<<" ";
        }
        cout<<endl;

        


    }
        
      
 
        
        
 
    
    
    
    return 0;
}