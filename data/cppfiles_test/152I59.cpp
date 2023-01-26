#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e6 + 7;
int p[MAX_N][2];
int dp[MAX_N][2][2];
pair<int, int> f[MAX_N][2][2];
bool g[MAX_N][2][2];
vector<int> ans;
int T, n;
void solve(int s, int k) {
  for (int i = n; i; --i) {
    ans.push_back(p[i][s]);
    pair<int, int> p = f[i][s][k];
    s = p.first, k = p.second;
  }
}
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &p[i][0]), p[i][1] = -p[i][0];
    for (int i = 1; i <= n; ++i) {
      for (int s = 0; s < 2; ++s) {
        for (int k = 0; k < 2; ++k) {
          dp[i][s][k] = -(1e9 + 7);
          g[i][s][k] = false;
        }
      }
    }
    g[1][0][0] = g[1][1][0] = true;
    for (int i = 2; i <= n; ++i) {
      for (int s1 = 0; s1 < 2; ++s1) {
        for (int s2 = 0; s2 < 2; ++s2) {
          if (p[i - 1][s1] < p[i][s2]) {
            if (g[i - 1][s1][1]) {
              if (p[i][s2] > dp[i - 1][s1][1] && dp[i][s2][0] < p[i - 1][s1]) {
                dp[i][s2][0] = p[i - 1][s1];
                f[i][s2][0] = pair<int, int>(s1, 1);
                g[i][s2][0] = true;
              }
              if (p[i][s2] < dp[i - 1][s1][1] && p[i][s2] > p[i - 1][s1] &&
                  dp[i][s2][1] <= dp[i - 1][s1][1]) {
                dp[i][s2][1] = dp[i - 1][s1][1];
                f[i][s2][1] = pair<int, int>(s1, 1);
                g[i][s2][1] = true;
              }
            }
            if (g[i - 1][s1][0]) {
              if (dp[i][s2][0] < dp[i - 1][s1][0] ||
                  dp[i - 1][s1][0] == -(1e9 + 7)) {
                dp[i][s2][0] = dp[i - 1][s1][0];
                g[i][s2][0] = true;
                f[i][s2][0] = pair<int, int>(s1, 0);
              }
            }
          } else {
            if (g[i - 1][s1][0]) {
              if (p[i][s2] > dp[i - 1][s1][0] && dp[i][s2][1] < p[i - 1][s1]) {
                dp[i][s2][1] = p[i - 1][s1];
                f[i][s2][1] = pair<int, int>(s1, 0);
                g[i][s2][1] = true;
              }
            }
          }
        }
      }
    }
    bool flag = true;
    for (int s = 0; s < 2; ++s) {
      for (int k = 0; k < 2; ++k) {
        if (g[n][s][k]) {
          solve(s, k);
          flag = false;
          break;
        }
      }
      if (!flag) break;
    }
    if (flag) {
      puts("NO");
    } else {
      puts("YES");
      for (int i = ans.size() - 1; i >= 0; --i) printf("%d ", ans[i]);
      puts("");
    }
    ans.clear();
  }
  return 0;
}
