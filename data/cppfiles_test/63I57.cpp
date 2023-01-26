#include <bits/stdc++.h>
using namespace std;
int n, dp[1 << 20][2], S[1 << 20], cnt[20 + 1];
string s[20 + 1];
int length[20 + 1];
vector<int> minn[20 + 1];
vector<vector<int>> p[20 + 1];
int lowbit(int x) { return x & (-x); }
int F(int x, int d) {
  if (d < -length[x] || d > length[x]) return 0;
  int ps =
      lower_bound(minn[x].begin(), minn[x].end(), d + 1) - minn[x].begin() - 1;
  return lower_bound(p[x][length[x] + d].begin(), p[x][length[x] + d].end(),
                     ps + 1) -
         p[x][length[x] + d].begin();
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> s[i], length[i] = s[i].length(), minn[i].resize(length[i] + 1),
                 p[i].resize(2 * length[i] + 1);
    for (int j = 1; j <= length[i]; ++j) {
      if (s[i][j - 1] == '(')
        cnt[i]++;
      else
        cnt[i]--;
      minn[i][j] = min(minn[i][j - 1], cnt[i]),
      p[i][s[i].length() - cnt[i]].push_back(j);
    }
    for (int j = 0; j <= length[i]; ++j) minn[i][j] = -minn[i][j];
  }
  for (int i = 1; i < (1 << n); ++i) {
    S[i] = S[i - lowbit(i)] + cnt[(int)(log(lowbit(i)) / log(2)) + 1];
    for (int j = 1; j <= n; ++j)
      if (i & (1 << (j - 1))) {
        bool op = (S[i - (1 << (j - 1))] - minn[j][length[j]] < 0);
        dp[i][op] = max(
            dp[i][op], dp[i - (1 << (j - 1))][0] + F(j, S[i - (1 << (j - 1))]));
        dp[i][1] = max(dp[i][1], dp[i - (1 << (j - 1))][1]);
      }
  }
  cout << max(dp[(1 << n) - 1][0], dp[(1 << n) - 1][1]) << endl;
  return 0;
}
