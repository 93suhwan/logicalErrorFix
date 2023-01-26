#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

/*---------------------DEFINES----------------------------------------------------*/
#define ll long long
#define ld long double
#define VL vector<ll>
#define VB vector<bool>
#define VS vector<string>
#define VPLL vector<pair<ll, ll>>
#define ordered_set tree <ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
#define SL set<ll>
#define FST first
#define SND second
#define PB push_back
#define I insert
#define PU push
#define PO pop
#define sz(x) (ll)x.size()
#define LOWBND(v, x) (lower_bound(v.begin(), v.end(), x) - v.begin())
#define UPPBND(v,x) (upper_bound(v.begin(),v.end(),x)-v.begin())
#define BSRCH(v,x) (binary_search(v.begin(),v.end(),x))
#define F(i, a, b) for (i = a; i < b; i++)
#define FILL(a, b) memset(a, b, sizeof(a))
#define INPUT(v, n) for (ll i = 0; i < n; i++) cin >> v[i];
#define INPUT2D(v, r, c) for (ll i = 0; i < r; i++){for (ll j = 0; j < c; j++)cin >> v[i][j];}
#define SORT(v) sort(v.begin(), v.end());
#define SORTG(v) sort(v.begin(), v.end(), greater<ll>());
#define RVS(v) reverse(v.begin(), v.end());
#define DISPLAY(v) for (auto k : v){cout << k <<" ";} cout<<endl;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl "\n";
#define PI 3.141592653589793238462
#define INF 2e18
const ll mod=1e9+7;

/*---------------------DEBUG----------------------------------------------------*/
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template <typename T, typename V>void __print(const pair<T, V> &x){cerr << '{';__print(x.first);cerr << ',';__print(x.second);cerr << '}';}
template <typename T>void __print(const T &x){int f = 0;cerr << '{';for (auto &i : x)cerr << (f++ ? "," : ""), __print(i);cerr << "}";}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>void _print(T t, V... v){__print(t);if (sizeof...(v))cerr << ", ";_print(v...);}
#ifndef ONLINE_JUDGE
#define DBG(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define DBG(x...)
#endif

/*---------------------USER DEFINED FUNCTIONS----------------------------------------------------*/
//a-> + or - number
inline ll MOD(ll a, ll m)
{
    return (a % m + m) % m;
}

ll BinPower(ll x,ll y,ll mod) //Calculate A^B%P
{
    ll res = 1;
    x = MOD(x ,mod);
    if (x == 0) return 0;
    while (y > 0)
    {
        if (y & 1)
            res = MOD((res*x) , mod);
        y = y>>1;
        x = MOD((x*x) , mod);
    }
    return res;
}

ll Add(ll a, ll b){a = a % mod;b = b % mod;return (((a + b) % mod) + mod) % mod;}
ll Sub(ll a, ll b){a = a % mod;b = b % mod;return (((a - b) % mod) + mod) % mod;}
ll Mul(ll a, ll b){a = a % mod;b = b % mod;return (((a * b) % mod) + mod) % mod;}
ll Div(ll a, ll b) {a = a % mod;b = b % mod;return Mul(a, BinPower(b, mod - 2, mod));}
bool IsPerSquare(ll a) {if(a<0) return false; ll sr = sqrt(a); return (sr*sr == a);}
inline ll Lcm(ll a , ll b)  {return (a*b)/__gcd(a,b) ;}

/*---------------------CODE BEGINS----------------------------------------------------*/

void Never_Give_Up()
{
    ll i, j;
    ll n, m;
    cin >> n >> m;

    ll sight[n * m];
    INPUT(sight, n * m);

    set<ll> st;
    map<ll, ll> cntmp;
    F(i, 0, n * m)
    {
        st.I(sight[i]);
        cntmp[sight[i]]++;
    }

    map<ll, ll> mp;//original,replaced value
    ll currele = 1;
    VL first(1000), last(1000);
    first[0] = 0;
    last[0] = -1;
    for (auto ele : st)
    {
        mp[ele] = currele;
        first[currele] = last[currele - 1]+1;
        last[currele] = first[currele] + cntmp[ele]-1;
        currele++;
    }
    // cout << "IND: " << endl;

    // F(i,1,3)
    // {
    //     cout << first[i] << " " << last[i] << endl;
    // }

    // cout << "LAST: " << endl;

    bool filled[n * m] = {0};
    ll ans = 0;

    F(i,0,n*m)
    {
        ll num = mp[sight[i]];
        ll firstind = first[num];
        ll lastind = last[num];
        DBG(firstind, lastind);

        ll nextval = (firstind + m)/m;
        nextval = m * nextval - 1;
        ll orignnextval = nextval;
        DBG(nextval);

        for (ll val = nextval; val >= (orignnextval-m+1);val--)
        {
            ll nu = val;
            if(nu<firstind)
                nu += m;
            ll currans = -1;
            ll whichind=-1;
            while (nu <= lastind)
            {
                if(!filled[nu])
                {
                    ll ans1 = 0;
                    ll ind = nu / m;
                    ind = ind * m;
                    for (ll k = ind; k < nu;k++)
                    {
                        if(filled[k])
                        {
                            ans1++;
                        }
                    }
                    if(currans==-1)
                    {
                        currans = ans1;
                        whichind = nu;
                    }
                    else
                    {
                        if(currans>ans1)
                        {
                            currans = ans1;
                            whichind = nu;
                        }
                    }
                }
                DBG(whichind,currans);
                nu += m;
            }

            // DBG(whichind);

            if(currans!=-1)
            {
                ans += currans;
                filled[whichind] = true;
                break;
            }
        }
    }

    cout << ans << endl;
}
signed main()
{
    FAST;
    ll tc = 1;
    cin >> tc;
    while (tc--)
    {
        Never_Give_Up();
    }
}