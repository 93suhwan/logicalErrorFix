#include <bits/stdc++.h>
long long calc_with_return(int k, std::vector<int> a) {
  if (a.empty()) {
    return 0;
  }
  std::sort(a.begin(), a.end(), std::greater<int>());
  int n = (int)a.size();
  long long res = 2ll * a[0];
  for (int i = k; i < n; i += k) {
    res += 2ll * a[i];
  }
  return res;
}
long long calc_without_return(int k, std::vector<int> a) {
  if (a.empty()) {
    return 0;
  }
  std::sort(a.begin(), a.end(), std::greater<int>());
  int n = (int)a.size();
  long long res = a[0];
  for (int i = k; i < n; i += k) {
    res += 2ll * a[i];
  }
  return res;
}
long long solve(int k, std::vector<int> neg, std::vector<int> pos) {
  if (neg.empty()) {
    return calc_without_return(k, pos);
  }
  if (pos.empty()) {
    return calc_without_return(k, neg);
  }
  long long pos_first = calc_with_return(k, pos) + calc_without_return(k, neg);
  long long neg_first = calc_with_return(k, neg) + calc_without_return(k, pos);
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
