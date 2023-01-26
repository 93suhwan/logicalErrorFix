
#include <bits//stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// MACROS
#define int                     long long
#define pb                      push_back
#define MAX                     2e18+5
#define MIN                     -2e18-5
#define mod                     1000000007
#define eps                     1e-9
#define set(x)                  memset(x, 0, sizeof(x))
#define clr(x)                  memset(x, -1, sizeof(x))
#define ff                      first
#define ss                      second
#define rep(i,a,b)              for(int i=a;i<b;i++)
#define sz(x)                   x.size()
#define endl                    "\n"
#define deb(x)                  cout << #x << "=" << x << endl
#define deb2(x, y)              cout << #x << "=" << x << "," << #y << "=" << y << endl
#define deb3(x, y, z)           cout << #x << "=" << x << "," << #y << "=" << y<< "," << #z << "=" << z << endl
#define deb4(x, y, z, a)        cout << #x << "=" << x << "," << #y << "=" << y<< "," << #z << "=" << z << "," << #a << "=" << a << endl
#define all(x)                  x.begin(), x.end()

typedef priority_queue<int>     maxHeap;
typedef priority_queue<int,     vector<int>, greater<int>> minHeap;
typedef pair<int, int>          pii;
typedef vector<int>             vi;
typedef vector<pii>             vpii;
typedef map<int, int>            mpii;
typedef set<int>                seti;
template<typename T> // find_by_order, order_of_key
using pbds = tree<T , null_type , less<T> , rb_tree_tag , tree_order_statistics_node_update>;
template<typename T, typename T1>T amax(T &a, T1 b) {if (b > a)a = b; return a;}
template<typename T, typename T1>T amin(T &a, T1 b) {if (b < a)a = b; return a;}
// typedef long long int           ll;

int mpow(int base, int exp);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int getRand(int l, int r)
{
    uniform_int_distribution<int> uid(l, r);
    return uid(rng);
}


// cout << fixed << setprecision(9) <<
const int N = 3e5 + 5;
int n;
pii a[N];

int BIT[N + 10];

int query(int idx) {
    int ans = 0;
    for (; idx > 0; idx -= idx & (-idx)) {
        ans += BIT[idx];
    }
    return ans;
}

void update(int idx, int val) {
    for (; idx <= n; idx += idx & (-idx)) // You can change to N if u want
        BIT[idx] += val;
}
bool cmp(pii a, pii b) {
    if (a.ss == b.ss) return a.ff < b.ff;
    return a.ss < b.ss;
}

void solve() {
    cin >> n;
    seti tmp;
    for (int i = 0; i <= n + 1; i++) BIT[i] = 0;
    rep(i, 0, n) {cin >> a[i].ff >> a[i].ss; tmp.insert(a[i].ss);}
    int ans = 0;
    sort(a, a + n, cmp);
    map<int, vi> mp;
    for (int i = 0; i < n; i++) {
        mp[a[i].ff].pb(a[i].ss);
    }
    for (auto &i : mp) {
        sort(all(i.ss));
    }
    rep(i, 0, n) update(a[i].ff, 1);
    for (int i = 0; i < n; i++) {
        int l = query(a[i].ff - 1);
        int r = query(n) - query(a[i].ff);
        // deb3(i, l, r);
        ans += l * r;

    }
    // deb(ans);
    int cur = 0;
    for (auto i : mp) {
        vi &v = i.ss;
        int sz = v.size();
        mpii cnt;
        seti s;
        for (int j = 0; j < sz; j++) {
            auto lb = lower_bound(all(v), v[j]) - v.begin();
            auto ub = upper_bound(all(v), v[j]) - v.begin();
            // deb4(i.ff, v[j], lb, ub);
            ans += lb * (sz - ub);
            s.insert(v[j]);
        }
        // deb(ans);
        for (int i : s) tmp.erase(i);
        ans += ((s.size() - 1) * s.size()) / 2 * tmp.size();
        for (int i : s) tmp.insert(i);
        // deb(ans);

    }
    cout << ans << endl;

}


/* TIPS
1. for interactive prob remove fastio and endl
2. for vector pass as reference
3. dont use set and clr when n * t is very large use loop till n instead.
4. don't forget to clear the graph
5.

*/



int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {

        // cout<<"Case #"<<i<<": ";

        solve();


    }
    return 0;
}

int mpow(int base, int exp) {
    base %= mod;
    int result = 1;
    while (exp > 0) {
        if (exp & 1) result = ((int)result * base) % mod;
        base = ((int)base * base) % mod;
        exp >>= 1;
    }
    return result;
}

