#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
using pii = pair<int, int>;
using vec = vector<int>;
using veg = vector<pii>;
template <typename T>
T read() {
  T x = 0;
  bool f = 0;
  char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = x * 10 + (ch ^ 48), ch = getchar();
  return f ? -x : x;
}
template <typename T>
void chkmax(T &x, const T &y) {
  x = x > y ? x : y;
}
template <typename T>
void chkmin(T &x, const T &y) {
  x = x < y ? x : y;
}
const int N = 2010;
const int mod = 1e9 + 7;
int f[N][N << 1], g[N][N << 1], n;
char s[N], t[N];
void solve() {
  n = read<int>();
  scanf("%s", s + 1);
  scanf("%s", t + 1);
  for (int i = (1); i <= (n); i++) {
    if (s[i] != '?') s[i] ^= 1;
    i++;
  }
  for (int i = (1); i <= (n); i++) {
    if (t[i] != '?') t[i] ^= 1;
    i++;
  }
  f[1][0 + n] = 1;
  for (int i = (1); i <= (n); i++)
    for (int j = (-i); j <= (i); j++)
      if (f[i][j + n] || g[i][j + n])
        for (int k = (0); k <= (1); k++)
          if (s[i] == k + '0' || s[i] == '?')
            for (int d = (0); d <= (1); d++)
              if (t[i] == d + '0' || t[i] == '?')
                (f[i + 1][j + k - d + n] += f[i][j + n]) %= mod,
                    (g[i + 1][j + k - d + n] +=
                     g[i][j + n] + 1ll * f[i][j + n] * abs(j) % mod) %= mod;
  printf("%d\n", g[n + 1][0 + n]);
  for (int i = (0); i <= (n + 1); i++)
    for (int j = (-i); j <= (i); j++) f[i][j + n] = 0, g[i][j + n] = 0;
}
int main() {
  int T = read<int>();
  while (T--) solve();
  return 0;
}
