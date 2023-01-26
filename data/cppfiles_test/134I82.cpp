#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp> 
#include<ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds;

#define pbds tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long int
#define mem0(arr) memset(arr,0,sizeof(arr));
#define mem1(arr) memset(arr,-1,sizeof(arr));
#define mod 1000000007 // 998244353 //
#define all(v1) v1.begin(),v1.end()
#define pb push_back
#define um unordered_map
#define ff first
#define ss second
#define cont continue
#define ret return
#define br break

ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mypow(ll a, ll b) { ll res=1; while(b>0) { if(b&1) res=mod_mul(res,a,mod); a=mod_mul(a,a,mod); b=b>>1; } return res; }
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mypow(b, m-2),m) + m) % m;}  
ll gcd(ll a,ll b) { if(!b) return a; return gcd(b,a%b);}

//--------------------------------------------------------------------------------------------------------------------------


void solve()
{
        ll n,i;
        cin >> n;
        vector<ll>v1(n);
        for(i=0;i<n;i++)
        {
                cin >> v1[i];
        }
        ll g1=v1[1],g2=v1[0];
        for(i=0;i<n;i++)
        {
                if(i&1)
                {
                        g1 = gcd(g1,v1[i]);
                }
                else{
                        g2= gcd(g2,v1[i]);
                }
        }
        ll m1=1,m2=1;
        for(i=0;i<n;i++)
        {
                if(i&1)
                {
                        if(v1[i]%g2 == 0)
                        {
                                m1=0;
                        }
                }
                else{
                        if(v1[i]%g1 == 0)
                        {
                                m2=0;
                        }
                }
        }
        if(m1 || m2)
                cout << max(g1,g2) << "\n";
        else
                cout << "0\n";
}

int main()
{   
        FAST; // remove in interactive
        ll testcases=1;
        cin >> testcases;
        // for(ll tt=1;tt<=testcases;tt++)
        while(testcases--)
        {
                // cout << "Case #" << t << ": ";
                solve();
        }
}
