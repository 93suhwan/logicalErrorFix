#include <bits/stdc++.h>
using namespace std;
const int N_MAX = 500;
const int M_MAX = 500;
const int INF = INT_MAX / 2;
int n, m;
string a, b;
int kmp[M_MAX];
int prec[M_MAX + 2][2];
int dp[N_MAX][N_MAX + 2][M_MAX + 2];
void update(int &x, int y) { x = min(x, y); }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  cin >> a >> b;
  kmp[0] = 0;
  for (int i = 1; i < m; i++) {
    kmp[i] = kmp[i - 1];
    while (kmp[i] > 0 && b[kmp[i]] != b[i]) kmp[i] = kmp[kmp[i] - 1];
    if (b[kmp[i]] == b[i]) kmp[i]++;
  }
  for (int i = 0; i < n; i++)
    for (int cnt = 0; cnt <= n; cnt++)
      for (int pref = 0; pref <= m; pref++) dp[i][cnt][pref] = INF;
  dp[0][(m == 1)][1] = (a[0] != b[0]);
  dp[0][0][0] = 0;
  for (int pref = 0; pref <= m; pref++) {
    for (char c = '0'; c <= '1'; c++) {
      int newPref = (pref == m ? kmp[pref - 1] : pref);
      while (newPref > 0 && b[newPref] != c) newPref = kmp[newPref - 1];
      if (b[newPref] == c) newPref++;
      prec[pref][c - '0'] = newPref;
    }
  }
  for (int i = 0; i + 1 < n; i++)
    for (int cnt = 0; cnt <= n; cnt++)
      for (int pref = 0; pref <= m; pref++) {
        for (char c = '0'; c <= '1'; c++) {
          int newPref = prec[pref][c - '0'];
          update(dp[i + 1][cnt + (newPref == m)][newPref],
                 dp[i][cnt][pref] + (a[i + 1] != c));
        }
      }
  for (int cnt = 0; cnt <= n - m + 1; cnt++) {
    int mn = INF;
    for (int pref = 0; pref <= m; pref++) mn = min(mn, dp[n - 1][cnt][pref]);
    cout << (mn == INF ? -1 : mn) << " ";
  }
  cout << "\n";
  return 0;
}
