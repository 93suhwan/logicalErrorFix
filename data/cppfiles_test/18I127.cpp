#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int MAX_N = 1e5 + 5;
const int MAX_L = 20; // ~ Log N
const long long inf = 1e9 + 1;
const long long INF = 1e18 + 1;
const long long mod = 1000000007;
const long long mod1 = 998244353;


#define nfs ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define newline "\n"
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(p) p.begin(), p.end()
#define ff first
#define ss second
#define lim 200005
#define PI 3.141592653589793238462
#define rep(i, x, y)   for (__typeof(x) i = x; i <= y; i ++)
#define repi(i, x, y)  for (__typeof(x) i = x; i >= y; i --)
#define fore(itr, x)   for (__typeof(x.begin()) itr = x.begin(); itr != x.end(); itr ++)
#define forei(itr, x)  for (__typeof(x.end()) itr = x.end() - 1; itr != x.begin() - 1; itr --)
#define sz(x) ((ll)x.size())
#define ln(x) ((ll)x.length())
#define len(s, e) ((e)-(s)+1)
#define mid(s, e) ((s)+((e)-(s))/2)

typedef long long int ll;
typedef unsigned long long ull;
typedef long double lld;

typedef pair<int, int> pii;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;


#define LSOne(S) (S & (-S))
#define isBitSet(S, i) ((S >> i) & 1)
#define a_count(p) __builtin_acountll(p)

// #define debug(x)       { cerr << #x << " = " << x << endl; }

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

int n, k;
set<pii> sets;

int next(int x)
{
    if (x < 2 * n)return x + 1;
    return 1;
}

int previous(int x)
{
    if (x > 1)return x - 1;
    return 2 * n;
}

pii returnPair(int a, int b)
{
    return {min(a, b), max(a, b)};
}

void divide(int l, int r, int x)
{
    sets.erase(sets.find({l, r}));
    if (l != x)
        sets.insert(returnPair(l, previous(x)));
    if (r != x)
        sets.insert(returnPair(next(x), r));
}
void solve()
{
    cin >> n >> k;
    if (k == 0)
    {
        int res = (n * (n - 1)) / 2;
        cout << res << newline;
        return;
    }
    int x, y;
    // cin>>x>>y;
    // if(x>y)swap(x,y);
    // set.insert({x,y-1});
    // set.insert({y,x-1});
    rep(i, 1, k)
    {
        cin >> x >> y;
    }
    cout << "0\n";
}

int main(void)
{
    nfs;
#ifdef LOCAL // if the problem requires input/output via terminal.
    // #ifdef ONLINE_JUDGE // if the problem requires input/output via file(s).
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif

    // setprecision(std::numeric_limits<double>::digits10 + 1);
    // setprecision(8);
    // double number = .007;
    // cout<<fixed<<number<<newline;

    int tc; cin >> tc;
    for (int testcase = 1; testcase <= tc; testcase++)
    {
        //cout << "Case #" << testcase  << ": ";
        solve();
    }
}