#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 50, maxm = 330;
const long long inf = 1e18;
int T, n, k, vis[maxn], p[maxn], sq[maxn], phi[maxn];
long long sp[maxn], s1[maxn][maxm], s2[maxn][maxm], f[maxn][20];
int read() {
  int x = 0;
  char c = getchar();
  while (c < '0' || c > '9') c = getchar();
  while (c >= '0' && c <= '9') x = x * 10 + (c ^ 48), c = getchar();
  return x;
}
inline long long calc(int l, int r) {
  int t = r / l;
  if (t <= sq[r])
    return s2[r][t - 1] + 1ll * (r / t - l + 1) * sp[t];
  else
    return s1[r][l];
}
void init(int n) {
  phi[1] = 1;
  for (int i = 2, tot = 0; i <= n; i++) {
    if (!vis[i]) p[++tot] = i, phi[i] = i - 1;
    for (int j = 1, t; j <= tot && (t = i * p[j]) <= n; j++) {
      vis[t] = 1;
      if (i % p[j] == 0) {
        phi[t] = phi[i] * p[j];
        break;
      } else
        phi[t] = phi[i] * phi[p[j]];
    }
  }
  for (int i = 1; i <= n; i++) sp[i] = sp[i - 1] + phi[i];
  for (int i = 1; i <= n; i++) {
    sq[i] = 0;
    while ((sq[i] + 1) * (sq[i] + 1) <= i) sq[i]++;
    int l = 1, r;
    while (l <= i) {
      r = i / (i / l);
      if (r <= sq[i])
        s1[i][r] = 1ll * (r - l + 1) * sp[i / l];
      else
        s2[i][i / r] = 1ll * (r - l + 1) * sp[i / l];
      l = r + 1;
    }
    for (int j = 1; j <= sq[i]; j++) s2[i][j] += s2[i][j - 1];
    s1[i][sq[i]] += s2[i][sq[i]];
    for (int j = sq[i] - 1; j >= 1; j--) s1[i][j] += s1[i][j + 1];
  }
  for (int i = 1; i <= n; i++) f[i][0] = inf;
  f[0][0] = 0;
  for (int j = 1; j <= 16; j++) {
    int p = 0;
    for (int i = 1; i <= n; i++) {
      while (p + 1 < i &&
             f[p + 1][j - 1] + calc(p + 2, i) <= f[p][j - 1] + calc(p + 1, i))
        p++;
      f[i][j] = f[p][j - 1] + calc(p + 1, i);
    }
  }
}
int main() {
  init(1e5);
  int cnt = 0;
  T = read();
  while (T--) {
    n = read(), k = read();
    cnt++;
    if (cnt == 200072) cout << n << ' ' << k << endl;
    if (k >= 17)
      printf("%d\n", n);
    else
      printf("%lld\n", f[n][k]);
  }
  return 0;
}
