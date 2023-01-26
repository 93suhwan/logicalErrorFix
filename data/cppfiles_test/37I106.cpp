#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pb push_back
#define pl pair<ll, ll>
#define vl vector<ll>
#define mod 1000000007
#define N 200003
#define inf 1e18

int main()
{
    fastIO
    ll t; cin>>t;
    while(t--)
    {
        ll n, m; cin>>n>>m;
        vector<pl> v;
        ll vis[n+1] = {0};
        for(ll i = 0; i < m; i++) 
        {
            ll a, b, c; cin>>a>>b>>c;
            if(!vis[c]) v.pb({a, c});
            if(!vis[b]) v.pb({b, c});
            vis[b] = 1, vis[c] = 1, vis[a] = 1;
        }
        ll len = v.size();
        for(ll i = 0; i < len; i++) cout<<v[i].first<<" "<<v[i].second<<"\n";
    }
}