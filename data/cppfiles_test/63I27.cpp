#include <bits/stdc++.h>
using namespace std;
int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - 48;
    ch = getchar();
  }
  return x * f;
}
const int maxn = 4e5 + 2;
const int N = 1e6 + 1e5;
int n, dp[N], sum[22][maxn], minpos[22][maxn];
vector<int> se[21][maxn * 2];
string s[22];
int main() {
  n = read();
  memset(dp, -1, sizeof(dp));
  dp[0] = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> s[i];
    for (int j = 0; j < s[i].length(); ++j) {
      if (s[i][j] == '(')
        sum[i][j + 1] = sum[i][j] + 1;
      else
        sum[i][j + 1] = sum[i][j] - 1;
      if (minpos[i][maxn + sum[i][j + 1]] == 0)
        minpos[i][maxn + sum[i][j + 1]] = j + 1;
      se[i][maxn + sum[i][j + 1]].push_back(j + 1);
    }
  }
  for (int i = 1; i < (1 << n); ++i) {
    for (int j = 0; j < n; ++j) {
      if ((i & (1 << j)) != 0) {
        int las = i ^ (1 << j);
        int tnum = 0;
        for (int k = 0; k < n; ++k) {
          if (las & (1 << k)) {
            tnum += sum[k + 1][s[k + 1].length()];
          }
        }
        if (tnum < 0 || dp[las] == -1) {
          dp[i] = max(dp[i], dp[las]);
          continue;
        }
        int sup = minpos[j + 1][maxn - tnum - 1];
        int temp = 0;
        if (sup == 0)
          temp = se[j + 1][maxn - tnum].size();
        else {
          int real = maxn - tnum;
          int l = 0, r = se[j + 1][real].size() - 1;
          if (r < l) continue;
          if (se[j + 1][real][r] < sup)
            temp = se[j + 1][real].size();
          else if (se[j + 1][real][l] >= sup)
            temp = 0;
          else {
            while (l + 1 < r) {
              int mid = (l + r) / 2;
              if (se[j + 1][real][mid] < sup)
                l = mid;
              else
                r = mid;
            }
            temp = l + 1;
          }
        }
        dp[i] = max(dp[i], dp[las] + temp);
      }
    }
  }
  cout << dp[(1 << n) - 1];
}
