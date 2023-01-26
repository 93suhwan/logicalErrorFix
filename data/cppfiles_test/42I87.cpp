#include <bits/stdc++.h>
const long long MAXN = 400005;
const long long MOD = 1000000007;
long long bit[MAXN];
void add(long long x, long long v) {
  x += 1;
  while (x < MAXN) {
    bit[x] += v;
    bit[x] %= MOD;
    x += x & (-x);
  }
}
long long sum(long long x) {
  long long ret = 0;
  x += 1;
  while (x > 0) {
    ret += bit[x];
    ret %= MOD;
    x -= x & (-x);
  }
  return ret;
}
signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  long long n;
  std::cin >> n;
  long long pos[2 * n];
  long long bn[n];
  for (long long i = 0; i < n; i++) {
    long long a, b;
    std::cin >> a >> b;
    a--;
    b--;
    bn[i] = b;
    pos[a] = b;
    pos[b] = a;
  }
  long long t;
  std::cin >> t;
  std::vector<long long> choose(2 * n, 0);
  long long maxa = 0, maxb = 0;
  for (long long i = 0; i < t; i++) {
    long long x;
    std::cin >> x;
    x--;
    choose[bn[x]] = 1;
    maxa = std::max(maxa, pos[bn[x]]);
    maxb = std::max(maxb, bn[x]);
  }
  for (long long i = maxb; i >= 0; i--) {
    if (pos[i] < i && pos[i] < maxa) choose[i] = 1;
  }
  long long next = 0;
  long long ans = 0;
  for (long long i = 2 * n - 1; i >= 0; i--) {
    if (pos[i] < i) {
      long long tele = sum(pos[i]);
      tele += choose[i];
      tele %= MOD;
      ans = (ans + tele) % MOD;
      add(pos[i], tele);
      next = (next + tele) % MOD;
    } else {
      long long tele = (sum(i) - sum(i - 1) + MOD) % MOD;
      next = (next - tele + MOD) % MOD;
    }
  }
  std::cout << ans << std::endl;
  return 0;
}
