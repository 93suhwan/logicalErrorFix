#include <bits/stdc++.h>
using namespace std;
template <typename T1, typename T2>
void CMax(T1 &x, T2 y) {
  if (y > x) x = y;
}
template <typename T1, typename T2>
void CMin(T1 &x, T2 y) {
  if (y < x) x = y;
}
template <typename T>
void read(T &x) {
  x = 0;
  int op = 1;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') op = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    x = (x << 1) + (x << 3) + (c ^ 48);
    c = getchar();
  }
  x *= op;
}
inline void swap(int &x, int &y) { x ^= y ^= x ^= y; }
inline int max(int x, int y) { return x > y ? x : y; }
inline int min(int x, int y) { return x < y ? x : y; }
const int MN = 4005;
int n, m, a[MN];
int stk[MN], top;
int ls[MN], rs[MN];
int sz[MN];
long long dp[MN][MN];
void DP(int x) {
  sz[x] = 1;
  if (ls[x]) {
    DP(ls[x]);
    int w = a[ls[x]] - a[x];
    for (int i = min(m, sz[x]); ~i; --i)
      for (int j = min(m, sz[ls[x]]); ~j; --j)
        dp[x][i + j] =
            max(dp[x][i + j], dp[x][i] + dp[ls[x]][j] + 1ll * w * (m - j) * j);
    sz[x] += sz[ls[x]];
  }
  if (rs[x]) {
    DP(rs[x]);
    int w = a[rs[x]] - a[x];
    for (int i = min(m, sz[x]); ~i; --i)
      for (int j = min(m, sz[rs[x]]); ~j; --j)
        dp[x][i + j] =
            max(dp[x][i + j], dp[x][i] + dp[rs[x]][j] + 1ll * w * (m - j) * j);
    sz[x] += sz[rs[x]];
  }
}
int main() {
  read(n);
  read(m);
  for (int i = (1); i <= (n); ++i) read(a[i]);
  for (int i = 1; i <= n; ++i) {
    while (top && a[stk[top]] > a[i]) top--;
    if (!top)
      ls[i] = stk[1];
    else
      ls[i] = rs[stk[top]], rs[stk[top]] = i;
    stk[++top] = i;
  }
  DP(stk[1]);
  printf("%lld", dp[stk[1]][m]);
  return 0;
}
