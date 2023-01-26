#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
#define int long long

signed main() {
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;

    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    vector<int> dp(501,INT32_MAX);
    dp[0] = 0;
    for(int i=0;i<n;i++){
//        dp[a[i]] = min(dp[a[i]],a[i]);

        for(int j=0;j<dp.size();j++){
            if(dp[j]<a[i]){
                int x = (j^a[i]);
                dp[x] = min(dp[x],a[i]);
            }
        }
    }

    vector<int> ans;
    for(int i=0;i<dp.size();i++){
        if(dp[i]!=INT32_MAX){
            ans.push_back(i);
        }
    }

    cout<<ans.size()<<endl;
    for(auto i:ans){
        cout<<i<<" ";
    }
}



















