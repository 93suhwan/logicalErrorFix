#include <bits/stdc++.h>
using namespace std;
template <typename A>
using VE = vector<A>;
template <typename A>
using USET = unordered_set<A>;
template <typename A>
using HEAP = priority_queue<A>;
template <typename A, typename B>
using PA = pair<A, B>;
template <typename A, typename B>
using UMAP = unordered_map<A, B>;
template <typename A>
using RHEAP = priority_queue<A, vector<A>, greater<A> >;
template <typename A>
A MAX(const A &a) {
  return a;
}
template <typename A>
A MIN(const A &a) {
  return a;
}
template <typename A>
A MAX(const A *a, const A *b) {
  return *max_element(a, b);
}
template <typename A>
A MIN(const A *a, const A *b) {
  return *min_element(a, b);
}
template <typename A, typename... B>
A MAX(const A &a, const B &...b) {
  return max(a, MAX(b...));
}
template <typename A, typename... B>
A MIN(const A &a, const B &...b) {
  return min(a, MIN(b...));
}
template <typename A, typename B = typename std::iterator_traits<A>::value_type>
B MAX(A a, A b) {
  return *max_element(a, b);
}
template <typename A, typename B = typename std::iterator_traits<A>::value_type>
B MIN(A a, A b) {
  return *min_element(a, b);
}
const int N = 100010, M = 1010;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout << fixed << setprecision(10);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    VE<vector<pair<int, int> > > g(n);
    vector<int> a(n - 1), b(n - 1), c(n - 1);
    for (int i = 0; i < n - 1; i++) {
      cin >> a[i] >> b[i] >> c[i];
      --a[i];
      --b[i];
      if (c[i] >= 0) {
        int cnt = __builtin_popcount(c[i]);
        g[a[i]].emplace_back(b[i], cnt & 1);
        g[b[i]].emplace_back(a[i], cnt & 1);
      }
    }
    for (int i = 0; i < m; i++) {
      int a, b, c;
      cin >> a >> b >> c;
      --a;
      --b;
      g[a].emplace_back(b, c);
      g[b].emplace_back(a, c);
    }
    vector<int> color(n, -1);
    function<bool(int, int, int)> dfs = [&](int u, int fa, int cc) -> bool {
      if (color[u] != -1) {
        return color[u] == cc;
      }
      color[u] = cc;
      for (auto &[v, p] : g[u]) {
        if (v != fa) {
          if (!dfs(v, u, cc ^ p)) {
            return false;
          }
        }
      }
      return true;
    };
    bool flag = true;
    for (int i = 0; i < n; i++) {
      if (color[i] == -1 && !dfs(i, -1, 0)) {
        flag = false;
        break;
      }
    }
    if (!flag) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    for (int i = 0; i < n - 1; i++) {
      if (c[i] == -1) {
        c[i] = 1 - (int)(color[a[i]] == color[b[i]]);
      }
      cout << a[i] + 1 << ' ' << b[i] + 1 << ' ' << c[i] << '\n';
    }
  }
  return 0;
}
