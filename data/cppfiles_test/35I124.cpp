#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int,null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ordered_set_pair tree<pair<int,int>,null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>
#define ordered_set_mutiset tree<int,null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
typedef long long int ll;
typedef long double ld;
typedef unsigned long long int ull;
typedef pair<int, int> pi;
#define PI 3.1415926535897932384
#define FOR(i,vv,n) for(ll i=vv;i<n;i++)
#define FORR(i,n,vv) for(ll i=n-1;i>=vv;i--)
#define ve vector
#define maxind(v) (max_element(v.begin(),v.end())-v.begin())
#define minind(v) (min_element(v.begin(),v.end())-v.begin())
#define maxe(v) *max_element(v.begin(),v.end())
#define mine(v) *min_element(v.begin(),v.end())
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define eb emplace_back
#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mp make_pair
#define M 1000000007ll
#define INF 1000000000000000000ll
#define PRECISE cout.precision(18);
#define all(v) v.begin(),v.end()
#define BS(v,n) binary_search(v.begin(),v.end(),n)
#define srt(v) sort(v.begin(),v.end())
#define rsrt(v) sort(v.begin(),v.end(),greater <ll>())
#define uni(v) v.resize(unique(v.begin(),v.end())-v.begin())
#define F first
#define S second
#define GET(i,p) get<p>(i)



int main()
{
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt 
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
     #endif

    FAST
    PRECISE


    ll t;
    cin>>t;
    FOR(i1,0,t){
        ll n,m;
        cin>>n>>m;
        ll ans = 0;
        ll ok = 1;
        ll lasb = 31;
        FORR(i,31,0){
            ll z1 = (n&(1ll<<i));
            ll z2 = (m&(1ll<<i));
            if(z1!=0)z1=1;
            if(z2!=0)z2=1;
            if(z2>z1)ans += (1ll<<i), lasb = i;
            else if(z2 < z1){ok = 0; break;}
        }

        if(ok){
            ll ex = 1;
            FOR(i,0,lasb){
                ll z = (n&(1ll<<i));
                if(z==0){
                    ex = (1ll<<i);
                    break;
                }
            }
            ans += ex;
        }
        cout<<ans<<"\n";

    }


    return 0;
}

