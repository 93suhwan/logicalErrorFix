#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const int inf = 1e9 + 10;
const int N = 1e3 + 10;
int read() {
  int x = 0;
  char c = getchar();
  while (!isdigit(c)) c = getchar();
  while (isdigit(c)) x = (x << 1) + (x << 3) + c - '0', c = getchar();
  return x;
}
inline int add(int x, int y) {
  x += y;
  (x >= mod && (x -= mod));
  return x;
}
inline int sub(int x, int y) {
  x -= y;
  (x < 0 && (x += mod));
  return x;
}
inline int mul(int x, int y) { return 1ll * x * y % mod; }
int qpow(int x, int y, int p = mod) {
  int res = 1;
  while (y) {
    if (y & 1) res = mul(res, x);
    x = mul(x, x);
    y >>= 1;
  }
  return res;
}
int dis[N][N], col[N][N], minm[N];
int n, k, ans;
int main() {
  cin >> n >> k;
  ans = 1;
  minm[1] = 1;
  for (int i = 2; i <= n; i++) {
    int d = 0;
    for (int j = 1; j < i; j++) {
      if (dis[j][minm[j]] + 1 >= k) {
        d = 1;
        col[j][i] = ans + 1;
        dis[i][ans + 1] = 1;
      } else {
        col[j][i] = minm[j];
        dis[i][minm[j]] = max(dis[i][minm[j]], dis[j][minm[j]] + 1);
      }
    }
    if (d)
      for (int j = 1; j < i; j++) minm[j] = ans + d;
    ans += d;
    minm[i] = 1;
    for (int j = 2; j <= ans; j++)
      if (dis[i][j] < dis[i][minm[i]]) minm[i] = j;
  }
  printf("%d\n", ans);
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) printf("%d ", col[i][j]);
  }
  return 0;
}
