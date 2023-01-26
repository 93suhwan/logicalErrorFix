#include <bits/stdc++.h>
using namespace std;
template <typename T1, typename T2>
inline void chkmin(T1 &a, T2 b) {
  if (a > b) a = b;
}
template <typename T1, typename T2>
inline void chkmax(T1 &a, T2 b) {
  if (a < b) a = b;
}
using ll = long long;
using ld = long double;
const string FILENAME = "input";
const int MAXN = 508;
int n, m;
string a;
string b;
int next228[MAXN][2];
short dp[MAXN][MAXN][MAXN];
void solve() {
  cin >> n >> m;
  cin >> a >> b;
  string c;
  for (int i = 0; i <= m; i++) {
    for (int t = 0; t < 2; t++) {
      c.push_back('0' + t);
      for (int j = 0; j <= (int)(c).size(); j++) {
        bool bad = false;
        for (int k = j; k < (int)(c).size(); k++) {
          if (k - j > (int)(b).size() || b[k - j] != c[k]) {
            bad = true;
            break;
          }
        }
        if (!bad) {
          next228[i][t] = (int)(c).size() - j;
          break;
        }
      }
      c.pop_back();
    }
    c += b[i];
  }
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      for (int f = 0; f <= i; f++) {
        dp[i][j][f] = 10000;
      }
    }
  }
  dp[0][0][0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= m; j++) {
      for (int f = 0; f <= i; f++) {
        for (int k = 0; k < 2; k++) {
          chkmin(dp[i + 1][next228[j][k]][f + (next228[j][k] == m)],
                 dp[i][j][f] + (k != a[i] - '0'));
        }
      }
    }
  }
  for (int f = 0; f <= n - m + 1; f++) {
    int res = 1e9;
    for (int t = 0; t <= m; t++) {
      chkmin(res, dp[n][t][f]);
    }
    if (res > 5000) {
      cout << -1;
    } else {
      cout << res;
    }
    cout << ' ';
  }
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
