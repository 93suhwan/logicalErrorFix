#include <bits/stdc++.h>
using namespace std;
class DSU {
  vector<int> rank, parent;
  int n;

 public:
  DSU(int n_) : rank(n_, 0), parent(n_) {
    this->n = n_;
    for (int i = 0; i < n; ++i) parent[i] = i;
  }
  int find(int x) {
    if (parent[x] != x) parent[x] = find(parent[x]);
    return parent[x];
  }
  void join(int x, int y) {
    int xset = find(x);
    int yset = find(y);
    if (xset == yset) return;
    if (rank[xset] < rank[yset])
      parent[xset] = yset;
    else if (rank[xset] > rank[yset])
      parent[yset] = xset;
    else {
      parent[yset] = xset;
      rank[xset]++;
    }
  }
};
void solve_yes(int n, const vector<int>& x, const vector<int>& y,
               const vector<int>& a, const vector<int>& b) {
  int m = x.size();
  vector<vector<int>> adj(n);
  DSU dsu(n);
  for (int i = 0; i < m; ++i) {
    if (dsu.find(x[i]) != dsu.find(y[i])) {
      dsu.join(x[i], y[i]);
      adj[x[i]].push_back(y[i]);
      adj[y[i]].push_back(x[i]);
    }
  }
  for (int qi = 0; qi < int(a.size()); ++qi) {
    vector<int> ba(n, -1);
    ba[a[qi]] = a[qi];
    vector<int> q;
    q.reserve(n);
    q.push_back(a[qi]);
    for (int i = 0; ba[b[qi]] < 0; ++i) {
      int me = q[i];
      for (int him : adj[me]) {
        if (ba[him] < 0) {
          ba[him] = me;
          q.push_back(him);
        }
      }
    }
    vector<int> p(1, b[qi]);
    int cur = b[qi];
    while (cur != a[qi]) {
      cur = ba[cur];
      p.push_back(cur);
    }
    reverse(p.begin(), p.end());
    int k = p.size();
    cout << k << "\n";
    for (int i = 0; i < k; ++i) {
      if (i > 0) cout << " ";
      cout << (p[i] + 1);
    }
    cout << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  vector<int> x(m), y(m);
  for (int i = 0; i < m; ++i) {
    cin >> x[i] >> y[i];
    --x[i];
    --y[i];
  }
  int q;
  cin >> q;
  vector<int> a(q), b(q);
  for (int i = 0; i < q; ++i) {
    cin >> a[i] >> b[i];
    --a[i];
    --b[i];
  }
  vector<int> parity(n, 0);
  for (int i = 0; i < q; ++i) {
    parity[a[i]] ^= 1;
    parity[b[i]] ^= 1;
  }
  int need = 0;
  for (int i = 0; i < n; ++i) {
    need += parity[i];
  }
  if (need > 0) {
    cout << "NO\n" << (need / 2) << "\n";
  } else {
    cout << "YES\n";
    solve_yes(n, x, y, a, b);
  }
}
