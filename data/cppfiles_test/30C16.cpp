#include <bits/stdc++.h>
using namespace std;
template <class c>
struct rge {
  c b, e;
};
template <class c>
rge<c> range(c i, c j) {
  return rge<c>{i, j};
}
template <class c>
auto dud(c* x) -> decltype(cerr << *x, 0);
template <class c>
char dud(...);
struct debug {
  template <class c>
  debug& operator<<(const c&) {
    return *this;
  }
};
struct DSU {
  std::vector<int> parent;
  DSU(int m) {
    parent.resize(m + 1);
    for (int i = 0; i <= m; i++) {
      parent[i] = i;
    }
  }
  int find(int a) {
    if (a == parent[a]) {
      return a;
    }
    return parent[a] = find(parent[a]);
  }
  void uni(int a, int b) { parent[find(a)] = find(b); }
};
int main() {
  int n, q;
  scanf("%d%d", &n, &q);
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  int m = *max_element(a.begin(), a.end());
  vector<vector<int>> prime_divisors(m + 2);
  for (int p = 2; p <= m + 1; ++p) {
    if (prime_divisors[p].empty()) {
      for (int j = p; j <= m + 1; j += p) {
        prime_divisors[j].push_back(p);
      }
    }
  }
  DSU dsu(m + 2);
  for (int x : a) {
    for (int p : prime_divisors[x]) {
      dsu.uni(x, p);
    }
  }
  set<pair<int, int>> edges;
  for (int x : a) {
    std::vector<int> nodes = prime_divisors[x + 1];
    nodes.push_back(x);
    for (int& node : nodes) {
      node = dsu.find(node);
    }
    for (int i = 0; i < (int)nodes.size(); ++i) {
      for (int j = i + 1; j < (int)nodes.size(); ++j) {
        int one = nodes[i];
        int two = nodes[j];
        if (one != two) {
          if (one > two) {
            swap(one, two);
          }
          edges.insert({one, two});
        }
      }
    }
  }
  debug() << " ["
          << "edges"
             ": "
          << (edges) << "] ";
  cerr << " ["
       << "edges.size()"
          ": "
       << (edges.size()) << "] " << endl;
  while (q--) {
    int s, t;
    scanf("%d%d", &s, &t);
    --s;
    --t;
    s = dsu.find(a[s]);
    t = dsu.find(a[t]);
    if (s == t) {
      puts("0");
    } else if (edges.count({min(s, t), max(s, t)})) {
      puts("1");
    } else {
      puts("2");
    }
  }
}
