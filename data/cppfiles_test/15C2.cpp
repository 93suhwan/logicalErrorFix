#include <bits/stdc++.h>
using namespace std;
vector<int> g[101];
vector<long long> v[101];
bool check[101];
long long dp[101][101];
void go(int root, int parent, int k) {
  if (!check[k]) {
    v[k].push_back(1);
    check[k] = true;
  } else
    v[k].back()++;
  for (int i = 0; i < (int)g[root].size(); i++)
    if (g[root][i] != parent) go(g[root][i], root, k + 1);
}
long long f(int k, int m, int t) {
  if (k < 0) return m == 0 ? 1ll : 0ll;
  if (dp[k][m] != -1) return dp[k][m];
  long long temp = f(k - 1, m, t);
  if (m > 0) temp = (temp + f(k - 1, m - 1, t) * v[t][k]) % 1000000007;
  dp[k][m] = temp;
  return temp;
}
int main() {
  int t, n, k, a, b;
  long long ans, temp;
  scanf("%d", &t);
  for (; t > 0; t--) {
    scanf("%d %d", &n, &k);
    for (int i = 1; i < n; i++) {
      scanf("%d %d", &a, &b);
      g[a].push_back(b);
      g[b].push_back(a);
    }
    if (k == 2)
      printf("%d\n", n * (n - 1) >> 1);
    else {
      ans = 0;
      for (int i = 1; i <= n; i++) {
        if ((int)g[i].size() < k) continue;
        for (int j = 0; j < (int)g[i].size(); j++) {
          memset(check, false, sizeof(check));
          go(g[i][j], i, 1);
        }
        for (int j = 1; j <= n; j++) {
          memset(dp, -1, sizeof(dp));
          temp = f((int)v[j].size() - 1, k, j);
          ans = (ans + temp) % 1000000007;
          v[j].clear();
        }
      }
      printf("%lld\n", ans);
    }
    for (int i = 1; i <= n; i++) g[i].clear();
  }
  return 0;
}
