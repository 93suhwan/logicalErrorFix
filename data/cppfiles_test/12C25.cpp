#include <bits/stdc++.h>
using namespace std;
const int N = 2005;
const int INF = 1e9;
char s[N][N];
int n, m;
int dp[N][N];
int columnOpt[N][N];
int sqr(int x) { return x * x; }
void read() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i <= n; i++) {
    scanf("%s", s[i]);
  }
}
void prepare() {
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      columnOpt[i][j] = INF;
    }
  }
  for (int column = 0; column <= m; column++) {
    int nearest = 10005;
    for (int row = 0; row <= n; row++) {
      if (s[row][column] == '1') nearest = row;
      columnOpt[row][column] = min(columnOpt[row][column], sqr(nearest - row));
    }
    nearest = 10005;
    for (int row = n; row >= 0; row--) {
      if (s[row][column] == '1') nearest = row;
      columnOpt[row][column] = min(columnOpt[row][column], sqr(nearest - row));
    }
  }
}
void solve(int row, int optL, int optR, int l, int r) {
  if (l > r) return;
  int mid = (l + r) / 2;
  dp[row][mid] = INF;
  int opt = optL;
  for (int i = optL; i <= optR; i++) {
    int val = columnOpt[row][i] + sqr(i - mid);
    if (val < dp[row][mid]) {
      dp[row][mid] = val;
      opt = i;
    }
  }
  solve(row, optL, opt, l, mid - 1);
  solve(row, opt, optR, mid + 1, r);
}
long long work() {
  long long ret = 0;
  for (int row = 0; row <= n; row++) {
    solve(row, 0, m, 0, m);
    for (int column = 0; column <= m; column++) {
      ret += dp[row][column];
    }
  }
  return ret;
}
int main() {
  read();
  prepare();
  printf("%lld\n", work());
  return 0;
}
