#include <bits/stdc++.h>
using namespace std ;

#define ll              long long
#define pb              push_back
#define all(v)          v.begin(),v.end()
#define sz(a)           (ll)a.size()
#define F               first
#define S               second
#define mp              make_pair
#define INF             2000000000000000000
#define popcount(x)     __builtin_popcountll(x)
#define pll             pair<ll,ll>
#define pii             pair<int,int>
#define ld              long double
#define put(a)          cout<<a<<" ";
#define putn(a)         cout<<a<<"\n";
#define rep(i,a,b)      for(int i=a; i<b; i++)
#define repr(i,a,b)     for(int i=a; i>b; i--)
#define get(a)          int a; cin>>a;
#define getl(a)         long long a; cin>>a;
#define uniq(x)         x.erase(unique(all()),x.end());
#define init(a,n)       vector<long long> a(n); for(int i=0; i<n; i++) { cin>>a[i]; }
#define tostr(n)        to_string(n);
#define minv(v)         *min_element(all(v))
#define maxv(v)         *max_element(all(v))

const int M = 1000000007;
const int MM = 998244353;

int _atharva_()
{
	bool fail1 = false, fail2 = false;
	getl(n); init(v, n);
	if (n == 2) {
		putn(maxv(v));
		return 0;
	}
	ll gcd1 = v[0], gcd2 = v[1];
	for (ll i = 2; i < n; i += 2) {
		gcd1 = __gcd (gcd1, v[i]);
	}
	for (ll i = 3; i < n; i += 2) {
		gcd2 = __gcd (gcd2, v[i]);
	}
	if (gcd1 == 1 && gcd2 == 1) {putn(0); return 0;}
	for (ll i = 1; i < n; i += 2) {
		if (v[i] % gcd1 == 0 ) {
			fail1 = true;
			break;
		}
	}
	for (ll i = 0; i < n; i += 2) {
		if (v[i] % gcd2 == 0 ) {
			fail2 = true;
			break;
		}
	}
	if (fail1 && fail2) {
		putn(0);
	}
	else if (!fail1) {putn(gcd1);}
	else {putn(gcd2);}
	return 0;
}

int main()
{

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int TESTS = 1;
	cin >> TESTS;

	while (TESTS--)
		_atharva_();

	cerr << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms" << '\n';

	return 0;
}

