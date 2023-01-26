#include <bits\stdc++.h>

#define ll long long
#define ull unsigned ll
ll  MM = 1e9 + 7;
const ll MAX = 2e5 + 5;
using namespace std;

ll gcd(ll a, ll b) {
	if (a < b)swap(a, b);
	if (b == 0)return a;
	return gcd(b, a % b);
}
ll lcm(ll a, ll b) {
	return a * b / gcd(a, b);
}
ll numberofdiviser(ll a) {
	ll ans = 0;
	ll i;
	for (i = 1; i * i < a; i++) {
		if (a % i == 0)ans += 2;
	}
	if (i * i == a)ans++;
	return ans;
}
void fival(ll * a, ll b, ll n) {
	for (int i = 0; i < n; i++) {
		a[i] = b;
	}
}

ll pow(ll a, ll b, ll m) {
	if (b == 0)return 1;
	if (b == 1)return a;
	ll x = pow(a, b / 2, m);
	x = (x * x) % m;
	if (b % 2)x = (x * a);
	return x % m;
}
ll inverse_mod(ll a, ll m) {
	return pow(a, m - 2, m);
}

int solve() {
	ll n; cin >> n;
	ll x, last;
	for (int i = 2; i <= n+1; i++) {
		cout << "? ";
		for (int j = 0; j < n - 1; j++)cout << 1 << " ";
		cout << i << endl;
		cin >> x;
		if (!x) {
			last = n + 2 - i;
			break;
		}
	}
	vector<ll>v(n);
	v[n - 1] = last;
	for (int i = 1; i <= n; i++) {
		if (i == last)continue;
		cout << "? ";
		for (int j = 1; j < n; j++) {
			cout << last << " ";
		}
		cout << i << endl;
		cin >> x;
		v[x-1] = i;
	}
	cout << "! ";
	for (auto x : v)cout << x << " ";
	cout << endl;
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t = 1;//cin >> t;
	while (t--) {
		solve();
	}
}