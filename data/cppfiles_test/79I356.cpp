#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define mp  make_pair
#define pb  push_back
#define vi vector<int>
#define vpi vector<pair<int,int>>
#define endl "\n"
#define F first
#define S second
#define rep(i,a,n) for(int i=a;i<n;i++)
#define repr(i,n,a) for(int i=n;i>=a;i--)
const int mod = 1e9 + 7;
const int N = 2e5 + 5;
const int INF = 1e10;
vector<bool> isprime(N + 1, true);
int n, m, k;
void cpc() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
#endif
}
int pow(int a, int b) {
	int ans = 1;
	while (b > 0) {
		if (b & 1)
			ans = (ans * a) ;
		a = (a * a);
		b >>= 1;
	}
	return ans % mod;
}
int gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}
void sieve(int n) {
	isprime[0] = 0;
	isprime[1] = 0;
	for (int i = 2; i * i <= n; i++) {
		if (isprime[i]) {
			for (int j = i * i; j <= n; j += i) {
				isprime[j] = false;
			}
		}
	}
}
int bit[N] = {};
void upd(int l, int v) {
	//l++;
	while (l <= n) {
		bit[l] += v;
		l += (l & (-l));
	}
}
int btsum(int l) {
	//l++;
	int s = 0;
	while (l > 0) {
		s += (bit[l]);
		l -= (l & (-l));
	}
	return s;
}
int ncr(int n, int r) {
	int p = 1, k = 1;
	if (n - r < r)
		r = n - r;
	while (r) {
		p = p * n;
		k = k * r;
		int g = __gcd(p, k);
		p /= g;
		k /= g;
		n--;
		r--;
	}
	return p;
}
void solve() {
	int n, m;
	cin >> n;
	string s;
	cin >> s;
	int ans = 0, ans1 = 0;
	string s1 = "";
	map<char, int> freq;
	rep(i, 0, n) {
		freq[s[i]]++;
		if (s[i] == '4' or s[i] == '6' or s[i] == '8' or s[i] == '9' or s[i] == '1') {
			cout << 1 << endl << s[i] << endl;
			return;
		}
		if (i > 0 and (s[i] == '2' or s[i] == '5')) {
			ans = 2;
			s1 += s[0];
			s1 += s[i];
		}
		if (freq[s[i]] > 1) {
			ans = 2;
			s1 += s[i];
			s1 += s[i];
		}

	}
	if (ans == 2) {
		cout << ans << endl << s1 << endl;
		return;
	}
	if (s[0] == '2') {
		s1 = "27";
		cout << 2 << endl << s1 << endl;
		return;
	}
	if (s[0] == '5') {
		s1 = "57";
		cout << 2 << endl << s1 << endl;
		return;
	}



}
int32_t main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cpc();
	int t;
	t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}