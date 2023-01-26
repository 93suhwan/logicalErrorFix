#include <bits/stdc++.h>
using namespace std;
void dbg() { cerr << endl; }
auto read = [](long long& x) {
  long long f = 1;
  x = 0;
  char ch = getchar();
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') f = -1;
  while (isdigit(ch)) {
    x = (x << 3) + (x << 1) + (ch - '0'), ch = getchar();
  }
  x *= f;
};
template <typename T, typename... A>
void dbg(T f, A... l) {
  cerr << f << " ";
  debug(l...);
}
template <typename T, typename F>
void rep(T b, T e, F f) {
  while (b != e) f(*b), b++;
}
signed main() {
  long long T;
  scanf("%lld", &T);
  while (T--) {
    long long n, m;
    scanf("%lld%lld", &m, &n);
    vector<vector<long long>> A(m, vector<long long>(n));
    for (long long i = 0; i < m; ++i) {
      for (long long j = 0; j < n; ++j) {
        scanf("%lld", &A[i][j]);
      }
    }
    if (m <= n - 1) {
      long long ans = 1000000001;
      for (long long i = 0; i < n; ++i) {
        long long M = A[0][i];
        for (long long j = 1; j < m; ++j) {
          M = max(M, A[j][i]);
        }
        ans = min(M, ans);
      }
      printf("%lld\n", ans);
      continue;
    }
    auto check = [&](long long x) -> bool {
      vector<long long> B(m);
      for (long long i = 0; i < m; ++i)
        for (long long j = 0; j < n; ++j)
          if (A[i][j] >= x) B[i]++;
      long long cnt = 0;
      for (long long i = 0; i < m; ++i) {
        if (B[i] >= 2) cnt++;
      }
      return cnt >= 1;
    };
    long long l = 0, r = 1000000000, mid;
    while (l < r) {
      mid = (l + r + 1) >> 1;
      if (check(mid))
        l = mid;
      else
        r = mid - 1;
    }
    printf("%lld\n", l);
  }
  return 0;
}
