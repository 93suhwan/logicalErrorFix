#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char c = getchar();
  while ((c < '0' || c > '9') && (c != '-')) c = getchar();
  if (c == '-') f = -1, c = getchar();
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
  return x * f;
}
const int N = 3010;
int n, a[N], f[N][N];
vector<int> v[N];
inline void solve() {
  n = read();
  for (int i = (1); i <= (n); i++) v[i].clear();
  for (int i = (1); i <= (n); i++) a[i] = read(), v[a[i]].push_back(i);
  for (int i = (1); i <= (n); i++)
    for (int j = (i); j <= (n); j++) f[i][j] = 0;
  for (int len = (2); len <= (n); len++) {
    for (int l = (1); l <= (n - len + 1); l++) {
      int r = l + len - 1;
      f[l][r] = max(f[l + 1][r], f[l][r - 1]);
      if (a[l] == a[r]) {
        f[l][r] = f[l + 1][r - 1] + 1;
        for (auto i : v[a[l]])
          if (i > l && i < r) f[l][r] = max(f[l][r], f[l][i] + f[i][r]);
      } else {
        for (auto i : v[a[l]])
          if (i > l && i < r) f[l][r] = max(f[l][r], f[l][i] + f[i + 1][r]);
        for (auto i : v[a[r]])
          if (i > l && i < r) f[l][r] = max(f[l][r], f[l][i - 1] + f[i][r]);
      }
    }
  }
  printf("%d\n", n - 1 - f[1][n]);
}
int main() {
  int T = read();
  while (T--) solve();
}
