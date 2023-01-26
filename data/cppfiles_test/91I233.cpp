#include <bits/stdc++.h>
using namespace std;
const int MX = 100005;
int n, m, q;
set<tuple<int, int, int> > ari, best;
set<pair<int, int> > in[MX];
map<pair<int, int>, int> ww;
multiset<long long> tri;
void clear() {
  ari.clear();
  for (int i = 1; i <= n; i++) in[i].clear();
  tri.clear();
  best.clear();
  ww.clear();
}
bool valid(int u, int v) {
  auto it = in[u].begin();
  for (int i = 0; i < int(3); i++) {
    if (it->second == v) return 1;
    it++;
    if (it == in[u].end()) break;
  }
  return 0;
}
void insert(int u, int v, int w) {
  if (u > v) swap(u, v);
  ww[{u, v}] = w;
  {
    ari.insert({w, u, v});
    {
      if (in[u].size()) {
        if (in[u].size()) {
          auto it = in[u].begin();
          for (int i = 0; i < int(3); i++) {
            if (1 || (valid(u, it->second) && valid(it->second, u)))
              best.insert({it->first, u, it->second});
            it++;
            if (it == in[u].end()) break;
          }
        }
        if (in[u].size() >= 3) {
          long long s = 0;
          auto it = in[u].begin();
          for (int i = 0; i < int(3); i++) {
            s += it->first;
            it++;
          }
          tri.insert(s);
        }
      }
    };
    {
      if (in[v].size()) {
        if (in[v].size()) {
          auto it = in[v].begin();
          for (int i = 0; i < int(3); i++) {
            if (1 || (valid(v, it->second) && valid(it->second, v)))
              best.insert({it->first, v, it->second});
            it++;
            if (it == in[v].end()) break;
          }
        }
        if (in[v].size() >= 3) {
          long long s = 0;
          auto it = in[v].begin();
          for (int i = 0; i < int(3); i++) {
            s += it->first;
            it++;
          }
          tri.insert(s);
        }
      }
    };
    in[u].insert({w, v});
    in[v].insert({w, u});
    {
      if (in[u].size()) {
        if (in[u].size()) {
          auto it = in[u].begin();
          for (int i = 0; i < int(3); i++) {
            if (0 || (valid(u, it->second) && valid(it->second, u)))
              best.insert({it->first, u, it->second});
            it++;
            if (it == in[u].end()) break;
          }
        }
        if (in[u].size() >= 3) {
          long long s = 0;
          auto it = in[u].begin();
          for (int i = 0; i < int(3); i++) {
            s += it->first;
            it++;
          }
          tri.insert(s);
        }
      }
    };
    {
      if (in[v].size()) {
        if (in[v].size()) {
          auto it = in[v].begin();
          for (int i = 0; i < int(3); i++) {
            if (0 || (valid(v, it->second) && valid(it->second, v)))
              best.insert({it->first, v, it->second});
            it++;
            if (it == in[v].end()) break;
          }
        }
        if (in[v].size() >= 3) {
          long long s = 0;
          auto it = in[v].begin();
          for (int i = 0; i < int(3); i++) {
            s += it->first;
            it++;
          }
          tri.insert(s);
        }
      }
    };
  };
}
void erase(int u, int v) {
  if (u > v) swap(u, v);
  int w = ww[{u, v}];
  ww.erase({u, v});
  {
    ari.erase({w, u, v});
    {
      if (in[u].size()) {
        if (in[u].size()) {
          auto it = in[u].begin();
          for (int i = 0; i < int(3); i++) {
            if (1 || (valid(u, it->second) && valid(it->second, u)))
              best.erase({it->first, u, it->second});
            it++;
            if (it == in[u].end()) break;
          }
        }
        if (in[u].size() >= 3) {
          long long s = 0;
          auto it = in[u].begin();
          for (int i = 0; i < int(3); i++) {
            s += it->first;
            it++;
          }
          tri.erase(s);
        }
      }
    };
    {
      if (in[v].size()) {
        if (in[v].size()) {
          auto it = in[v].begin();
          for (int i = 0; i < int(3); i++) {
            if (1 || (valid(v, it->second) && valid(it->second, v)))
              best.erase({it->first, v, it->second});
            it++;
            if (it == in[v].end()) break;
          }
        }
        if (in[v].size() >= 3) {
          long long s = 0;
          auto it = in[v].begin();
          for (int i = 0; i < int(3); i++) {
            s += it->first;
            it++;
          }
          tri.erase(s);
        }
      }
    };
    in[u].erase({w, v});
    in[v].erase({w, u});
    {
      if (in[u].size()) {
        if (in[u].size()) {
          auto it = in[u].begin();
          for (int i = 0; i < int(3); i++) {
            if (0 || (valid(u, it->second) && valid(it->second, u)))
              best.erase({it->first, u, it->second});
            it++;
            if (it == in[u].end()) break;
          }
        }
        if (in[u].size() >= 3) {
          long long s = 0;
          auto it = in[u].begin();
          for (int i = 0; i < int(3); i++) {
            s += it->first;
            it++;
          }
          tri.erase(s);
        }
      }
    };
    {
      if (in[v].size()) {
        if (in[v].size()) {
          auto it = in[v].begin();
          for (int i = 0; i < int(3); i++) {
            if (0 || (valid(v, it->second) && valid(it->second, v)))
              best.erase({it->first, v, it->second});
            it++;
            if (it == in[v].end()) break;
          }
        }
        if (in[v].size() >= 3) {
          long long s = 0;
          auto it = in[v].begin();
          for (int i = 0; i < int(3); i++) {
            s += it->first;
            it++;
          }
          tri.erase(s);
        }
      }
    };
  };
}
bool valid(vector<int> v) {
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  return v.size() == 4;
}
void query() {
  long long res = 1e18;
  if (tri.size()) res = min(res, *tri.begin());
  const auto& [w, u, v] = *ari.begin();
  for (auto it = best.begin(); it != best.end();) {
    auto nex = it;
    nex++;
    const auto& [w2, u2, v2] = *it;
    if (!valid(u2, v2) || !valid(v2, u2)) {
      best.erase(it);
      it = nex;
      continue;
    }
    if (valid({u, v, v2, u2})) {
      res = min(res, 0ll + w + w2);
      break;
    }
    it = nex;
  }
  {
    auto it = in[u].begin();
    for (int i = 0; i < int(3); i++) {
      auto jt = in[v].begin();
      for (int j = 0; j < int(3); j++) {
        if (valid({u, v, it->second, jt->second}))
          res = min(res, 0ll + it->first + jt->first);
        jt++;
        if (jt == in[v].end()) break;
      }
      it++;
      if (it == in[u].end()) break;
    }
  }
  cout << res << '\n';
}
void main_() {
  cin >> n >> m;
  clear();
  while (m--) {
    int u, v, w;
    cin >> u >> v >> w;
    insert(u, v, w);
  }
  query();
  cin >> q;
  while (q--) {
    int t, u, v;
    cin >> t >> u >> v;
    if (t) {
      int w;
      cin >> w;
      insert(u, v, w);
    } else {
      erase(u, v);
    }
    query();
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) main_();
  return 0;
}
