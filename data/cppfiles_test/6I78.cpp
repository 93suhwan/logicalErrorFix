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

const int maxn = 1e5 + 1;
ll res;
vector<int> d[maxn];
int phi[maxn];
int cnt[maxn];//counts the number of a[i*x] which are divisible by y
int main() {
	// your code goes here
	IOS;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ll i, j, t, k, x, y, z,  N;

	cin >> n;
	int a[n + 1];
	rep(i, n) cin >> a[i + 1];

	for (int i = 1; i < maxn; i++) {
		for (int j = i; j < maxn; j += i) d[j].pb(i);
	}

	phi[0] = 0;
	phi[1] = 1;

	for (int i = 2; i < maxn; i++) phi[i] = i - 1;

	for (int i = 2; i < maxn; i++) {
		for (int j = 2 * i; j < maxn; j += i) phi[j] -= phi[i];
	}
	ll ans = 0;
	for (int x = 1; x <= n; x++) {
		res = 0;
		for (int j = x; j <= n; j += x) {
			for (auto u : d[a[j]]) {
				res -= phi[u] * cnt[u] * cnt[u];
				cnt[u]++;
				res += phi[u] * cnt[u] * cnt[u];
			}
		}
		ans += res * phi[x];
		for (int j = x; j <= n; j += x) {
			for (auto u : d[a[j]]) {
				cnt[u]--;
			}
		}
	}
	cout << ans;

	return 0;




}



















