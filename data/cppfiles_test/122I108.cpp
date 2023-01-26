#include <bits/stdc++.h>
using namespace std;
using ld = long double;
using ll = long long;
ll mod = 1e9 + 7;
int const N = 3e5 + 100;
mt19937 rnd;
ll random(ll limit) {
  uniform_int_distribution<ll> uniform_dist(0, limit);
  return uniform_dist(rnd);
}
ll bpow(ll a, ll p) {
  ll res = 1;
  while (p > 0) {
    if (p % 2) {
      res = res * a % mod;
    }
    a = a * a % mod;
    p /= 2;
  }
  return res;
}
ll inv(ll a) { return bpow(a, mod - 2); }
int kek(int a, int b) {
  if (a - b >= 2) return 1e9;
  if (b - a >= 1) return 1e9;
  return a + b;
}
void solve() {
  int n;
  cin >> n;
  string s1, s2;
  cin >> s1 >> s2;
  ll ans = 1e9;
  bool f1 = 0, f0 = 0;
  for (int i = 0; i < n; i++) {
    f0 = f0 || s2[i] == '1';
    f1 = f1 || s1[i] == '1';
  }
  if (!f1) {
    if (f0) {
      cout << "-1\n";
      return;
    }
    cout << "0\n";
    return;
  }
  ll n0 = 0, n1 = 0;
  for (int i = 0; i < n; i++) {
    if (s1[i] != s2[i]) {
      if (s1[i] == '0')
        n0++;
      else
        n1++;
    }
  }
  ll ans1 = 1e9;
  if ((n0 + n1) % 2 == 0) {
    ans1 = kek(n1, n0);
  }
  n0 = 0, n1 = 0;
  for (int i = 0; i < n; i++) {
    if (s1[i] == s2[i]) {
      if (s1[i] == '0')
        n0++;
      else
        n1++;
    }
  }
  ll ans2 = 1e9;
  if ((n0 + n1) % 2 == 1) {
    ans2 = kek(n1, n0);
  }
  ans = min(ans1, ans2);
  if (ans >= 1e9) {
    cout << "-1\n";
  } else {
    cout << ans << '\n';
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  rnd = mt19937(956231);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
