#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long N = 100000;
long long n, m, q;
set<pair<long long, long long>> adj[N + 1];
set<pair<long long, pair<long long, long long>>> all;
map<pair<long long, long long>, long long> weight;
multiset<long long> ms;
long long ans;
void upd(long long u) {
  long long t = 3;
  auto it = adj[u].begin();
  vector<long long> vec;
  while (t-- && it != adj[u].end()) {
    pair<long long, long long> p = *it;
    vec.push_back(p.first);
    all.erase({p.first, {min(p.second, u), max(p.second, u)}});
    it++;
  }
  if ((long long)vec.size() == 3) {
    ms.erase(ms.find(vec[0] + vec[1] + vec[2]));
  }
}
void upd2(long long u) {
  long long t = 3;
  auto it = adj[u].begin();
  vector<long long> vec;
  while (t-- && it != adj[u].end()) {
    pair<long long, long long> p = *it;
    vec.push_back(p.first);
    all.insert({p.first, {min(u, p.second), max(u, p.second)}});
    it++;
  }
  if ((long long)vec.size() == 3) ms.insert(vec[0] + vec[1] + vec[2]);
}
void try_edge(pair<long long, pair<long long, long long>> p) {
  long long u = p.second.first;
  long long v = p.second.second;
  if (all.find(p) == all.end()) return;
  all.erase(p);
  adj[u].erase({p.first, v});
  adj[v].erase({p.first, u});
  vector<pair<long long, pair<long long, long long>>> del;
  if ((long long)adj[u].size()) {
    long long t = 3;
    auto it = adj[u].begin();
    while (t-- && it != adj[u].end()) {
      pair<long long, long long> k = *it;
      del.push_back({k.first, {min(u, k.second), max(u, k.second)}});
      all.erase({k.first, {min(u, k.second), max(u, k.second)}});
      it++;
    }
  }
  if ((long long)adj[v].size()) {
    long long t = 3;
    auto it = adj[v].begin();
    while (t-- && it != adj[v].end()) {
      pair<long long, long long> k = *it;
      del.push_back({k.first, {min(v, k.second), max(v, k.second)}});
      all.erase({k.first, {min(v, k.second), max(v, k.second)}});
      it++;
    }
  }
  if ((long long)all.size())
    ans = min(ans, (long long)p.first + (*all.begin()).first);
  for (auto d : del) {
    all.insert(d);
  }
  all.insert(p);
  adj[u].insert({p.first, v});
  adj[v].insert({p.first, u});
}
signed main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m;
  for (long long i = 0; i < m; i++) {
    long long u, v, w;
    cin >> u >> v >> w;
    if (v < u) swap(u, v);
    adj[u].insert({w, v});
    adj[v].insert({w, u});
    weight[{u, v}] = w;
    all.insert({w, {u, v}});
  }
  for (long long i = 1; i <= n; i++) upd2(i);
  auto answer = [&] {
    pair<long long, pair<long long, long long>> mn = *all.begin();
    long long u = mn.second.first;
    long long v = mn.second.second;
    ans = 1e18;
    if ((long long)ms.size()) ans = *ms.begin();
    auto it = adj[u].begin();
    long long t = 3;
    vector<pair<long long, pair<long long, long long>>> todo;
    while (t-- && it != adj[u].end()) {
      pair<long long, long long> p = *it;
      todo.push_back({p.first, {min(u, p.second), max(u, p.second)}});
      it++;
    }
    it = adj[v].begin();
    t = 3;
    while (t-- && it != adj[v].end()) {
      pair<long long, long long> p = *it;
      todo.push_back({p.first, {min(v, p.second), max(v, p.second)}});
      it++;
    }
    for (auto p : todo) {
      try_edge(p);
    }
    cout << ans << "\n";
  };
  answer();
  cin >> q;
  while (q--) {
    long long op;
    cin >> op;
    if (op == 0) {
      long long u, v;
      cin >> u >> v;
      if (v < u) swap(u, v);
      upd(u);
      all.insert({weight[{u, v}], {u, v}});
      upd(v);
      adj[u].erase({weight[{u, v}], v});
      adj[v].erase({weight[{u, v}], u});
      upd2(u);
      upd2(v);
    } else {
      long long u, v, w;
      cin >> u >> v >> w;
      if (v < u) swap(u, v);
      upd(u);
      upd(v);
      weight[{u, v}] = w;
      adj[u].insert({w, v});
      adj[v].insert({w, u});
      upd2(u);
      upd2(v);
    }
    answer();
  }
}
