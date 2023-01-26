#include <bits/stdc++.h>
#pragma GCC optimize(2, 3, "Ofast")
#pragma GCC target("avx", "avx2")
using namespace std;
template <typename T1, typename T2>
void ckmin(T1 &a, T2 b) {
  if (a > b) a = b;
}
template <typename T1, typename T2>
void ckmax(T1 &a, T2 b) {
  if (a < b) a = b;
}
int read() {
  int x = 0, f = 0;
  char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
  return f ? -x : x;
}
template <typename T>
void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
template <typename T>
void print(T x, char let) {
  print(x), putchar(let);
}
const int N = 3005;
int dp[N][N];
vector<int> go[N];
int a[N], n;
void solve() {
  n = read();
  for (int i = 1; i <= n; i++) go[i].clear();
  for (int l = 1; l <= n; l++) {
    for (int r = 1; r <= n; r++) {
      dp[l][r] = l == r ? 0 : 1e9;
    }
  }
  for (int i = 1; i <= n; i++) {
    a[i] = read();
    if (i != 1 && a[i] == a[i - 1]) {
      i--, n--;
    }
  }
  for (int i = 1; i <= n; i++) {
    go[a[i]].push_back(i);
  }
  for (int len = 2; len <= n; len++) {
    for (int i = 1; i <= n - len + 1; i++) {
      int j = i + len - 1;
      ckmin(dp[i][j], dp[i + 1][j] + 1);
      for (auto k : go[a[i]]) {
        if (k > i && k <= j) ckmin(dp[i][j], dp[i + 1][k - 1] + 1 + dp[k][j]);
      }
    }
  }
  print(dp[1][n], '\n');
}
int main() {
  int T = read();
  while (T--) {
    solve();
  }
  return 0;
}
