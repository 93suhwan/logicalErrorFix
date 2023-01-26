#include <bits/stdc++.h>
using namespace std;
const int mx = 8192;
int n, dp[10000], q[10000], p[10000], a[1000010], res;
vector<int> v[5010];
bool vis[10000];
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    v[a[i]].push_back(i);
  }
  dp[0] = 0;
  for (int i = 1; i <= mx; i++) dp[i] = n + 1, q[i] = i;
  for (int i = 1; i <= 5000; i++) {
    int tot = 0, now = -1;
    memset(vis, 0, sizeof(vis));
    for (int j = 0; j < v[i].size(); j++) {
      int x = v[i][j], lst = --tot;
      while (tot <= mx && dp[q[++tot]] < x)
        if (!vis[q[tot]]) p[++now] = q[tot];
      for (int j = lst; j < tot; j++) {
        if (dp[q[j] ^ i] > x) {
          p[++now] = q[j] ^ i;
          dp[p[now]] = x;
          vis[p[now]] = 1;
        }
      }
    }
    --tot;
    while (++tot <= mx)
      if (!vis[q[tot]]) p[++now] = q[tot];
    for (int i = 0; i <= mx; i++) q[i] = p[i];
  }
  for (int i = 0; i <= mx; i++)
    if (dp[i] <= n) res++;
  cout << res << endl;
  for (int i = 0; i <= mx; i++)
    if (dp[i] <= n) printf("%d ", i);
}
