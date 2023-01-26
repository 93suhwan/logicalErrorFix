#include <bits/stdc++.h>
using namespace std;
const int rr[6][3] = {{0, 1, 2}, {0, 2, 1}, {1, 0, 2},
                      {1, 2, 0}, {2, 0, 1}, {2, 1, 0}};
int n, m, c[200010][3];
char s[200010];
int ans, l, r;
const int MAX = 0x7fffffff;
int make(int x, int y) {
  if (y == 0)
    return x;
  else
    return x + y - 3;
}
int solve(int l, int r, int op) {
  int cnt = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++)
      if (rr[op][i] != j)
        cnt += c[max(0, make(r, i))][j] - c[max(0, make(l, i))][j];
  }
  return cnt;
}
int main() {
  scanf("%d%d", &n, &m);
  scanf("%s", s + 1);
  for (int i = 1; i <= 3; i++) c[i][s[i] - 'a']++;
  for (int i = 4; i <= n; i++) {
    for (int j = 0; j < 3; j++) c[i][j] = c[i - 3][j];
    c[i][s[i] - 'a']++;
  }
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &l, &r);
    if (l == r)
      printf("0\n");
    else if (l == r - 1)
      printf("%d\n", s[l] == s[r] ? 1 : 0);
    else {
      ans = MAX;
      for (int j = 0; j < 6; j++) ans = min(solve(l - 1, r, j), ans);
      printf("%d\n", ans);
    }
  }
}
