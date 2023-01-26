#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &x) {
  x = 0;
  char c = getchar();
  bool f = false;
  for (; !isdigit(c); c = getchar()) f |= c == '-';
  for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
  if (f) x = -x;
}
template <typename T, typename... Arg>
inline void read(T &x, Arg &...args) {
  read(x);
  read(args...);
}
template <typename T>
inline void write(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) write(x / 10);
  putchar(x % 10 + '0');
}
const int N = 8200;
int n, a[1001000];
vector<int> p[N];
int dp[2][N];
signed main() {
  read(n);
  for (int i = 1; i <= n; i++) read(a[i]), p[a[i]].push_back(i);
  int now = 0, lst = 1;
  memset(dp, 0x3f, sizeof dp);
  dp[now][0] = 0;
  for (int i = 0; i < N; i++) {
    if (!p[i].size()) continue;
    swap(now, lst);
    memcpy(dp[now], dp[lst], sizeof dp[now]);
    for (int j = 0; j < N; j++) {
      if (p[i].back() < dp[lst][j]) continue;
      ((dp[now][j ^ i]) =
           min((dp[now][j ^ i]),
               (*lower_bound(p[i].begin(), p[i].end(), dp[lst][j]))));
    }
  }
  vector<int> ans;
  for (int i = 0; i < N; i++)
    if (dp[now][i] != 0x3f3f3f3f) ans.push_back(i);
  write(ans.size());
  putchar('\n');
  for (auto x : ans) write(x), putchar(' ');
}
