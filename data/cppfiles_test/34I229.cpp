#include <bits/stdc++.h>
using namespace std;
unsigned long long power(unsigned long long a, unsigned long long p,
                         unsigned long long mod = 1e9 + 7) {
  unsigned long long res = 1, run = p % mod;
  while (p > 0) {
    if (p & 1) {
      res = (res * run) % mod;
    }
    p = (p >> 1);
    run = (run * run) % mod;
  }
  return res;
}
unsigned long long inverse(unsigned long long a,
                           unsigned long long mod = 1e9 + 7) {
  return power(a, mod - 2, mod);
}
unsigned long long gcd(unsigned long long a, unsigned long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
void pre() {}
void solve() {
  long long n, k;
  cin >> n >> k;
  vector<long long> a(n);
  for (auto &x : a) cin >> x;
  auto mycom = [](const vector<long long> &a, const vector<long long> &b) {
    return (a[0] * a[1]) > (b[0] * b[1]);
  };
  set<vector<long long>, decltype(mycom)> s(mycom);
  for (long long i = 2; i <= n; i++) {
    s.insert({i, i - 1});
  }
  long long ans = INT_MIN;
  while (!s.empty()) {
    auto mx = *s.begin();
    long long i = mx[0], j = mx[1];
    if (i * j <= ans) break;
    ans = max(ans, i * j - k * (a[i - 1] | a[j - 1]));
    if (mx[1] != 1) s.insert({mx[0], mx[1] - 1});
    s.erase({i, j});
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  unsigned long long t = 1;
  cin >> t;
  pre();
  while (t--) {
    solve();
  }
}
