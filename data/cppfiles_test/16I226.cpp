#include<bits/stdc++.h>
#include<iostream>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define w(x)                int x;cin>>x;while(x-->0)
#define ll                  long long int
#define mod                 1000000007
#define arin(a)             for (auto &it : a) cin >> it;
#define dbg(ar,st,ed)       for(ll i=st;i<=ed;i++)cout<<ar[i]<<" ";cout<<endl;
#define endl               "\n"
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> PBDS;

void solve(){
    ll n;cin>>n; vector<ll> ar(n);arin(ar);
    sort(ar.begin(),ar.end());
    ll i=0,j=n-1;
    vector<pair<ll,ll>> ans;
    while(i<j){
        if(ar[i]==0)i+=1;
        else if(ar[j]==0)j-=1;
        else{
            ans.push_back({i+1,j+1});
            ar[i]-=1;
            ar[j]-=1;
        }
    }
    cout<<ans.size()<<endl;
    for(ll i=0;i<ans.size();i++)cout<<ans[i].first<<" "<<ans[i].second<<endl;
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    w(t)solve();
    //solve();
}