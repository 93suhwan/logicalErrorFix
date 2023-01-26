#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using uint = unsigned int;
using ui64 = unsigned long long;
namespace IO {
template <typename T>
inline void read(T &x) {
  x = 0;
  bool f = 0;
  char a = getchar();
  for (; !isdigit(a); a = getchar())
    if (a == '-') f = 1;
  for (; isdigit(a); a = getchar()) x = x * 10 + a - '0';
  if (f) x = -x;
}
inline int read() {
  int x;
  read(x);
  return x;
}
inline i64 readll() {
  i64 x;
  read(x);
  return x;
}
}  // namespace IO
using IO ::read;
using IO ::readll;
using vi = vector<int>;
const int N = 4000 + 5;
int n, m;
int a[N], ls[N], rs[N], stk[N], top, fa[N];
i64 dp[N][N], f[N];
int sz[N];
void dfs(int x) {
  sz[x] = 1;
  dp[x][0] = 0;
  dp[x][1] = 1LL * (m - 1) * a[x];
  int y = ls[x];
  if (y) {
    dfs(y);
    memset(f, 0, sizeof(f));
    for (int i = (0); i <= (sz[y]); i++)
      for (int j = (0); j <= (sz[x]); j++) {
        f[i + j] = max(dp[y][i] + dp[x][j] - 2ll * a[x] * i * j, f[i + j]);
      }
    sz[x] += sz[y];
    for (int i = (0); i <= (sz[x]); i++) dp[x][i] = f[i];
  }
  y = rs[x];
  if (y) {
    dfs(y);
    memset(f, 0, sizeof(f));
    for (int i = (0); i <= (sz[y]); i++)
      for (int j = (0); j <= (sz[x]); j++) {
        f[i + j] = max(dp[y][i] + dp[x][j] - 2ll * a[x] * i * j, f[i + j]);
      }
    sz[x] += sz[y];
    for (int i = (0); i <= (sz[x]); i++) dp[x][i] = f[i];
  }
}
int main() {
  n = read();
  m = read();
  for (int i = (1); i <= (n); i++) a[i] = read();
  for (int i = (1); i <= (n); i++) {
    int pos = top;
    while (pos && a[stk[pos]] > a[i]) pos--;
    if (pos) rs[stk[pos]] = i;
    if (pos < top) ls[i] = stk[pos + 1];
    stk[top = ++pos] = i;
  }
  for (int i = (1); i <= (n); i++)
    if (ls[i]) fa[ls[i]] = i;
  for (int i = (1); i <= (n); i++)
    if (rs[i]) fa[rs[i]] = i;
  int rt = 0;
  for (int i = (1); i <= (n); i++)
    if (fa[i] == 0) rt = i;
  dfs(rt);
  cout << dp[rt][m] << endl;
  return 0;
}
