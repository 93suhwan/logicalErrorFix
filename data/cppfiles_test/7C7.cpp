#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
const int N = 505;
const int INF = 0x3f3f3f3f;
void upd(int &a, int b) { a = min(a, b); }
int go[N][2];
int dp[N][N];
int ndp[N][N];
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  string a, b;
  cin >> n >> m >> a >> b;
  for (int i = 0; i <= m; ++i) {
    for (int x = 0; x < 2; ++x) {
      string s = b.substr(0, i) + string({(char)('0' + x)});
      int mx = 0;
      for (int j = 0; j <= i + 1; ++j) {
        if (s.substr(i + 1 - j, j) == b.substr(0, j)) {
          mx = max(mx, j);
        }
      }
      go[i][x] = mx;
    }
  }
  memset(dp, 0x3f, sizeof(dp));
  dp[0][0] = 0;
  for (int i = 0; i < n; ++i) {
    memset(ndp, 0x3f, sizeof(ndp));
    for (int cnt = 0; cnt <= max(0, i - m + 1); ++cnt) {
      for (int v = 0; v <= m; ++v) {
        for (int x = 0; x < 2; ++x) {
          int nv = go[v][x];
          int ncnt = cnt + (nv == m);
          upd(ndp[ncnt][nv], dp[cnt][v] + (x != a[i] - '0'));
        }
      }
    }
    memcpy(dp, ndp, sizeof(dp));
  }
  for (int i = 0; i <= n - m + 1; ++i) {
    int mn = INF;
    for (int v = 0; v <= m; ++v) mn = min(mn, dp[i][v]);
    cout << (mn == INF ? -1 : mn) << " ";
  }
  cout << "\n";
  return 0;
}
