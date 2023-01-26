#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5, P = 1e9 + 7;
int k, n, t, id[150], f[6][N];
long long a[N];
char ch[15];
map<long long, int> col;
map<long long, int> vis;
int get(long long v) {
  int u = 0;
  while (v) v >>= 1, u++;
  return ((1ll << k - u + 1) - 1) % (P - 1);
}
int K(int x, int y) {
  int z = 1;
  for (; y; y >>= 1, x = 1ll * x * x % P)
    if (y & 1) z = 1ll * z * x % P;
  return z;
}
int main() {
  id['w'] = 0;
  id['y'] = 1;
  id['g'] = 2;
  id['b'] = 3;
  id['r'] = 4;
  id['o'] = 5;
  scanf("%d%d", &k, &n);
  for (int i = 1; i <= n; i++) {
    long long v;
    scanf("%lld %s", &v, ch);
    col[v] = id[ch[0]];
    while (v) a[++t] = v, v >>= 1;
  }
  sort(a + 1, a + t + 1);
  t = unique(a + 1, a + t + 1) - a - 1;
  for (int i = 1; i <= t; i++) vis[a[i]] = i;
  for (int i = t; i; i--) {
    if (col.count(a[i]))
      f[col[a[i]]][i] = 1;
    else
      for (int j = 0; j < 6; j++) f[j][i] = 1;
    for (long long v = a[i] * 2; v < a[i] * 2 + 2; v++) {
      if (!vis.count(v)) {
        for (int j = 0; j < 6; j++) f[j][i] = 1ll * f[j][i] * K(4, get(v)) % P;
      } else {
        int u = vis[v];
        f[0][i] = 1ll * f[0][i] *
                  ((f[2][u] + f[3][u]) % P + (f[4][u] + f[5][u]) % P) % P;
        f[1][i] = 1ll * f[1][i] *
                  ((f[2][u] + f[3][u]) % P + (f[4][u] + f[5][u]) % P) % P;
        f[2][i] = 1ll * f[2][i] *
                  ((f[0][u] + f[1][u]) % P + (f[4][u] + f[5][u]) % P) % P;
        f[3][i] = 1ll * f[3][i] *
                  ((f[0][u] + f[1][u]) % P + (f[4][u] + f[5][u]) % P) % P;
        f[4][i] = 1ll * f[4][i] *
                  ((f[0][u] + f[1][u]) % P + (f[2][u] + f[3][u]) % P) % P;
        f[5][i] = 1ll * f[5][i] *
                  ((f[0][u] + f[1][u]) % P + (f[2][u] + f[3][u]) % P) % P;
      }
    }
  }
  int ans = 0;
  for (int j = 0; j < 6; j++) (ans += f[j][1]) %= P;
  cout << ans << endl;
  return 0;
}
