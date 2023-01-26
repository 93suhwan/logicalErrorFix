//g++ -std=c++17 -Wl,--stack,268435456 ezpz.cpp -o ezpz.exe
//ezpz.exe

#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC optimize("Ofast")//Comment optimisations for interactive problems (use endl)
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pld pair<ld,ld>
#define pb push_back
#define fi first
#define se second
#define UP(a,b,c) for(ll (a)=(b);(a)<(c);++(a))
#define UU(a,b,c) for(ll (a)=(b);(a)<=(c);++(a))
#define DN(a,b,c) for(ll (a)=(b);(a)>(c);--(a))
#define DU(a,b,c) for(ll (a)=(b);(a)>=(c);--(a))
#define ALL(a) a.begin(), a.end()
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
#define ordered_set tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update>
 
 
/*
int RNG()
{
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	int ret = (uniform_real_distribution<long double>(0,1)(rng));
	return ret;
}
*/
 
ll expo(ll a, ll b, ll mod)
{
	if(b == 0) return 1;
	if(b == 1) return a % mod;
	ll ret = expo(a, b / 2, mod);
	ret *= ret;
	if(ret >= mod) ret %= mod;
	if(b & 1)
	{
		ret *= a;
		if(ret >= mod) ret %= mod;
	}
	return ret;
}
 
ll inv(ll v, ll mod)
{
	return expo(v, mod - 2, mod);
}

ll n, a[200005];
ll DP[200005];
ll fen[200005];

void upd(int id, ll v)
{
	while(id <= n)
	{
		fen[id] = max(fen[id], v);
		id += (id & (-id));
	}
}

ll get(int id)
{
	ll ans = 0;
	while(id > 0)
	{
		ans = max(ans, fen[id]);
		id -= (id & (-id));
	}
	return ans;
}

void reset()
{
}

void input()
{
	cin >> n;
	UU(i, 1, n) {
		cin >> a[i];
	}
}

void solve()
{
	vector< pair<int, int> > v;
	for(int i = 1; i <= n; i++) {
		if(i - a[i] >= 0) {
			v.push_back(make_pair(a[i], i - a[i]));
		}
	}
	sort(v.begin(), v.end());
	int ret = 0;
	for(int i = 0; i < v.size(); i++) {
		int maks = get(v[i].second + 1) + 1;
		ret = max(ret, maks);
		upd(v[i].second + 1, maks);
	}
	cout << ret << endl;
}

void Ahoy()
{
	solve();
}
 
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

 
	int T = 1;
	// cin >> T;
	UU(t, 1, T)
	{
		input();
		// cout << "Case #" << t << ": ";
		Ahoy();
		reset();
	}
 
	return 0;
} 

