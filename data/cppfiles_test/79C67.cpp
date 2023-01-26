#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const long long infinity = 1000000000000000000;
const int inf = 1e9 + 5;
void solve() {
  int n;
  cin >> n;
  vector<int> range(n + 1), drop(n + 1);
  for (int i = 1; i <= n; i++) cin >> range[i];
  ;
  for (int i = 1; i <= n; i++) cin >> drop[i];
  ;
  vector<int> dist(n + 5, inf);
  vector<int> par(n + 5, -1);
  set<pair<int, int> > q;
  vector<pair<int, int> > pr(n + 5, make_pair(-1, -1));
  dist[n] = 0;
  q.insert(make_pair(0, n));
  int max_seen = n;
  int ans = inf;
  while ((int)q.size() > 0) {
    auto [wt, v] = (*q.begin());
    q.erase(q.begin());
    int l = v, r = v - range[v];
    if (r <= 0) {
      par[0] = v;
      pr[0] = make_pair(par[0], par[v]);
      ans = min(ans, wt + 1);
      break;
    }
    l = min(l, max_seen - 1);
    max_seen = min(max_seen, r);
    for (int i = l + 1 - 1; i >= r; i--) {
      par[i] = v;
      int u = i + drop[i];
      if (wt + 1 < dist[u]) {
        dist[u] = wt + 1;
        par[u] = i;
        pr[u] = make_pair(par[u], v);
        q.insert(make_pair(dist[u], u));
      }
    }
  }
  if (ans == inf) ans = -1;
  cout << ans << "\n";
  if (ans != -1) {
    vector<int> av;
    av.push_back(0);
    pair<int, int> p = pr[0];
    av.push_back(p.first);
    int v = p.first;
    while (v != -1) {
      p = pr[v];
      av.push_back(p.first);
      av.push_back(p.second);
      v = p.second;
    }
    while (av.back() == -1) {
      av.pop_back();
    }
    reverse(av.begin(), av.end());
    for (int i = 1; i < (int)av.size(); i += 2) {
      cout << av[i] << " ";
    }
    cout << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int TC = 1;
  for (int tc = 1; tc <= TC; tc++) {
    solve();
  }
  return 0;
}
