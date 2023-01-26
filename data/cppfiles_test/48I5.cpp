#include<bits\stdc++.h>
#define ll long long
#define ull unsigned ll
ll  MM = 1e18 + 7;
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
	int n; cin >> n;
	ll x;
	vector <ll>v;
	map<ll, ll>mp;
	set<ll>s1, s2;
	for (int i = 0; i < n; i++) {
		cin >> x;
		v.emplace_back(x);
		mp[x]++;
	}
	vector<ll>v1 = v;
	sort(v1.begin(), v1.end());
	int cnt = 0;
	int f = 0, f1 = 0;
	for (int i = 0; i < n; i++) {
		if (v[i] != v1[i]) {
			cnt++;
		}
	}
	if (cnt > 9||cnt==1)return cout << "NO\n", 0;
	if (cnt % 3 == 0 || cnt%3 == 1)return cout << "YES\n", 0;
	cout << "NO\n";
	
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t = 1;cin >> t;
	while (t--) {
		solve();
	}
}