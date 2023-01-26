// #define ONLINE_JUDGE
//                 _
//                (_)
// _ __ ___   __ _ _  ___  _ __ _ __ ___
//| '_ ` _ \ / _` | |/ _ \| '__| '__/ _ \ 
//| | | | | | (_| | | (_) | |  | | | (_) |
//|_| |_| |_|\__,_| |\___/|_|  |_|  \___/
//               _/ |
//              |__/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef tree<
    ll, //
    null_type,
    greater<ll>, //
    rb_tree_tag,
    tree_order_statistics_node_update>
    ordered_set;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rngl(chrono::steady_clock::now().time_since_epoch().count());

#define majorro              \
    cout.precision(20);      \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define pb push_back
#define forn(i, n) for (ll(i) = 0; (i) < (n); ++(i))
#define fornm(i, m, n) for (ll(i) = (m); (i) < (n); ++(i))
#define rfornm(i, m, n) for (ll(i) = (m); (i) >= (n); --(i))
#define readvec(vector, n)                  \
    {                                       \
        ll temp_vec_val;                    \
        forn(inc, n)                        \
        {                                   \
            cin >> temp_vec_val;            \
            vector.push_back(temp_vec_val); \
        }                                   \
    }
#define printvec(vector, delimeter)                                                     \
    {                                                                                   \
        ll length_of_vector = vector.size();                                            \
        forn(elementvec, length_of_vector) { cout << vector[elementvec] << delimeter; } \
    }
#define all(vector) (vector).begin(), (vector).end()
#define rall(vector) (vector).rbegin(), (vector).rend()
#define endl "\n"
#define sz(something) (ll) something.size()

struct pair_hash
{
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2> &pair) const
    {
        return hash<T1>()(pair.first) ^ hash<T2>()(pair.second);
    }
};

const ld EPS = 1e-7;
const ll MOD = 1e9 + 7;
// const ll MOD = 998244353;
const ll INF = 1e18;
const ld pi = 2.0 * acos(0.0);
ll n, m, k, p, q, t, sum = 0, cnt = 0;
ll mx = -INF;
ll mn = INF;
bool flag = 0;
vll v;
string s = "", s1, s2;
char c;

void solve()
{
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        v.clear();
        readvec(v,n);
        vector<vector<vll>> dp(n+1,vector<vll>(n+1,vll(2,0)));
        fornm(i,1,n+1)
        {
            forn(j,n+1)
            {
                p = i-j==v[i-1];
                q = i-(j-1)==v[i-1];
                dp[i][j][0] = max(dp[i][j][0],dp[i-1][j][0]+p);
                dp[i][j][1] = max(dp[i][j][1],dp[i-1][j][0]);
                if(j)
                {
                    dp[i][j][0] = max(dp[i][j][0],dp[i-1][j-1][1]+q);
                    dp[i][j][1] = max(dp[i][j][1],dp[i-1][j-1][1]);
                }
            }
        }
        flag=0;
        forn(i,n+1)
        {
            if(dp[n][i][0]>=k||dp[n][i][1]>=k)
            {
                flag=1;
                cout << i << endl;
                break;
            }
        }
        if(!flag) cout << -1 << endl;
    }
}

int main()
{
#if defined ACMP
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#elif !defined ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    majorro
    solve();
    return 0;
} //