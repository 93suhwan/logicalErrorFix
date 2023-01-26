#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
using namespace std;
using namespace __gnu_pbds;
 
typedef long long int ll;
typedef tree<pair<ll,ll>, null_type, less<pair<ll,ll>>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
 
 
#define pii pair<int,int> 
#define vi vector<int>
#define vll vector<ll>
#define MOD 1000000007
 
 
template<typename T>
T ceil(T a, T b)
{
	return (a + b - 1) / b;
}
 
template<typename T>
T logb(T a, T b)
{
	return (double)log(a) / log(b);
}

 
template<typename T>
T gcd(T a, T b)
{
	if(b == 0)
		return a;
	return gcd(b, a % b);
}
  
ll isprime(ll x)
{
	for(ll i = 2;i <= sqrt(x);i++)
	{
		if(x % i == 0)
			return false;
	}
	return true;
}
 
 
bool rangeCheck(int x, int y, int h, int w)
{
	return (x >= 0 && x < h && y >= 0 && y < w);
}
 

ll modexp(ll n, ll x)
{
	if(x == 0)
		return 1;
	if(x == 1)
		return n;
	if(x % 2 == 0)
		return (modexp(n, x / 2) * modexp(n, x / 2)) % MOD;
	else
		return (modexp(n, x - 1) * modexp(n, 1)) % MOD;
}
 
 
 
 
void solve(int tc)
{
	double W, H;
	cin >> W >> H;
	double x1, x2, y1, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	double w, h;
	cin >> w >> h;
	double ans = (double)max(W, H);
	if(w <= min(x1, x2) || h <= min(y1, y2) || W - w >= max(x1, x2) || H - h >= max(y1, y2)) {
		cout << 0 << '\n';
		return;
	}
	if(abs(x1 - x2) + w <= W) {
		double tmp = min(max(0.0, w - min(x1, x2)), max(0.0, max(x1, x2)  - (W - w)));
		if(tmp == 0.0) tmp = max(W, H);
		ans = min(ans, tmp);
	}
	if(abs(y1 - y2) + h <= H) {
		double tmp = min(max(0.0, h - min(y1, y2)), max(0.0, max(y1, y2) - (H - h)));
		if(tmp == 0.0) tmp = max(W, H);
		ans = min(ans, tmp);
	}
	if(ans == max(W, H)) ans = (double)-1;
	cout << ans << '\n';
	return;
}
 
 
 
 
 
 
 
int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int tc;
	cin >> tc;
 
	// tc = 1;
	while(tc--) 
		solve(tc);
	return 0;
}