#include <bits/stdc++.h>
using namespace std;
const int N = 2007, inf = 1e9, mod = 1e9 + 7;
char s[N], t[N];
int n, a[N], b[N], cur[N], o[N];
int f[N][N * 2][2];
int g[N][N * 2][2];
void Main() {
  cin >> n;
  cin >> (s + 1);
  cin >> (t + 1);
  for (int i = (0); i <= (n + 1); ++i)
    memset(f[i], 0, sizeof(f[i])), memset(g[i], 0, sizeof(g[i]));
  f[0][N][0] = 1;
  for (int i = (1); i <= (n); ++i) {
    for (int j = (2); j <= (N * 2 - 3); ++j)
      for (int o = (0); o <= (1); ++o)
        if (f[i - 1][j][o] || g[i - 1][j][o]) {
          for (int x = (0); x <= (1); ++x)
            if (s[i] == '?' || s[i] - '0' == x)
              for (int y = (0); y <= (1); ++y)
                if (t[i] == '?' || t[i] - '0' == y) {
                  int ho = x ^ y ^ o, w = j, Z = 0;
                  if (i & 1) {
                    if (x) w += 1;
                    if (y) w -= 1;
                  } else {
                    if (x) w -= 1;
                    if (y) w += 1;
                  }
                  Z = abs(j - N);
                  (f[i][w][ho] += f[i - 1][j][o]) %= mod;
                  (g[i][w][ho] += (long long)f[i - 1][j][o] * Z % mod) %= mod;
                  (g[i][w][ho] += g[i - 1][j][o]) %= mod;
                }
        }
  }
  cout << (g[n][N][0] + g[n][N][1]) % mod << '\n';
}
int main() {
  ios ::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) Main();
  return 0;
}
