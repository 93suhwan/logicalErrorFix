#include <bits/stdc++.h>
using namespace std;
template <class T>
bool umin(T &a, const T &b) {
  return (a > b ? a = b, 1 : 0);
}
template <class T>
bool umax(T &a, const T &b) {
  return (a < b ? a = b, 1 : 0);
}
void INPUT(bool F = 0) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  if (F) {
    freopen(
        "name"
        ".in",
        "r", stdin);
    freopen(
        "name"
        ".out",
        "w", stdout);
  }
}
const int N = 503;
int dp[2][N][N];
int state[N][N];
vector<int> cmp(string a) {
  int n = (int)(a).size();
  vector<int> p(n);
  p[0] = 0;
  for (int i = 1; i < n; ++i) {
    int j = p[i - 1];
    while (a[j] != a[i] && j > 0) j = p[j - 1];
    if (a[j] == a[i]) j++;
    p[i] = j;
  }
  return p;
}
const int inf = 1e9;
void clr(int layer) {
  for (int x = 0; x < N; ++x) {
    for (int y = 0; y < N; ++y) dp[layer][x][y] = inf;
  }
}
signed main() {
  INPUT();
  int n, m;
  cin >> n >> m;
  string a, b;
  cin >> a >> b;
  swap(a, b);
  for (int i = 0; i <= (int)(a).size(); ++i) {
    for (int bt = 0; bt < 2; ++bt) {
      string nw = a.substr(0, i) + char('0' + bt);
      nw = a + "#" + nw;
      vector<int> p = cmp(nw);
      state[i][bt] = p.back();
    }
  }
  int bt = 0;
  clr(bt);
  dp[0][0][0] = 0;
  for (int i = 0; i < (int)(b).size(); ++i) {
    clr(bt ^ 1);
    for (int k = 0; k < (int)(b).size(); ++k) {
      for (int first = 0; first <= (int)(b).size(); ++first) {
        for (int t = 0; t < 2; ++t) {
          int togo = state[first][t];
          int dk;
          if (togo == (int)(a).size())
            dk = 1;
          else
            dk = 0;
          dp[bt ^ 1][k + dk][togo] = min(
              dp[bt ^ 1][k + dk][togo], dp[bt][k][first] + (t != (b[i] - '0')));
        }
      }
    }
    bt ^= 1;
  }
  for (int k = 0; k <= n - m + 1; ++k) {
    int ans = 1e9;
    for (int z = 0; z <= (int)(a).size(); ++z) ans = min(ans, dp[bt][k][z]);
    cout << (ans == inf ? -1 : ans) << ' ';
  }
  return 0;
}
