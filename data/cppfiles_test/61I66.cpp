#include<bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class A> using ordered_set=tree<A,null_type,less<A>,rb_tree_tag,tree_order_statistics_node_update>;

#define ll long long 
#define int long long
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define all(x) x.begin(),x.end()
#define debug(a...) cout<<#a<<": ";for(auto &it:a)cout<<it<<" ";cout<<"\n";
#define pb push_back
#define br "\n"
const int mod=1e9+7;
const int maxn=2e5+9;
const int INF=1e18;

// ---------------------------------------------------------------------

// ---------------------------------------------------------------------

// ---------------------------------------------------------------------
void test_case(int tno)
{
    int n;
    cin>>n;
    map<int,vi>mp;
    map<int,int>s;
    for(int i=0;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        mp[u].push_back(v);
        s[v]++;
    }
    int ans=0;
    for(auto &it:mp)
    {
        vector<int>v=it.second;
        for(auto &it2:v)
            s[it2]--;
        int ctri=0,ctro=0,ctrod=0;
        for(auto &it2:v)
        {
            if(s[it2]>0)
                ctro++;
            ctrod+=s[it2];
        }
        ctri=v.size()-ctro;
        ans+=ctri*ctrod+(ctro-1)*ctrod;
    }
    ans=(n*(n-1)*(n-2))/6-ans;
    cout<<ans<<br;
}

int32_t main()
{
    ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif    
    int t=1;
    cin>>t;
    for(int i=1;i<=t;i++)
        test_case(i);
}