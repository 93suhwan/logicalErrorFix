#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#pragma GCC target("avx,avx2,fma")
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
long long rnpow(long long x, long long y) {
  if (y == 0) return 1;
  if (y & 1) return rnpow(x, y - 1) * x % 1000000007LL;
  long long res = rnpow(x, y >> 1LL) % 1000000007LL;
  return res * res % 1000000007LL;
}
int gcd(int i, int j) { return i ? gcd(j % i, i) : j; }
long long gcd(long long i, long long j) { return i ? gcd(j % i, i) : j; }
long long fac(long long x) { return x ? fac(x - 1) * x : 1; }
int main() {
  int tc;
  for (scanf("%d", &tc); tc--;) {
    int n, k, res = 0;
    int dp[202] = {
        0,
    };
    std::vector<std::pair<int, int> > v;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < k; ++i) {
      int p, q;
      scanf("%d%d", &p, &q);
      if (p > q) std::swap(p, q);
      v.emplace_back(p, q);
      ++dp[p];
      ++dp[q];
    }
    std::vector<int> w;
    for (int i = 1; i <= 2 * n; ++i) {
      if (!dp[i]) w.push_back(i);
    }
    int m = w.size();
    std::sort((w).begin(), (w).end());
    for (int i = 0; i < m / 2; ++i) {
      v.emplace_back(w[i], w[m / 2 + i]);
    }
    std::sort((v).begin(), (v).end());
    for (int i = 0; i < v.size(); ++i) {
      for (int j = i + 1; j < v.size(); ++j) {
        res += (v[i].first < v[j].first && v[i].second < v[j].second &&
                v[j].first < v[i].second) ||
               (v[j].first < v[i].first && v[j].second < v[i].second &&
                v[i].first < v[j].second);
      }
    }
    printf("%d\n", res);
  }
  return 0;
}
