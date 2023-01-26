#include <bits/stdc++.h>
const int N = 1e5 + 10;
inline int read() {
  int x = 0, f = 0;
  char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  return f ? -x : x;
}
int phi[N], sum[N], vis[N], p[N];
inline void init(int n = 1e5) {
  phi[1] = 1;
  for (int i = 2, cnt = 0; i <= n; ++i) {
    if (!vis[i]) p[++cnt] = i, phi[i] = i - 1;
    for (int j = 1; j <= cnt && i * p[j] <= n; ++j) {
      vis[i * p[j]] = 1, phi[i * p[j]] = phi[i] * (p[j] - 1);
      if (i % p[j] == 0) {
        phi[i * p[j]] = p[j] * phi[i];
        break;
      }
    }
  }
  for (int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + phi[i];
}
inline int64_t calc(int l, int r) {
  if (l > r) return 1LL << 60;
  int64_t ans = 0;
  for (int i = l, j; i <= r; i = j + 1) {
    j = r / (r / i);
    ans += sum[r / i] * (j - i + 1);
  }
  return ans;
}
int64_t f[21][N];
inline void solve(int l, int r, int L, int R, int64_t *f, int64_t *g) {
  if (l > r) return;
  int mid = l + r >> 1, p = 0;
  int64_t w = calc(std::min(mid, R + 1), mid);
  f[mid] = 1LL << 60;
  for (int i = std::min(mid - 1, R); i >= L; --i) {
    if (g[i] + w < f[mid]) f[mid] = g[i] + w, p = i;
    if (i) w += sum[mid / i];
  }
  solve(l, mid - 1, L, p, f, g);
  solve(mid + 1, r, p, R, f, g);
}
int main() {
  int n = 1e5, k = 16;
  init();
  for (int i = 1; i <= n; ++i) f[1][i] = 1LL * i * (i + 1) / 2;
  for (int i = 2; i <= k; ++i) solve(1, n, 0, n, f[i], f[i - 1]);
  for (int T = read(); T; --T) {
    int n = read(), k = read();
    printf("%lld\n", k >= 18 || (1 << k) > n ? n : f[k][n]);
  }
  return 0;
}
