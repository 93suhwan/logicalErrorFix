#include <bits/stdc++.h>
using namespace std;
int read() {
  char ch = getchar();
  int x = 0, pd = 0;
  while (ch < '0' || ch > '9') pd |= ch == '-', ch = getchar();
  while ('0' <= ch && ch <= '9') x = x * 10 + (ch ^ 48), ch = getchar();
  return pd ? -x : x;
}
int Add(int x, int y) { return x + y < 998244353 ? x + y : x + y - 998244353; }
int Mul(int x, int y) { return 1ll * x * y % 998244353; }
int Pow(int x, int y) {
  int res = 1;
  for (; y; y >>= 1, x = Mul(x, x))
    if (y & 1) res = Mul(res, x);
  return res;
}
const int maxn = 1000005;
int n, a[maxn];
bool vis[5005][8095];
int list[5005][8095], len[5005];
vector<int> ans;
int main() {
  for (int i = 1; i <= 5000; i++) vis[i][0] = 1, len[i] = 1;
  n = read();
  int mx = 0;
  for (int i = 1; i <= n; i++) mx = max(mx, a[i] = read());
  ++mx;
  for (int i = 1; i <= n; i++) {
    int x = a[i];
    for (int j = 1; j <= len[x]; j++) {
      int y = x ^ list[x][j];
      for (int k = x + 1; k <= mx; k++)
        if (!vis[k][y])
          vis[k][list[k][++len[k]] = y] = 1;
        else
          break;
    }
    len[x] = 0;
  }
  ans.push_back(0);
  for (int i = 1; i < 8092; i++)
    for (int j = 1; j <= mx; j++)
      if (vis[j][i]) {
        ans.push_back(i);
        break;
      }
  printf("%d\n", (int)ans.size());
  for (int x : ans) printf("%d ", x);
  return 0;
}
