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
int ar[300003], dp[300003];
int main() {
  int tc;
  for (scanf("%d", &tc); tc--;) {
    int n, m;
    std::vector<int> v;
    scanf("%d%d", &n, &m);
    for (int i = 0; i <= n; ++i) dp[i] = 0;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", ar + i);
      ++dp[(i + n - ar[i]) % n];
    }
    for (int i = 0; i < n; ++i) {
      if ((n - dp[i]) % 2 == 0 && (n - dp[i]) / 2 <= m) {
        v.push_back(i);
      }
    }
    printf("%lu ", v.size());
    for (auto& it : v) printf("%d ", it);
    puts("");
  }
  return 0;
}
