#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
string to_string(pair<A, B> p);
string to_string(const string &s) { return '"' + s + '"'; }
string to_string(const char *s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) res += static_cast<char>('0' + v[i]);
  return res;
}
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) res += ", ";
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
class DSU {
 public:
  DSU(long long n, const vector<long long> &a) : num_comp_(n), root_(n + 1, 0) {
    ls_.resize(n + 1);
    a_.resize(n + 1);
    for (long long i = 1; i <= n; i++) {
      ls_[i].push_back(i);
      a_[i] = a[i];
    }
  }
  long long num_comp() { return num_comp_; }
  long long a(long long u) { return a_[u]; }
  vector<long long> &ls(long long u) { return ls_[u]; }
  long long GetRoot(long long u) {
    return root_[u] ? root_[u] = GetRoot(root_[u]) : u;
  }
  bool Unite(long long u, long long v) {
    u = GetRoot(u);
    v = GetRoot(v);
    if (u == v) return 0;
    a_[v] += a_[u];
    if (ls_[v].size() < ls_[u].size()) {
      swap(ls_[u], ls_[v]);
    }
    ls_[v].insert(ls_[v].end(), ls_[u].begin(), ls_[u].end());
    ls_[u].clear();
    root_[u] = v;
    num_comp_--;
    return 1;
  }

 private:
  long long num_comp_;
  vector<long long> a_;
  vector<long long> root_;
  vector<vector<long long>> ls_;
};
void Solve(long long test) {
  long long n, m;
  cin >> n >> m;
  vector<long long> a(n + 1, 0);
  for (long long i = 2; i <= n; i++) {
    cin >> a[i];
  }
  vector<long long> b(n + 1, 0);
  for (long long i = 2; i <= n; i++) {
    cin >> b[i];
  }
  vector<vector<pair<long long, long long>>> adj(
      n + 1, vector<pair<long long, long long>>());
  for (long long i = 1; i <= m; i++) {
    long long u, v;
    cin >> u >> v;
    adj[u].push_back({v, i});
    adj[v].push_back({u, i});
  }
  auto Check = [&](long long init_value) -> bool {
    b[1] = init_value;
    DSU dsu(n, b);
    while (dsu.num_comp() > 1) {
      queue<long long> q;
      vector<long long> d(n + 1, -1);
      vector<long long> last_edge(n + 1, -1);
      vector<long long> last_ver(n + 1, -1);
      vector<long long> cur(n + 1, 0);
      auto root = dsu.GetRoot(1);
      cur[root] = dsu.a(root);
      d[root] = 0;
      q.push(root);
      bool found_loop = false;
      pair<long long, long long> loop;
      while (!q.empty() && !found_loop) {
        long long u = q.front();
        q.pop();
        for (long long node_u : dsu.ls(u)) {
          for (auto [node_v, edge_id] : adj[node_u]) {
            auto v = dsu.GetRoot(node_v);
            if (u == v) continue;
            if (last_edge[u] == edge_id) continue;
            if (cur[u] <= a[node_v]) continue;
            if (d[v] == -1) {
              d[v] = d[u] + 1;
              last_edge[v] = edge_id;
              last_ver[v] = u;
              cur[v] = cur[u] + dsu.a(v);
              q.push(v);
            } else {
              found_loop = true;
              loop = {u, v};
              break;
            }
          }
          if (found_loop) {
            break;
          }
        }
      }
      if (!found_loop) {
        break;
      }
      auto [u, v] = loop;
      auto Go = [&](long long u) {
        while (u != -1) {
          dsu.Unite(u, root);
          u = last_ver[u];
        }
      };
      Go(u);
      Go(v);
    }
    return dsu.num_comp() == 1;
  };
  long long low = 0, high = *max_element(a.begin(), a.end()) + 1;
  while (high - low > 1) {
    long long mid = low + high >> 1;
    if (Check(mid)) {
      high = mid;
    } else {
      low = mid;
    }
  }
  cout << high << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long tc;
  cin >> tc;
  for (long long test = 1; test <= tc; ++test) Solve(test);
  return 0;
}
