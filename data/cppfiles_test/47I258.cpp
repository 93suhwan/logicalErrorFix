#include <bits/stdc++.h>
long long calc(int k, bool need_return, std::vector<int> a) {
  if (need_return) {
    std::sort(a.begin(), a.end(), std::greater<int>());
  } else {
    std::sort(a.begin(), a.end(), std::less<int>());
  }
  long long res = 0;
  int goods = k, i = 0, x = 0, n = (int)a.size();
  while (i < n) {
    res += std::abs(a[i] - x);
    x = a[i];
    --goods;
    if (goods == 0) {
      if (i == n - 1 && !need_return) {
        return res;
      }
      res += x;
      x = 0;
      goods = k;
    }
    int rest = n - i - 1;
    if (!need_return && rest == k) {
      res += x;
      x = 0;
      goods = k;
    }
    ++i;
  }
  if (need_return) {
    res += x;
  }
  return res;
}
long long solve(int k, std::vector<int> neg, std::vector<int> pos) {
  if (neg.empty()) {
    return calc(k, false, pos);
  }
  if (pos.empty()) {
    return calc(k, false, neg);
  }
  long long pos_first = calc(k, true, pos) + calc(k, false, neg);
  long long neg_first = calc(k, true, neg) + calc(k, false, pos);
  return std::min(pos_first, neg_first);
}
int main() {
  int tests;
  std::scanf("%d", &tests);
  for (int test = 1; test <= tests; ++test) {
    int n, k;
    std::scanf("%d %d", &n, &k);
    std::vector<int> pos, neg;
    for (int i = 0; i < n; ++i) {
      int v;
      std::scanf("%d", &v);
      if (v > 0) {
        pos.push_back(v);
      } else if (v < 0) {
        neg.push_back(-v);
      }
    }
    long long ans = solve(k, neg, pos);
    std::printf("%lld\n", ans);
  }
  return 0;
}
