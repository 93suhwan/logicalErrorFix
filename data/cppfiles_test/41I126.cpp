#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 100;
int dp1[maxn][3], dp2[maxn][3], dp3[maxn][3];
int c[3][3];
char s[maxn];
int main() {
  int n, m;
  cin >> n >> m;
  cin >> s + 1;
  for (int i = 1; i <= n; i++) {
    if (s[i] == 'a') {
      if (i % 3 == 1) {
        c[1][0]++;
        dp1[i][0] = c[1][0];
        dp1[i][1] = c[1][1];
        dp1[i][2] = c[1][2];
        dp2[i][0] = c[2][0];
        dp2[i][1] = c[2][1];
        dp2[i][2] = c[2][2];
        dp3[i][0] = c[0][0];
        dp3[i][1] = c[0][1];
        dp3[i][2] = c[0][2];
      }
      if (i % 3 == 2) {
        c[2][0]++;
        dp1[i][0] = c[1][0];
        dp1[i][1] = c[1][1];
        dp1[i][2] = c[1][2];
        dp2[i][0] = c[2][0];
        dp2[i][1] = c[2][1];
        dp2[i][2] = c[2][2];
        dp3[i][0] = c[0][0];
        dp3[i][1] = c[0][1];
        dp3[i][2] = c[0][2];
      }
      if (i % 3 == 0) {
        c[0][0]++;
        dp1[i][0] = c[1][0];
        dp1[i][1] = c[1][1];
        dp1[i][2] = c[1][2];
        dp2[i][0] = c[2][0];
        dp2[i][1] = c[2][1];
        dp2[i][2] = c[2][2];
        dp3[i][0] = c[0][0];
        dp3[i][1] = c[0][1];
        dp3[i][2] = c[0][2];
      }
    }
    if (s[i] == 'b') {
      if (i % 3 == 1) {
        c[1][1]++;
        dp1[i][0] = c[1][0];
        dp1[i][1] = c[1][1];
        dp1[i][2] = c[1][2];
        dp2[i][0] = c[2][0];
        dp2[i][1] = c[2][1];
        dp2[i][2] = c[2][2];
        dp3[i][0] = c[0][0];
        dp3[i][1] = c[0][1];
        dp3[i][2] = c[0][2];
      }
      if (i % 3 == 2) {
        c[2][1]++;
        dp1[i][0] = c[1][0];
        dp1[i][1] = c[1][1];
        dp1[i][2] = c[1][2];
        dp2[i][0] = c[2][0];
        dp2[i][1] = c[2][1];
        dp2[i][2] = c[2][2];
        dp3[i][0] = c[0][0];
        dp3[i][1] = c[0][1];
        dp3[i][2] = c[0][2];
      }
      if (i % 3 == 0) {
        c[0][1]++;
        dp1[i][0] = c[1][0];
        dp1[i][1] = c[1][1];
        dp1[i][2] = c[1][2];
        dp2[i][0] = c[2][0];
        dp2[i][1] = c[2][1];
        dp2[i][2] = c[2][2];
        dp3[i][0] = c[0][0];
        dp3[i][1] = c[0][1];
        dp3[i][2] = c[0][2];
      }
    }
    if (s[i] == 'c') {
      if (i % 3 == 1) {
        c[1][2]++;
        dp1[i][0] = c[1][0];
        dp1[i][1] = c[1][1];
        dp1[i][2] = c[1][2];
        dp2[i][0] = c[2][0];
        dp2[i][1] = c[2][1];
        dp2[i][2] = c[2][2];
        dp3[i][0] = c[0][0];
        dp3[i][1] = c[0][1];
        dp3[i][2] = c[0][2];
      }
      if (i % 3 == 2) {
        c[2][2]++;
        dp1[i][0] = c[1][0];
        dp1[i][1] = c[1][1];
        dp1[i][2] = c[1][2];
        dp2[i][0] = c[2][0];
        dp2[i][1] = c[2][1];
        dp2[i][2] = c[2][2];
        dp3[i][0] = c[0][0];
        dp3[i][1] = c[0][1];
        dp3[i][2] = c[0][2];
      }
      if (i % 3 == 0) {
        c[0][2]++;
        dp1[i][0] = c[1][0];
        dp1[i][1] = c[1][1];
        dp1[i][2] = c[1][2];
        dp2[i][0] = c[2][0];
        dp2[i][1] = c[2][1];
        dp2[i][2] = c[2][2];
        dp3[i][0] = c[0][0];
        dp3[i][1] = c[0][1];
        dp3[i][2] = c[0][2];
      }
    }
  }
  for (int i = 1; i <= m; i++) {
    int l, r, ans = 0;
    cin >> l >> r;
    int x1 = dp1[r][0] - dp1[l - 1][0];
    int x2 = dp1[r][1] - dp1[l - 1][1];
    int x3 = dp1[r][2] - dp1[l - 1][2];
    int big1 = max(x1, max(x2, x3));
    int sum1 = x1 + x2 + x3;
    ans += sum1 - big1;
    int x4 = dp2[r][0] - dp2[l - 1][0];
    int x5 = dp2[r][1] - dp2[l - 1][1];
    int x6 = dp2[r][2] - dp2[l - 1][2];
    int big2 = max(x4, max(x5, x6));
    int sum2 = x4 + x5 + x6;
    ans += sum2 - big2;
    int x7 = dp3[r][0] - dp3[l - 1][0];
    int x8 = dp3[r][1] - dp3[l - 1][1];
    int x9 = dp3[r][2] - dp3[l - 1][2];
    int big3 = max(x7, max(x8, x9));
    int sum3 = x7 + x8 + x9;
    ans += sum3 - big3;
    cout << ans << endl;
  }
  return 0;
}
