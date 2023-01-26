#include <bits/stdc++.h>
using namespace std;
const long long N = 5e5 + 5, mod = 1e9 + 7;
const long long oo = 1e18 + 7;
long long n, m;
long long a[N], b[N];
vector<long long> Adj[N];
set<pair<long long, long long> > second;
long long mn_dist[N], lst[N];
void process() {
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
    second.insert({i - a[i], i});
  }
  for (long long i = 1; i <= n; i++) {
    cin >> b[i];
    Adj[i + b[i]].push_back(i);
  }
  for (long long i = 1; i <= n; i++) mn_dist[i] = oo;
  queue<long long> bfs;
  for (long long i = 1; i <= n; i++) {
    if (i == a[i]) {
      mn_dist[i] = 1;
      lst[i] = 0;
      second.erase({i - a[i], i});
      bfs.push(i);
    }
  }
  while (!bfs.empty()) {
    long long u = bfs.front();
    bfs.pop();
    for (auto v : Adj[u]) {
      vector<pair<long long, long long> > del;
      for (auto it : second) {
        if (it.first > v) break;
        del.push_back(it);
        bfs.push(it.second);
        mn_dist[it.second] = mn_dist[u] + 1;
        lst[it.second] = v;
      }
      for (auto it : del) second.erase(it);
    }
  }
  if (mn_dist[n] == oo) {
    cout << -1 << "\n";
    return;
  }
  cout << mn_dist[n] << "\n";
  long long itr = n;
  for (long long i = 0; i < mn_dist[n]; i++) {
    cout << lst[itr] << " ";
    itr = lst[itr] + b[lst[itr]];
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  process();
}
