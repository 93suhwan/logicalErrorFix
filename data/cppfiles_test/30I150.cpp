#include <bits\stdc++.h>

#define ll long long
#define ull unsigned ll
ll  MM = 1e18;
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

bool pal(string& s) {
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != s[s.size() - 1 - i])return 0;
	}
	return 1;
}

int solve() {
	int n; cin >> n;
	string s;
	cin >> s;
	if (pal(s))return cout << "0\n", 0;
	ll res = 1e15;
	for (char c = 'a'; c <= 'z'; c++) {
		ll sum = 0;
		for (int i = 0, j = n - 1; i < j;i++,j--) {
			if (s[i] == s[j]) {
				sum += 2; 
				continue;
			}
			while (i < j && s[i] == c)i++;
			while (i < j && s[j] == c)j--;
			if (s[i] != s[j]) {
				sum = 1e15;
				break;
			}
			if (i != j)
				sum += 2;
			else
				sum++;
		}
		if(sum<1e6)
			res = min(res, n-sum);
	}
	if (res > 1e10) {
		cout << -1 << '\n';
	}
	else {
		cout << res << '\n';
	}
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