#include <bits/stdc++.h>
using pii = std::pair<long long, long long>;
using namespace std;
const long long maxn = 3e5 + 5;
long long n, a[maxn], b[maxn], dist[maxn][2], from[maxn][2];
vector<long long> adj[maxn];
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  vector<pii> order;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
    order.push_back({i - a[i], i});
  }
  for (long long i = 1; i <= n; i++) {
    cin >> b[i];
    adj[i + b[i]].push_back(i);
  }
  sort(order.begin(), order.end());
  for (long long i = 0; i <= n; i++)
    for (long long j = 0; j < 2; j++) dist[i][j] = 2e9;
  a[0] = 0;
  long long curidx = 0;
  deque<pii> q;
  dist[0][1] = 0;
  q.push_back({0, 1});
  while (!q.empty()) {
    long long curpos, curtype;
    tie(curpos, curtype) = q.front();
    q.pop_front();
    if (curtype == 0) {
      for (auto v : adj[curpos])
        if (dist[curpos][0] < dist[v][1]) {
          dist[v][1] = dist[curpos][0];
          from[v][1] = curpos;
          q.push_front({v, 1});
        }
    } else {
      while (curidx < order.size() && order[curidx].first <= curpos) {
        if (dist[curpos][1] + 1 < dist[order[curidx].second][0]) {
          dist[order[curidx].second][0] = dist[curpos][1] + 1;
          from[order[curidx].second][0] = curpos;
          q.push_back({order[curidx].second, 0});
        }
        curidx++;
      }
    }
  }
  if (dist[n][0] > 1e9)
    cout << "-1\n";
  else {
    cout << dist[n][0] << "\n";
    long long at = n, type = 0;
    while (at != 0) {
      at = from[at][type];
      type ^= 1;
      if (type == 1) cout << at << " ";
    }
    cout << "\n";
  }
  return 0;
}
