#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 3e5 + 5;
int tt, dp[maxn][2];
int n, q, a[maxn];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> tt;
  while (tt--) {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
      char c;
      cin >> c;
      if (c == '+')
        a[i] = 1;
      else
        a[i] = -1;
    }
    dp[n + 1][0] = dp[n + 1][1] = 0;
    map<int, vector<int>> m[2];
    for (int i = n; i >= 1; i--) {
      dp[i][0] = dp[i + 1][1] + a[i];
      dp[i][1] = dp[i + 1][0] - a[i];
    }
    int par = 1;
    for (int i = 1; i <= n; i++) {
      if (par) {
        m[0][dp[i][1]].push_back(i);
        m[1][dp[i][0]].push_back(i);
      } else {
        m[0][dp[i][0]].push_back(i);
        m[1][dp[i][1]].push_back(i);
      }
      par ^= 1;
    }
    while (q--) {
      int l, r;
      cin >> l >> r;
      int nw = 0;
      if ((r + 1) % 2 != (l % 2)) nw = 1;
      int now = dp[l][0] - dp[r + 1][nw];
      if (!now) {
        cout << "0\n";
        continue;
      }
      if (now % 2 == 0) {
        cout << "2\n";
        if (now < 0) {
          int fn = -1 + dp[r + 1][nw];
          int idx = upper_bound(m[l % 2][fn].begin(), m[l % 2][fn].end(), r) -
                    m[l % 2][fn].begin() - 1;
          cout << m[l % 2][fn][idx] << ' ';
          fn = (now / 2) - 1 + dp[r + 1][nw];
          idx = upper_bound(m[l % 2][fn].begin(), m[l % 2][fn].end(), r) -
                m[l % 2][fn].begin() - 1;
          cout << m[l % 2][fn][idx] << '\n';
        } else {
          int fn = 1 + dp[r + 1][nw];
          int idx = upper_bound(m[l % 2][fn].begin(), m[l % 2][fn].end(), r) -
                    m[l % 2][fn].begin() - 1;
          cout << m[l % 2][fn][idx] << ' ';
          fn = (now / 2) + 1 + dp[r + 1][nw];
          idx = upper_bound(m[l % 2][fn].begin(), m[l % 2][fn].end(), r) -
                m[l % 2][fn].begin() - 1;
          cout << m[l % 2][fn][idx] << '\n';
        }
      } else {
        cout << "1\n";
        if (now < 0)
          now = (now - 1) / 2;
        else
          now = (now + 1) / 2;
        now += dp[r + 1][nw];
        int idx = upper_bound(m[l % 2][now].begin(), m[l % 2][now].end(), r) -
                  m[l % 2][now].begin() - 1;
        cout << m[l % 2][now][idx] << '\n';
      }
    }
  }
}
