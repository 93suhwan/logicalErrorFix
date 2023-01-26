#include <bits/stdc++.h>
using namespace std;
long long I() {
  char c = getchar();
  long long x = 0;
  long long f = 1;
  while (c < '0' or c > '9') f = (c == '-') ? -1 : 1, c = getchar();
  while (c >= '0' and c <= '9')
    x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
  return ((f == 1) ? x : -x);
}
long long n, a[100005];
long long f[2][100005];
vector<long long> n0[2];
inline void ad(long long& x, long long y) { x = (x + y) % 998244353; }
void flandre() {
  n = I();
  for (long long i = 1; i <= n; ++i) a[i] = I();
  long long ans = 0;
  long long pre = 0, cur = 1;
  n0[0].clear();
  n0[1].clear();
  for (long long i = n; i >= 1; --i) {
    f[cur][a[i]] = 1;
    n0[cur].push_back(a[i]);
    long long lasp = -1;
    for (auto x : n0[pre]) {
      long long p = a[i] / ((a[i] + x - 1) / x);
      ad(f[cur][p], f[pre][x]);
      if (p != lasp and p != a[i]) n0[cur].push_back(p), lasp = p;
      ad(ans, f[pre][x] * i % 998244353 * ((a[i] - 1) / x) % 998244353);
    }
    for (auto x : n0[pre]) f[pre][x] = 0;
    n0[pre].clear();
    swap(pre, cur);
  }
  printf("%lld\n", ans);
  for (auto x : n0[0]) f[0][x] = 0;
  for (auto x : n0[1]) f[1][x] = 0;
}
int main() {
  int t = I();
  while (t-- > 0) {
    flandre();
  }
}
