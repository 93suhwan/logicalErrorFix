#include <bits/stdc++.h>
long long mod = 1000000007;
using namespace std;
long long power(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = (res * a) % mod;
    b >>= 1;
    a = (a * a) % mod;
  }
  return res;
}
bool isprime(long long n) {
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) return 0;
  }
  return 1;
}
long long pref[200005][31];
void precalculate() {
  long long N = 2e5 + 5;
  for (long long i = 1; i < N; i++) {
    for (int j = 0; j <= 30; j++) {
      if (i & (1 << j)) pref[i][j] = 1;
      pref[i][j] += pref[i - 1][j];
    }
  }
}
void solve() {
  long long l, r;
  cin >> l >> r;
  long long total = r - l + 1;
  long long ans = 1e10;
  for (int j = 0; j <= 30; j++) {
    long long curr = (pref[r][j] - pref[l - 1][j]);
    ans = min(ans, total - curr);
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  precalculate();
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
