#include <bits/stdc++.h>
const long long MAXN = 400005;
const long long MOD = 1000000007;
long long bit[MAXN];
long long N;
struct seg {
  std::vector<long long> arr;
  void update(long long x, long long v, long long id = 0, long long l = 0,
              long long r = N - 1) {
    if (l == r) {
      arr[id] = std::max(arr[id], v);
      return;
    }
    if (x <= ((l + r) / 2))
      update(x, v, (id + 1), l, ((l + r) / 2));
    else
      update(x, v, (id + 2 * (((l + r) / 2) - l + 1)), ((l + r) / 2) + 1, r);
    arr[id] = std::max(arr[(id + 1)], arr[(id + 2 * (((l + r) / 2) - l + 1))]);
  }
  long long max(long long x, long long y, long long id = 0, long long l = 0,
                long long r = N - 1) {
    if (y < l || r < x) return 0;
    if (x <= l && r <= y) return arr[id];
    return std::max(
        max(x, y, (id + 1), l, ((l + r) / 2)),
        max(x, y, (id + 2 * (((l + r) / 2) - l + 1)), ((l + r) / 2) + 1, r));
  }
};
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
  N = 2 * n;
  seg tree;
  tree.arr = std::vector<long long>(2 * N - 1, 0);
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
  for (long long i = 0; i < t; i++) {
    long long x;
    std::cin >> x;
    x--;
    tree.update(bn[x], pos[bn[x]]);
  }
  for (long long i = 2 * n - 1; i >= 0; i--) {
    if (pos[i] < i && tree.max(i, N - 1) >= pos[i]) choose[i] = 1;
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
