#include <bits/stdc++.h>
using namespace std;
const int INF = 0x7fffffff;
const int N = 1e5 + 5;
inline int read() {
  int x = 0, rev = 0, ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') rev = 1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + ch - '0';
    ch = getchar();
  }
  return rev ? -x : x;
}
int n, a[N];
bool dfs(int i, int step, int sum) {
  if (sum == a[i]) return 1;
  if (step == n + 1) return 0;
  int flg = 0;
  if (i == step) return dfs(i, step + 1, sum);
  flg |= dfs(i, step + 1, sum + a[step]) + dfs(i, step + 1, sum - a[step]) +
         dfs(i, step + 1, sum);
  return flg;
}
int main() {
  int T = read();
  while (T--) {
    int flg = 0;
    n = read();
    for (int i = 0; i < n; i++) {
      a[i] = read();
    }
    for (int i = 0; i < n; i++) {
      flg |= dfs(i, 1, 0);
    }
    puts(flg ? "YES" : "NO");
  }
}
