#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
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

const int maxn = 3e5 + 5;
//SEGMENT TREE
struct seg {
	seg(int n) {
		tv.assign(4 * n, 0);
	}
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
};
struct seg2 {
	seg2(int n) {
		tv.assign(4 * n, 0);
	}
	v<ll> tv;
	ll neutral = 0; //change
	ll combine(ll a, ll b)
	{	//change
		return a + b;
	}
	void push(ll v)
	{
		tv[2 * v] = combine(tv[2 * v], tv[v]);
		tv[2 * v + 1] = combine(tv[2 * v + 1], tv[v]);
		tv[v] = neutral;
	}

	void update(ll v, ll tl, ll tr, ll l, ll r, ll new_val)
	{
		if (l > r)
			return;
		if (l == tl && tr == r)
		{
			tv[v] = combine(tv[v], new_val);
		}
		else
		{
			push(v);
			ll tm = (tl + tr) / 2;
			update(v * 2, tl, tm, l, min(r, tm), new_val);
			update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, new_val);
		}
	}
	ll get(ll v, ll tl, ll tr, ll pos)
	{
		if (tl == tr)
		{
			return tv[v];
		}
		push(v);
		ll tm = (tl + tr) / 2;
		if (pos <= tm)
			return get(v * 2, tl, tm, pos);
		else
			return get(v * 2 + 1, tm + 1, tr, pos);
	}
};
int main() {
	// your code goes here
	IOS;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ll i, j, t, k, x, y, z,  N;

	cin >> n;
	ll a[n];
	rep(i, n) cin >> a[i];

	seg *sum = new seg(maxn);
	seg *cnt = new seg(maxn);
	seg2 *fut = new seg2(maxn);
	seg2 *futcnt = new seg2(maxn);

	ll ans[n + 1] = {0};

	rep(i, n) {

		ans[i + 1] += ans[i];
		//contribution because of x%a[i]

		for (int j = a[i]; j < maxn; j += a[i]) {

			ans[i + 1] += sum->sum(1, 0, maxn - 1, j - a[i], j - 1) - cnt->sum(1, 0, maxn - 1, j - a[i], j - 1) * (j - a[i]);

		}
		//contribution because of a[i]%x

		ans[i + 1] += futcnt->get(1, 0, maxn - 1, a[i]) * a[i] - fut->get(1, 0, maxn - 1, a[i]);

		cnt->update(1, 0, maxn - 1, a[i], 1);
		sum->update(1, 0, maxn - 1, a[i], a[i]);

		int sam = 0;
		for (int j = a[i]; j < maxn; j += a[i]) {

			futcnt->update(1, 0, maxn - 1, j - a[i], j - 1, 1);
			fut->update(1, 0, maxn - 1, j - a[i], j - 1, sam * a[i]);
			sam++;

		}
		cout << ans[i + 1] << ' ';


	}



	return 0;



}



















