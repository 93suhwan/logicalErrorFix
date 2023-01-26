#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10, mod = 1e9 + 7;
int n, m, t, k;
long long dp[100][7], ddp[N], f[N];
char g[N];
priority_queue<int> q;
string str;
vector<pair<int, int> > vec[N];
void solve() {
  cin >> n;
  memset(dp, 0, sizeof dp);
  for (int i = 1; i <= 6; i++) dp[1][i] = 1;
  for (int i = 2; i <= n; i++)
    for (int j = 1; j <= 6; j++)
      for (int k = 1; k <= 6; k++)
        for (int p = 1; p <= 6; p++) {
          if (j == p || j + p == 7 || k == p || k + p == 7) continue;
          dp[i][p] += dp[i - 1][j] * dp[i - 1][k];
          dp[i][p] %= mod;
        }
  map<string, int> m1;
  m1["white"] = 1;
  m1["yellow"] = 6;
  m1["green"] = 2;
  m1["blue"] = 5;
  m1["red"] = 3;
  m1["orange"] = 4;
  struct node {
    long long v[7];
    node() { memset(v, 0, sizeof v); }
  };
  map<long long, node> ans;
  map<long long, int> col, vis;
  cin >> m;
  for (int i = 1; i <= m; i++) {
    long long x;
    string s;
    cin >> x >> s;
    col[x] = m1[s];
    q.push(x), vis[x] = 1;
  }
  while (q.size()) {
    long long t = q.top();
    q.pop();
    node n1, n2;
    if (t >= pow(2, k - 1)) {
      node tmp;
      tmp.v[col[t]] = 1;
      ans[t] = tmp;
      if (!vis[t / 2]) q.push(t / 2);
      continue;
    }
    if (!col[t * 2])
      for (int i = 1; i <= 6; i++) n1.v[i] = dp[k - (int)log2(t * 2)][i];
    else
      n1 = ans[t * 2];
    if (!col[t * 2] + 1)
      for (int i = 1; i <= 6; i++) n2.v[i] = dp[k - (int)log2(t * 2 + 1)][i];
    else
      n2 = ans[t * 2 + 1];
    node tmp;
    for (int j = 1; j <= 6; j++)
      for (int k = 1; k <= 6; k++)
        for (int p = 1; p <= 6; p++) {
          if (j == p || j + p == 7 || k == p || k + p == 7) continue;
          tmp.v[p] += n1.v[j] * n2.v[k];
          tmp.v[p] %= mod;
        }
    if (col[t]) {
      for (int i = 1; i <= 6; i++)
        if (i != col[t]) tmp.v[i] = 0;
    } else
      col[t] = 7;
    ans[t] = tmp;
    if (t >= 2 && !vis[t / 2]) q.push(t / 2), vis[t / 2] = 1;
  }
  long long sum = 0;
  for (int i = 1; i <= 6; i++) sum += ans[1].v[1];
  cout << sum % mod << '\n';
}
int main() {
  int T;
  T = 1;
  while (T--) solve();
  return 0;
}
