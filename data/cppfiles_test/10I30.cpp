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
// modular exponentiation
ll binpow(ll val, ll deg)
{
	if (deg < 0)
		return 0;
	if (!deg)
		return 1 % M;
	if (deg & 1)
		return binpow(val, deg - 1) * val % M;
	ll res = binpow(val, deg >> 1);
	return (res * res) % M;
}
//binomial
ll modinv(ll n) {
	return binpow(n, M - 2);
}


int main() {
	// your code goes here
	IOS;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ll i, j, t, k, x, y, z,  N;

	int r, c;
	cin >> n >> m >> k >> r >> c;

	int ax, bx, ay, by;
	cin >> ax >> ay >> bx >> by;

	int cx, cy;

	if (ax <= bx) {
		cx = max(0, ax + r - bx);
	}
	else {
		cx = max(0, bx + r - ax);
	}

	if (ay <= by) {
		cy = max(0, ay + c - by);
	}
	else {
		cy = max(0, by + c - ay);
	}

	ll tot = n * m - r * c;
	if (cx * cy == 0) {
		cout << binpow(k, tot);
	}
	else {

		ll rem = n * m - (2 * r * c - cx * cy);

		ll ans = binpow(k, rem);

		if (cx * cy == r * c) {
			ans = ans * binpow(k, r * c) % M;
		}
		else {
			ans = ans * binpow(k, r * c - cx * cy) % M;
		}

		cout << ans;
	}


	return 0;




}




















