#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
long long pw(long long a, long long n) {
  if (n == 0) return 1;
  long long q = pw(a, n / 2);
  if (n % 2 == 0) return q * q % MOD;
  return q * q % MOD * a % MOD;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  int t;
  cin >> t;
  for (int z = 1; z <= t; z++) {
    int n, m, x, y, a, b;
    long long p;
    cin >> n >> m >> x >> y >> a >> b >> p;
    p = p * pw(100, MOD - 2) % MOD;
    int cnt = 0;
    int dx = 1, dy = 1;
    int x0 = x, y0 = y;
    vector<int> pos;
    while (cnt < 2 * (n - 1) * (m - 1)) {
      if (x == a || y == b) {
        pos.push_back(cnt);
      }
      cnt++;
      if (x + dx > n || x + dx < 1) {
        dx = -dx;
      }
      if (y + dy > m || y + dy < 1) {
        dy = -dy;
      }
      x += dx;
      y += dy;
    }
    x = x0, y = y0;
    long long q = (MOD + 1 - p) % MOD;
    long long sum = 0, cur = 1, sumP = 0;
    for (auto i : pos) {
      sum += cur * p % MOD * i % MOD;
      sumP += cur * p % MOD;
      cur = cur * q % MOD;
      sum %= MOD;
      sumP %= MOD;
    }
    long long res = sum + (1 - sumP) * cnt % MOD;
    res = (res % MOD + MOD) % MOD;
    res = res * pw(sumP, MOD - 2) % MOD;
    cout << res << "\n";
  }
  return 0;
}
