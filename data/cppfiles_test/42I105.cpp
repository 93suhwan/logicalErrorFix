
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
int n, m;
struct node {
    int l, r, w;
    bool operator<(const node &o) {
        return w < o.w;
    }
} a[N];

int st[4 * 1000000], lazy[4 * 1000000];
void update(int node, int ss, int se, int qs, int qe, int val) {
    int l = 2 * node + 1, r = 2 * node + 2;

    if (ss > se) return;

    if (lazy[node] != 0) {
        int dx = lazy[node];
        //+++++++++++++++++++++++++
        st[node] += dx; // update it
        lazy[node] = 0;
        if (ss != se) {
            lazy[l] += dx;          // mark childs as lazy
            lazy[r] += dx;
        }
    }
    if (ss > qe || se < qs)  // Current segment is not within range [l, r]
        return ;

    if (ss >= qs && se <= qe) {
        // ++++++++++++++++++++++++
        st[node] += val;
        if (ss != se) {
            // Not leaf node
            lazy[l] += val;
            lazy[r] += val;
        }
        return;
    }

    int mid = (ss + se) / 2;
    update(l, ss, mid, qs, qe, val);
    update(r, mid + 1, se, qs, qe, val);
    st[node] = min(st[l], st[r]);
    // ++++++++++++++++++++++++++
}

int query(int node, int ss, int se, int qs, int qe) {
    int l = 2 * node + 1, r = 2 * node + 2;
    if (ss > se) return MAX;

    if (ss > qe || se < qs) // Out of range
        return MAX;

    if (lazy[node] != 0) {
        int dx = lazy[node];
        // ++++++++++++++++++++++++++++
        st[node] += dx;
        lazy[node] = 0;
        if (ss != se) {
            lazy[l] += dx;
            lazy[r] += dx;
        }
    }


    if (qs <= ss and se <= qe)
        return st[node];

    int mid = (ss + se) / 2;
    int left = query(l, ss, mid, qs, qe);
    int right = query(r, mid + 1, se, qs, qe);
    // ++++++++++++++++++++++++++
    return min(left, right);
}

void solve() {
    cin >> n >> m;
    rep(i, 0, n) {
        cin >> a[i].l >> a[i].r >> a[i].w;
    }
    sort(a, a + n);
    int i = 0, j = 0, ans = MAX;
    while (i < n) {
        if (j <= i) {
            update(0, 0, m - 1, a[j].l - 1, a[j].r - 1, 1);
            j++;
        }
        while (j < n and query(0, 0, m - 1, 0, m - 1) < 1) {
            update(0, 0, m - 1, a[j].l - 1, a[j].r - 1, 1);
            j++;
        }
        int t = query(0, 0, m - 1, 0, m - 1);
        // deb4(i, a[i].w, j - 1, t);
        if (t >= 1) {
            ans = min(ans, a[j - 1].w - a[i].w);
        }
        update(0, 0, m - 1, a[i].l - 1, a[i].r - 1, -1);
        i++;
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
    // cin >> t;
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

