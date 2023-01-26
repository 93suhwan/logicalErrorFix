#include <bits/stdc++.h>
using namespace std;
template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec);
template <typename T>
std::ostream& operator<<(std::ostream& os, const std::set<T>& vec);
template <typename T>
std::ostream& operator<<(std::ostream& os, const std::unordered_set<T>& vec);
template <typename T>
std::ostream& operator<<(std::ostream& os, const std::multiset<T>& vec);
template <typename T>
std::ostream& operator<<(std::ostream& os,
                         const std::unordered_multiset<T>& vec);
template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& os, const std::pair<T1, T2>& p);
template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& os, const std::map<T1, T2>& p);
template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& os, const std::unordered_map<T1, T2>& p);
template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
  os << "{";
  for (auto elem : vec) os << elem << ",";
  os << "}";
  return os;
}
template <typename T>
std::ostream& operator<<(std::ostream& os, const std::set<T>& vec) {
  os << "{";
  for (auto elem : vec) os << elem << ",";
  os << "}";
  return os;
}
template <typename T>
std::ostream& operator<<(std::ostream& os, const std::unordered_set<T>& vec) {
  os << "{";
  for (auto elem : vec) os << elem << ",";
  os << "}";
  return os;
}
template <typename T>
std::ostream& operator<<(std::ostream& os, const std::multiset<T>& vec) {
  os << "{";
  for (auto elem : vec) os << elem << ",";
  os << "}";
  return os;
}
template <typename T>
std::ostream& operator<<(std::ostream& os,
                         const std::unordered_multiset<T>& vec) {
  os << "{";
  for (auto elem : vec) os << elem << ",";
  os << "}";
  return os;
}
template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& os, const std::pair<T1, T2>& p) {
  os << "{" << p.first << "," << p.second << "}";
  return os;
}
template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& os, const std::map<T1, T2>& p) {
  os << "{";
  for (auto x : p) os << x.first << "->" << x.second << ", ";
  os << "}";
  return os;
}
template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& os,
                         const std::unordered_map<T1, T2>& p) {
  os << "{";
  for (auto x : p) os << x.first << "->" << x.second << ", ";
  os << "}";
  return os;
}
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
long long find_parent(long long parent[], long long a) {
  if (parent[a] >= 0)
    return parent[a] = find_parent(parent, parent[a]);
  else
    return a;
}
void merge_sets(long long parent[], long long a, long long b) {
  long long p1 = find_parent(parent, a), p2 = find_parent(parent, b);
  if (p1 == p2) return;
  if (abs(parent[p1]) < abs(parent[p2])) swap(p1, p2);
  parent[p1] -= abs(parent[p2]);
  parent[p2] = p1;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n, m;
  cin >> n >> m;
  long long parent[n + 1];
  memset(parent, -1, sizeof(parent));
  ;
  vector<vector<long long>> adj(n + 1);
  for (long long i = 1; i <= m; i++) {
    long long u, v;
    cin >> u >> v;
    if (find_parent(parent, u) != find_parent(parent, v)) {
      adj[u].push_back(v);
      adj[v].push_back(u);
      merge_sets(parent, u, v);
    }
  }
  memset(parent, -1, sizeof(parent));
  ;
  function<void(long long, long long)> dfs = [&](long long node,
                                                 long long par) {
    parent[node] = par;
    for (auto x : adj[node])
      if (x != par) dfs(x, node);
  };
  dfs(1, 0);
  vector<long long> w(n + 1, 0);
  long long q;
  cin >> q;
  vector<vector<long long>> paths;
  while (q--) {
    long long u, v;
    cin >> u >> v;
    vector<long long> path1;
    vector<long long> path2;
    vector<long long> path;
    while (u != 1) {
      path1.push_back(u);
      w[u] ^= 1;
      u = parent[u];
    }
    while (v != 1) {
      path2.push_back(v);
      w[v] ^= 1;
      v = parent[v];
    }
    while (!path1.empty() && !path2.empty() && path1.back() == path2.back()) {
      path1.pop_back();
      path2.pop_back();
    }
    if (!path1.empty())
      path1.push_back(parent[path1.back()]);
    else {
      assert(!path2.empty());
      path2.push_back(parent[path2.back()]);
    }
    reverse(path2.begin(), path2.end());
    for (auto x : path2) path1.push_back(x);
    paths.push_back(path1);
  }
  bool flag = true;
  for (long long i = 2; i <= n; i++) {
    flag = flag & (w[i] == 0);
  }
  if (flag) {
    cout << "YES\n";
    for (auto path : paths) {
      cout << path.size() << "\n";
      for (auto x : path) {
        cout << x << " ";
      }
      cout << "\n";
    }
    return 0;
  }
  long long more_queries = 0;
  function<void(long long, long long, long long)> dfs2 =
      [&](long long node, long long par, long long overflag) {
        long long cur = overflag;
        for (long long i : adj[node]) {
          if (i == par) continue;
          if (w[i]) {
            cur ^= 1;
            more_queries += cur;
            dfs2(i, node, 1);
          } else {
            dfs2(i, node, 0);
          }
        }
      };
  dfs2(1, 0, 0);
  cout << "NO\n";
  cout << more_queries << "\n";
}
