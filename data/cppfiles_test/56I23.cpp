#include <bits/stdc++.h>
using namespace std;
const int N = 5e2 + 10, mod = 998244353;
int n, m, t, k;
int s[N][N], dp[N][N], f[N], dp1[N];
char g[N];
priority_queue<int> q;
string str;
unordered_map<int, int> ma;
vector<int> vec[N], ve;
void solve() {
  int k;
  cin >> k;
  long long dp[k + 1][7];
  memset(dp, 0, sizeof(dp));
  dp[1][1] = dp[1][2] = dp[1][3] = dp[1][4] = dp[1][5] = dp[1][6] = 1;
  for (int i = 2; i <= k; i++)
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
    node() { memset(v, 0, sizeof(v)); }
  };
  map<long long, node> ans;
  map<long long, int> col, vis;
  int m;
  cin >> m;
  priority_queue<long long> pq;
  for (int i = 1; i <= m; i++) {
    long long first;
    string s;
    cin >> first >> s;
    col[first] = m1[s];
    pq.push(first), vis[first] = 1;
  }
  while (!pq.empty()) {
    long long t = pq.top();
    pq.pop();
    node n1, n2;
    if (t >= pow(2, k - 1)) {
      node tmp;
      tmp.v[col[t]] = 1;
      ans[t] = tmp;
      if (!vis[t / 2]) pq.push(t / 2);
      continue;
    }
    if (!col[t * 2])
      for (int i = 1; i <= 6; i++) n1.v[i] = dp[k - (int)log2(t * 2)][i];
    else
      n1 = ans[t * 2];
    if (!col[t * 2 + 1])
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
    if (t >= 2 && !vis[t / 2]) pq.push(t / 2), vis[t / 2] = 1;
  }
  cout << (ans[1].v[1] + ans[1].v[2] + ans[1].v[3] + ans[1].v[4] + ans[1].v[5] +
           ans[1].v[6]) %
              mod;
}
int main() {
  t = 1;
  while (t--) solve();
  return 0;
}
