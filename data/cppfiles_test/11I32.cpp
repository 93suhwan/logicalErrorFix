
#include <bits/stdc++.h>  
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;   
using namespace std;
typedef long long ll;
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> 


class comp{
    public:
    bool operator()(const pair<ll,ll> &a, pair<ll,ll> &b){
        if(a.first <= b.first && a.second <= b.second)
            return true;
        return false;
    }
};

int lis(vector<pair<ll,ll>> const& a) {
    int n = a.size();
    const ll INF = 1e9;
    vector<pair<ll,ll>> d(n+1, {INF,INF});
    d[0] = {-INF,-INF};

    for (int i = 0; i < n; i++) {
        int j = upper_bound(d.begin(), d.end(), a[i],comp()) - d.begin();
        if (d[j-1].second <= a[i].second && d[j-1].first <= a[i].first && a[i].first <= d[j].first && a[i].second <= d[j].second)
            d[j] = a[i];
    }

    int ans = 0;
    for (int i = 0; i <= n; i++) {
        if(d[i] < make_pair(INF,INF))
            ans = i;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin>>n;
    vector<ll> arr(n);
    for(ll i =0;i<n;i++)
        cin>>arr[i];
    
    vector<pair<ll,ll>> arr2;
    for(ll i = 0;i<n;i++){
        ll val = i+1 - arr[i];
        if(val >=0)
        arr2.push_back({val,arr[i]});
    }
    //for(auto i:arr)
    //    cout<<i<<" ";
    //cout<<endl;
    //for(auto i:arr2)
    //    cout<<i.first<<i.second<<" ";
    //cout<<endl;
    
    cout<<lis(arr2)<<endl;
    return 0;
}