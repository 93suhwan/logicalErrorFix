#include <bits/stdc++.h>
#pragma GCC optimize "O3"
using namespace std;
const int INF = 1e9 + 7;
const int N = 1e6 + 7;
const int T = 1 << 20;
vector<vector<int> > G;
vector<int> przesun(vector<int> a) {
  vector<int> ret((int)a.size() + 1);
  for (int i = 0; i < (int)a.size(); i++) ret[i + 1] = a[i];
  return ret;
}
vector<int> operator+(vector<int> a, vector<int> b) {
  int n = max((int)a.size(), (int)b.size());
  a.resize(n);
  b.resize(n);
  vector<int> ret(n);
  for (int i = 0; i < n; i++) ret[i] = a[i] + b[i];
  return ret;
}
long long ans = 0;
int n, k;
int dp[101][101];
vector<int> dfs(int start, int prz = -1) {
  vector<vector<int> > kubki;
  for (auto& u : G[start])
    if (u != prz) kubki.push_back(przesun(dfs(u, start)));
  if (prz != -1) {
    vector<int> ret = {1};
    for (auto& u : kubki) ret = ret + u;
    return ret;
  } else {
    for (int odl = 1; odl < n; odl++) {
      for (int i = 0; i <= 100; i++)
        for (int j = 0; j <= 100; j++) dp[i][j] = 0;
      dp[0][0] = 1;
      for (int i = 0; i < (int)kubki.size(); i++) {
        for (int j = 0; j <= i; j++) dp[i + 1][j] = dp[i][j];
        for (int j = 0; j <= i; j++)
          dp[i + 1][j + 1] =
              (dp[i + 1][j + 1] +
               1ll * dp[i][j] *
                   ((int)kubki[i].size() > odl ? kubki[i][odl] : 0)) %
              INF;
      }
      ans = (ans + dp[(int)kubki.size()][k]) % INF;
    }
  }
  return {};
}
int dist[1004][1004];
void solve() {
  cin >> n >> k;
  ans = 0;
  G = vector<vector<int> >(n + 1);
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  if (k == 2)
    cout << n * (n - 1) / 2 << '\n';
  else {
    for (int i = 1; i <= n; i++) {
      vector<int> siema(n + 1);
      dfs(i);
    }
    cout << ans << '\n';
  }
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int test = 1;
  cin >> test;
  for (int i = 0; i < test; i++) solve();
}
