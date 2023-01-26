#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;
bool ispoweroftwo(long long n) { return n & (!(n & (n - 1))); }
long long mod = 1000000007;
long long dx[] = {1, 0, -1, 0};
long long dy[] = {0, -1, 0, 1};
bool test = 1;
const long long inf = 1e18;
const long long N = 2e5 + 5;
long long n;
vector<long long> adj[N];
long long vis[N];
void solve(long long tc = 0) {
  cin >> n;
  for (long long i = 1; i <= n; ++i) {
    adj[i].clear();
    vis[i] = 0;
  }
  vector<long long> store[n + 1];
  vector<long long> in_deg(n + 5, 0);
  for (long long i = 1, k; i <= n; ++i) {
    cin >> k;
    for (long long j = 1, x; j <= k; ++j) {
      cin >> x;
      store[i].push_back(x);
      adj[x].push_back(i);
      in_deg[i]++;
    }
  }
  queue<long long> q;
  for (long long i = 1; i <= n; ++i) {
    if (in_deg[i] == 0) q.push(i);
  }
  vector<long long> order;
  while (!q.empty()) {
    long long u = q.front();
    q.pop();
    order.push_back(u);
    for (auto it : adj[u]) {
      in_deg[it]--;
      if (in_deg[it] == 0) q.push(it);
    }
  }
  if ((long long)order.size() != n) {
    cout << "-1\n";
    return;
  }
  long long ans = 0;
  vector<long long> res(n + 1, 1);
  for (auto i : order) {
    for (auto it : store[i]) {
      if (it > i)
        res[i] = max(res[i], res[it] + 1);
      else
        res[i] = max(res[i], res[it]);
    }
    ans = max(ans, res[i]);
  }
  cout << ans << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  if (test) cin >> t;
  for (long long i = 1; i <= t; ++i) {
    solve(i);
  }
  return 0;
}
