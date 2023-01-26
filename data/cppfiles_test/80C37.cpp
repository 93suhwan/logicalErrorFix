#include <bits/stdc++.h>
long long n, m;
const long long MAXN = 1000006;
long long bit[MAXN];
void add(long long x, long long v) {
  x += 1;
  while (x < MAXN) {
    bit[x] += v;
    x += x & (-x);
  }
}
long long sum(long long x) {
  x += 1;
  long long ret = 0;
  while (x > 0) {
    ret += bit[x];
    x -= x & (-x);
  }
  return ret;
}
struct seg {
  std::vector<long long> arr, lazy;
  void push(long long id, long long l, long long r) {
    if (lazy[id] == 0) return;
    arr[(id + 1)] += lazy[id];
    arr[(id + 2 * (((l + r) / 2) - l + 1))] += lazy[id];
    lazy[(id + 1)] += lazy[id];
    lazy[(id + 2 * (((l + r) / 2) - l + 1))] += lazy[id];
    lazy[id] = 0;
  }
  void update(long long x, long long y, long long val, long long id = 0,
              long long l = 0, long long r = n - 1) {
    if (y < l || r < x) return;
    if (x <= l && r <= y) {
      lazy[id] += val;
      arr[id] += val;
      return;
    }
    push(id, l, r);
    update(x, y, val, (id + 1), l, ((l + r) / 2));
    update(x, y, val, (id + 2 * (((l + r) / 2) - l + 1)), ((l + r) / 2) + 1, r);
    arr[id] = std::min(arr[(id + 1)], arr[(id + 2 * (((l + r) / 2) - l + 1))]);
  }
};
signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  long long t;
  std::cin >> t;
  while (t--) {
    std::cin >> n >> m;
    seg tree;
    tree.arr = tree.lazy = std::vector<long long>(2 * n - 1, 0);
    long long cur[n];
    for (long long i = 0; i < n; i++) {
      tree.update(i, n - 1, 1);
      cur[i] = 1;
    }
    long long nones = 0;
    std::pair<long long, long long> help[n];
    for (long long i = 0; i < n; i++) {
      std::cin >> help[i].first;
      help[i].second = i;
      bit[i + 1] = 0;
    }
    long long b[m];
    for (long long i = 0; i < m; i++) std::cin >> b[i];
    std::sort(help, help + n);
    std::sort(b, b + m);
    long long init = 0;
    for (long long i = 0; i < n; i++) {
      init += sum(n - 1 - help[i].second);
      add(n - 1 - help[i].second, 1);
    }
    long long op = 0, zp = 0;
    long long ans = 0;
    for (long long i = 0; i < m; i++) {
      while (op < n && help[op].first <= b[i]) {
        tree.update(help[op].second, n - 1, -1);
        op++;
      }
      while (zp < n && help[zp].first < b[i]) {
        tree.update(help[zp].second, n - 1, -1);
        nones++;
        zp++;
      }
      ans += nones;
      ans += std::min(tree.arr[0], 0ll);
    }
    std::cout << ans + init << std::endl;
  }
  return 0;
}
