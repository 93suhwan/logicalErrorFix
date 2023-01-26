#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 3;
char s[N];
int sum[7][N];
int n, m;
void init() {
  string ss = "abc";
  int cnt = 1;
  while (cnt <= 6) {
    if (s[0] != ss[0]) sum[cnt][0] = 1;
    for (int j = 1; j < n; j++) {
      sum[cnt][j] = sum[cnt][j - 1];
      if (s[j] != ss[j % 3]) sum[cnt][j]++;
    }
    cnt++;
    next_permutation(ss.begin(), ss.end());
  }
}
int main() {
  scanf("%d%d", &n, &m);
  scanf("%s", s);
  init();
  while (m--) {
    int l, r;
    scanf("%d%d", &l, &r);
    int ans = 0x3f3f3f3f;
    for (int i = 1; i <= 6; i++) ans = min(ans, sum[i][r - 1] - sum[i][l - 2]);
    printf("%d\n", ans);
  }
  return 0;
}
