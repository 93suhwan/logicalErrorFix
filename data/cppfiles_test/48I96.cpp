#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#pragma GCC optimize("O3")
#pragma GCC target("sse4")

using namespace std;
using namespace __gnu_pbds;

#define endl "\n" //interactive
#define pb push_back
#define int long long
#define ll long long
#define ld long double
#define pii pair<ll, ll>
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vpi;
template <class T>
using pq = priority_queue<T>;
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;

#define all(value) value.begin(), value.end()
#define f(a, b, c) for (ll a = b; a < c; a++)
#define For(i, n) for (ll i = 0; i < n; i++)
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

template <class T>
bool ckmin(T &a, const T &b)
{
    return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T &a, const T &b)
{
    return a < b ? a = b, 1 : 0;
}
#define deb(value) cerr << #value << " is =" << value << endl;
#define derun deb("running");

#define RAND srand(chrono::steady_clock::now().time_since_epoch().count());
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update> omultiset;
typedef tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update> oset;
typedef tree<long long, null_type, greater<long long>, rb_tree_tag, tree_order_statistics_node_update> oset1;
typedef tree<pair<ll, ll>, null_type, greater<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update> omultiset1;
/*  member functions :
                1. order_of_key(k) : number of elements strictly lesser than k
                2. find_by_order(k) : k-th element in the set (counting from zero)
 
    a.erase(unique(a.begin(),a.end()),a.end());     */

double pi = 3.141592653589793238462641;
int dx[4] = {1, 0, 0, -1}, dy[4] = {0, -1, 1, 0}; //DLRU..lexographic
const int mod = 1e9 + 7, mod2 = 998244353, inf = 1e18;

long long binpow(int a, int b, int m = mod)
{
    a %= m;
    int res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % m;
        a = (a * a) % m;
        b /= 2;
    }
    return res;
}

int modinv(int n, int m) { return binpow(n, m - 2, m); }

/*......................................................................................................................*/

const int N = 2e5 + 5;
int segsum[4 * N], segmin[4 * N], segmax[4 * N];

ll querymin(ll node, ll l, ll r, ll L, ll R)
{
    if (l > r)
        return inf;
    if (l > R || r < L)
        return inf;
    if (l == L && r == R)
    {
        return segmin[node];
    }
    ll m = (l + r) / 2;
    return min(querymin(node * 2, l, m, L, min(R, m)), querymin(node * 2 + 1, m + 1, r, max(L, m + 1), R));
}
void updatemin(ll node, ll l, ll r, ll pos, ll val)
{
    if (l == r)
    {
        segmin[node] = val;
    }
    else
    {
        ll m = (l + r) / 2;
        if (pos <= m)
        {
            updatemin(2 * node, l, m, pos, val);
        }
        else
        {
            updatemin(2 * node + 1, m + 1, r, pos, val);
        }
        segmin[node] = min(segmin[node * 2 + 1], segmin[node * 2]);
    }
}
//mx
ll querymax(ll node, ll l, ll r, ll L, ll R)
{
    if (l > r)
        return -inf;
    if (l > R || r < L)
        return -inf;
    if (l == L && r == R)
    {
        return segmax[node];
    }
    ll m = (l + r) / 2;
    return max(querymax(node * 2, l, m, L, min(R, m)), querymax(node * 2 + 1, m + 1, r, max(L, m + 1), R));
}
void updatemax(ll node, ll l, ll r, ll pos, ll val)
{
    if (l == r)
    {
        segmax[node] = val;
    }
    else
    {
        ll m = (l + r) / 2;
        if (pos <= m)
        {
            updatemax(2 * node, l, m, pos, val);
        }
        else
        {
            updatemax(2 * node + 1, m + 1, r, pos, val);
        }
        segmax[node] = min(segmax[node * 2 + 1], segmax[node * 2]);
    }
}

void solve()
{
    int n, q;
    cin >> n >> q;
    vi a(n + 1, 0), b(n + 1);
    for (int i = 0; i < n; i++)
        cin >> a[i + 1];
    for (int i = 0; i < n; i++)
        cin >> b[i + 1];
    for (int i = 0; i < n; i++)
    {
        a[i + 1] = a[i + 1] - b[i + 1];
    }
    for (int i = 1; i <= n; i++)
    {
        a[i] += a[i - 1];
    }
    for (int i = 1; i <= n; i++)
    {
        updatemax(1, 1, n, i, a[i]);
        updatemin(1, 1, n, i, a[i]);
    }
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        int sum = a[r] - a[l - 1];
        if (sum != 0)
        {
            cout << -1 << endl;
        }
        else
        {
            int s0 = a[l - 1];
            int mx = querymax(1, 1, n, l, r);
            int mi = querymin(1, 1, n, l, r);
            mx -= s0;
            mi -= s0;
            if (mx > 0)
            {
                cout << -1 << endl;
            }
            else
            {
                cout << -mi << endl;
            }
        }
    }
}

signed main()
{
    fast;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int test = 1;
    // cin >> test;
    while (test--)
    {
        solve();
    }
}