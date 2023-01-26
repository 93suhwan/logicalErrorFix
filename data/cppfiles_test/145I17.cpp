
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
#define sz(x)                   (int)x.size()
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
int n, k;
struct node {
	int x, y, i, t;
} a[N];
struct DSU {
	int connected;
	vector<int> par, sz;
	void setup(int n)
	{
		par = sz = vector<int> (n + 1, 0);
		for (int i = 0; i <= n; i++)
			par[i] = i, sz[i] = 1;
		connected = n;
	}
	int find(int u)
	{
		while (u != par[u])
		{
			par[u] = par[par[u]];
			u = par[u];
		}
		return u;
	}
	int getsize(int u)
	{
		return sz[find(u)];
	}
	void merge(int u, int v)
	{
		int par1 = find(u), par2 = find(v);
		if (par1 == par2)
			return;
		connected--;
		if (sz[par1] > sz[par2])
			swap(par1, par2);

		sz[par2] += sz[par1];
		sz[par1] = 0;
		par[par1] = par[par2];
	}
};
DSU dsu;
bool cmp1(node a, node b) {
	if (a.y == b.y) return a.x < b.x;
	return a.y > b.y;
}
bool cmp2(node a, node b) {
	if (a.x == b.x) return a.y < b.y;
	return a.x < b.x;
}
bool cmp3(node a, node b) {
	return a.t > b.t;
}
bool check(int x) {
	int ans = -1;
	seti s;
	for (int i = 1; i <= n; i++) {
		if (s.count(dsu.find(a[i].i)) > 0 or a[i].t <= x) {
		}  else {
			ans++;
			s.insert(dsu.find(a[i].i));
		}
	}
	return ans <= x;
}
void solve() {
	cin >> n >> k;
	rep(i, 1, n + 1) {
		cin >> a[i].x >> a[i].y >> a[i].t; a[i].i = i;
	}
	dsu.setup(n);
	sort(a + 1, a + n + 1, cmp2);
	map<int, vector<node>> mp;
	for (int i = 1; i <= n; i++) {
		if (mp.find(a[i].y) != mp.end() and abs(a[i].x - mp[a[i].y].back().x) <= k) {
			dsu.merge(a[i].i, mp[a[i].y].back().i);
		}
		mp[a[i].y].pb(a[i]);
	}
	mp.clear();
	sort(a + 1, a + n + 1, cmp1);
	for (int i = 1; i <= n; i++) {
		if (mp.find(a[i].x) != mp.end() and abs(a[i].y - mp[a[i].x].back().y) <= k) {
			dsu.merge(a[i].i, mp[a[i].x].back().i);
		}
		mp[a[i].x].pb(a[i]);
	}
	sort(a + 1, a + n + 1, cmp3);
	int lo = 0, hi = n + 1, ans = -1;
	while (lo <= hi) {
		int md = (lo + hi) / 2;
		if (check(md)) {
			ans = md, hi = md - 1;
		} else {
			lo = md + 1;
		}
	}
	cout << ans << endl;
	// cout << check(2) << endl;
	// cout << check(1) << endl;
	// cout << check(0) << endl;
}


/* TIPS
------------------------------------------------------------------------------------
5. Builtin_popcountll FOR LONG LONG ////////////////////////////////////////////////
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

