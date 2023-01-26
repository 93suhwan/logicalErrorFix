#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 1e6 + 5;
long long a[MAXN];
long long b[MAXN];
long long dw[MAXN];
vector<long long> conn[MAXN];
long long dist[MAXN];
long long pre[MAXN];
long long vv[MAXN];
signed main() {
  cin.tie(0)->sync_with_stdio(0);
  long long n;
  cin >> n;
  for (long long i = 1; i <= n; i++) cin >> a[i];
  for (long long i = 0; i <= n; i++) conn[i].clear();
  for (long long i = 1; i <= n; i++) {
    cin >> b[i], b[i] += i;
    conn[b[i]].push_back(i);
  }
  set<long long> rem;
  for (long long i = 0; i < n; i++) rem.insert(i);
  memset(dist, -1, sizeof dist);
  queue<long long> bfs;
  bfs.push(n);
  dist[n] = 0;
  while (!bfs.empty()) {
    long long u = bfs.front();
    bfs.pop();
    while (true) {
      auto it = rem.upper_bound(u);
      if (it == rem.begin()) break;
      long long jmp = *prev(it);
      if (u - jmp > a[u]) break;
      long long v = b[jmp];
      for (long long j : conn[v]) rem.erase(j);
      if (dist[v] == -1) {
        bfs.push(v);
        dist[v] = dist[u] + 1;
        pre[v] = u;
        vv[v] = jmp;
      }
      if (v == 0) goto after;
    }
  }
after:
  cout << dist[0] << '\n';
  if (dist[0] == -1) return 0;
  vector<long long> ans;
  long long cur = 0;
  while (cur != n) {
    ans.push_back(vv[cur]);
    cur = pre[cur];
  }
  reverse(ans.begin(), ans.end());
  for (long long i : ans) cout << i << ' ';
  cout << '\n';
}
