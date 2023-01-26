#include <bits/stdc++.h>
using namespace std;
inline long long readint() {
  long long x = 0;
  bool f = 0;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-') {
    f = 1;
    c = getchar();
  }
  while (isdigit(c)) {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return f ? -x : x;
}
const int maxn = 200 + 5;
int n;
long long m;
long long ksm(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b % 2 == 1) ans = ans * a % m;
    a = a * a % m;
    b /= 2;
  }
  return ans;
}
long long fac[maxn], ifac[maxn], f[40][maxn][maxn];
bool vis[40][maxn][maxn];
long long dfs(int x, int y, int z, int a) {
  if (x == -1) return y == n ? fac[n] : 0;
  if (vis[x][y][z]) return f[x][y][z];
  vis[x][y][z] = 1;
  f[x][y][z] = 0;
  for (int i = x == 0   ? 1
               : x == 1 ? 0
                        : max(n + 2 - a - x - y, 0);
       y + i <= n && z + x * i <= a; i++)
    f[x][y][z] =
        (f[x][y][z] + dfs(x - 1, y + i, z + x * i, a) * ifac[i] % m) % m;
  return f[x][y][z];
}
int main() {
  n = readint();
  m = readint();
  fac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % m;
  ifac[n] = ksm(fac[n], m - 2);
  for (int i = n - 1; i >= 0; i--) ifac[i] = ifac[i + 1] * (i + 1) % m;
  long long ans = 0;
  for (int i = max(1, n - 35); i <= n + 1; i++) {
    memset(vis, 0, sizeof(vis));
    ans = (ans + dfs(n + 1 - i, 0, 0, i)) % m;
  }
  printf("%lld\n", ans);
  return 0;
}
