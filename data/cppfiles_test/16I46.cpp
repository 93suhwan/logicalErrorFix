#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define ordered_set tree <ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>

typedef long long ll;

const ll M=998244353;

void solve(int testNo){
    ll n;
    cin>>n;
    vector<ll> a(n);
    ll mx=-1;
    ll sum=0,p=-1;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    priority_queue<pair<ll,ll>> pq;
    for(int i=0;i<n;i++){
        pq.push({a[i],i});
    }
    vector<pair<ll,ll>> ans;
    while(!pq.empty()){
        pair<ll,ll> p1=pq.top();
        pq.pop();
        if(pq.empty()){
            break;
        }
        pair<ll,ll> p2=pq.top();
        pq.pop();
        ll mn=min(p1.first,p2.first);
        for(int i=0;i<mn;i++){
            ans.push_back({p1.second,p2.second});
        }
        p1.first-=mn;
        p2.first-=mn;
        if(p1.first!=0){
            pq.push(p1);
        }
        if(p2.first!=0){
            pq.push(p2);
        }
    }
    cout<<ans.size()<<"\n";
    for(auto it:ans){
        cout<<it.first+1<<" "<<it.second+1<<"\n";
    }
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
    #endif
 
    int t=1;
    cin>>t;
    int tt=t;
 
    while(t--){
        //cout<<"Case #"<<tt-t<<": ";
        solve(tt-t);
    }
    return 0;
}