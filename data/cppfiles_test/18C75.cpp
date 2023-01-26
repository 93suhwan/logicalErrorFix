#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 2;
const long long mod = 1000000007;
long long a[N], n, d, vis[N], cost[N];
void dfs(long long u) {
  vis[u] = 1;
  a[u] = 0;
  long long v = (u + d + n) % n;
  if (vis[v]) return;
  if (a[v] == 0) return;
  cost[v] = cost[u] + 1;
  dfs(v);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  long long tt;
  cin >> tt;
  while (tt--) {
    cin >> n >> d;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
      if (a[i] == 1) continue;
      dfs(i);
    }
    long long sum = 0;
    for (int i = 0; i < n; i++) sum += a[i];
    if (sum)
      cout << -1 << "\n";
    else {
      long long ans = -(1LL << 61);
      for (int i = 0; i < n; i++) ans = max(ans, cost[i]);
      cout << ans << "\n";
    }
    for (int i = 0; i < n; i++) {
      vis[i] = cost[i] = 0;
    }
  }
}
