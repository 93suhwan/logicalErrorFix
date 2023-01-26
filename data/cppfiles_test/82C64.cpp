#include <bits/stdc++.h>
using namespace std;
const int maxn = 6e5 + 10;
const int mod = 1e9 + 7;
inline int read() {
  int x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 1) + (x << 3) + c - '0';
    c = getchar();
  }
  return x * f;
}
int n, m, k, a[maxn], b[maxn], mn[maxn];
int to[maxn][20];
long long s[maxn][20];
int main() {
  n = read();
  m = read();
  k = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  for (int i = n, l = 1, r = 0; i; --i) {
    while (l <= r && a[i] < a[b[r]]) --r;
    b[++r] = i;
    while (l <= r && b[l] > k + i) ++l;
    mn[i] = a[b[l]];
  }
  mn[n + k] = -1;
  for (int i = n - k + 1; i <= n + k; i++)
    for (int j = 0; j < 20; j++) to[i][j] = n + k;
  for (int i = n - k; i; --i) {
    to[i][0] = i + k;
    if (mn[to[i][0]] >= mn[i]) {
      int x = to[i][0];
      for (int j = 19; ~j; --j)
        if (mn[to[x][j]] >= mn[i]) x = to[x][j];
      to[i][0] = to[x][0];
    }
    s[i][0] = 1ll * mn[i] * ((to[i][0] - i) / k);
    for (int j = 1; j <= 19; j++) {
      to[i][j] = to[to[i][j - 1]][j - 1];
      s[i][j] = s[i][j - 1] + s[to[i][j - 1]][j - 1];
    }
  }
  while (m--) {
    int l = read(), r = read();
    r -= (r - l) % k;
    long long ans = a[l];
    for (int i = 19; ~i; --i)
      if (to[l][i] <= r) ans += s[l][i], l = to[l][i];
    printf("%lld\n", ans + 1ll * mn[l] * ((r - l) / k));
  }
  return 0;
}
