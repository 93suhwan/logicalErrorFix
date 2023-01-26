#include <bits/stdc++.h>
using namespace std;
template <class T>
void read(T &x) {
  x = 0;
  char c = getchar();
  while (c > '9' || c < '0') c = getchar();
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
}
bool bo[100001];
int p[100001], tot = 0, mu[100001], S[100001], a[100001], num[100001],
               sum[100001], q[100001];
int gcd(int x, int y) { return y == 0 ? x : gcd(y, x % y); }
int main() {
  int i, j, n, ans = 0, d, t, d1, s;
  mu[1] = 1;
  bo[1] = 1;
  for (i = 2; i < 100001; ++i) {
    if (!bo[i]) {
      p[++tot] = i;
      q[tot] = 100001 / i;
      mu[i] = -1;
      for (j = 2; j * i < 100001; ++j) {
        bo[j * i] = 1;
        if (j % i) mu[j * i] = -mu[j];
      }
    }
  }
  for (i = 1; i < 100001; ++i) {
    for (j = 1; j * i < 100001; ++j) {
      S[i * j] = (1LL * S[i * j] + j * mu[i] + 1000000007) % 1000000007;
    }
  }
  read(n);
  for (i = 1; i <= n; ++i) read(a[i]);
  int m = min(800, n);
  for (d = m + 1; d <= n; ++d) {
    for (i = 1; i * d <= n; ++i) {
      for (j = 1; j * d <= n; ++j)
        ans = (ans + 1LL * S[d] * gcd(a[i * d], a[j * d])) % 1000000007;
    }
  }
  for (d = 1; d <= m; ++d) {
    memset(num, 0, sizeof(num));
    for (i = 1; i * d <= n; ++i) ++num[a[i * d]];
    for (i = 1; i <= tot; ++i) {
      for (j = q[i]; j >= 1; --j) num[j] += num[p[i] * j];
    }
    t = 0;
    for (d1 = 1; d1 < 100001; ++d1) {
      t = (t + 1LL * S[d1] * num[d1] % 1000000007 * num[d1]) % 1000000007;
    }
    ans = (ans + 1LL * t * S[d]) % 1000000007;
  }
  printf("%d\n", ans);
  return 0;
}
