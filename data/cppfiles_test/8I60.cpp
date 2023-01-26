#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double db;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define pll pair<ll,ll>
#define pb push_back
#define eb emplace_back
#define ub(v,val) upper_bound(v.begin(),v.end(),val)
#define np(str) next_permutation(str.begin(),str.end())
#define lb(v,val) lower_bound(v.begin(),v.end(),val)
#define sortv(vec) sort(vec.begin(),vec.end())
#define rev(p) reverse(p.begin(),p.end());
#define v vector
#define repc(i,s,e) for(ll i=s;i<e;i++)
#define fi first
#define se second
#define mset(a,val) memset(a,val,sizeof(a));
#define repr(i,n) for(i=n-1;i>=0;i--)
#define rep(i,n) for(i=0;i<n;i++)
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define at(s,pos) *(s.find_by_order(pos))
#define set_ind(s,val) s.order_of_key(val)
long long int M = 1e9 + 7 ;
long long int inf = 9 * 1e18;
const double PI = acos(-1);
//CLOCK
ll begtime = clock();
#define time() cout << "\n\nTime elapsed: " << (clock() - begtime)*1000/CLOCKS_PER_SEC << " ms\n\n";
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//CLOCK ENDED
ll n, m;
//SEGMENT TREE
v<ll> tv;    //tv is the segment tree ans a is the main array of elements
//initialize tl ans tr with 0 ans n-1
ll neutral = 0; //change
ll combine(ll a, ll b)
{	//change
	return a + b;
}
ll sum(ll v, ll tl, ll tr, ll l, ll r)
{
	if (l > r)
		return neutral;
	if (l == tl && r == tr)
	{
		return tv[v];
	}
	ll tm = (tl + tr) / 2;
	return combine(sum(v * 2, tl, tm, l, min(r, tm)), sum(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}
void update(ll v, ll tl, ll tr, ll pos, ll new_val)
{
	if (tl == tr)
	{
		tv[v] = new_val;
	}
	else
	{
		ll tm = (tl + tr) / 2;
		if (pos <= tm)
			update(v * 2, tl, tm, pos, new_val);
		else
			update(v * 2 + 1, tm + 1, tr, pos, new_val);
		tv[v] = combine(tv[v * 2], tv[v * 2 + 1]);
	}
}
vector<int> parent, depth, heavy, head, pos, a;
int cur_pos;

int dfs(int s, vector<vector<int>> & adj) {
	int size = 1;
	int max_c_size = 0;
	for (int c : adj[s]) {
		if (c != parent[s]) {
			parent[c] = s, depth[c] = depth[s] + 1;
			int c_size = dfs(c, adj);
			size += c_size;
			if (c_size > max_c_size)
				max_c_size = c_size, heavy[s] = c;
		}
	}
	return size;
}

void decompose(int s, int h, vector<vector<int>> & adj) {
	head[s] = h, pos[s] = cur_pos++;
	if (heavy[s] != -1)
		decompose(heavy[s], h, adj);
	for (int c : adj[s]) {
		if (c != parent[s] && c != heavy[s])
			decompose(c, c, adj);
	}
}
void init(vector<vector<int>> & adj) {
	int n = adj.size();
	parent = vector<int>(n);
	depth = vector<int>(n);
	heavy = vector<int>(n, -1);
	head = vector<int>(n);
	pos = vector<int>(n);
	cur_pos = 0;
	dfs(0, adj);
	decompose(0, 0, adj);
}
v<v<int>> adj;
ll query(ll x, ll y) {
	//a to b
	ll ans = 0;
	while (head[x] != head[y]) {
		if (depth[x] < depth[y]) swap(x, y);
		ans += sum(1, 0, cur_pos - 1, pos[head[x]], pos[x] - 1);
		x = head[x];
		ll val = max(abs(a[x] + a[parent[x]]), abs(a[x] - a[parent[x]]));
		ans += val;
		x = parent[x];
	}
	if (depth[x] > depth[y]) swap(x, y);
	ans += sum(1, 0, cur_pos - 1, pos[x], pos[y] - 1);
	return ans;
}
int main() {
	// your code goes here
	IOS;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ll i, j, t, k, x, y, z,  N;

	ll q;
	cin >> n >> q;
	a.resize(n);
	rep(i, n) cin >> a[i];

	adj.resize(n);
	rep(i, n - 1) {
		cin >> x >> y;
		x--;
		y--;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	init(adj);
	tv.assign(4 * cur_pos, 0);

	rep(i, n) {
		if (heavy[i] != -1) {
			ll val = max(abs(a[i] + a[heavy[i]]), abs(a[i] - a[heavy[i]]));
			update(1, 0, cur_pos - 1, pos[i], val);
		}
	}
	// cout << query(0, 0);

	rep(i, q) {
		cin >> x;
		if (x == 1) {
			int u, c;
			cin >> u >> c;
			u--;
			a[u] = c;
			if (heavy[u] != -1) {
				ll val = max(abs(a[u] + a[heavy[u]]), abs(a[u] - a[heavy[u]]));
				update(1, 0, cur_pos - 1, pos[u], val);
			}
			if (parent[u] != -1) {
				if (heavy[parent[u]] == u) {
					u = parent[u];
					ll val = max(abs(a[u] + a[heavy[u]]), abs(a[u] - a[heavy[u]]));
					update(1, 0, cur_pos - 1, pos[u], val);
				}
			}
		}
		else {
			int u, v;
			cin >> u >> v;
			u--; v--;
			cout << query(u, v) << '\n';

		}
	}




	return 0;




}



















