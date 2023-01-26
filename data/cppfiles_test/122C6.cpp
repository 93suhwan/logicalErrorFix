#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int> >& adj, int v, int p, vector<int>& tin,
         vector<int>& tout, int& cnt) {
  tin[v] = cnt++;
  for (int u : adj[v]) {
    if (p == u) continue;
    dfs(adj, u, v, tin, tout, cnt);
  }
  tout[v] = cnt++;
}
void update(vector<vector<pair<int, int> > >& bed, vector<int>& pref, int v) {
  int u, p;
  for (pair<int, int> pair : bed[v]) {
    tie(u, p) = pair;
    if (pref[u] == -1) {
      pref[u] = pref[v] ^ p;
      update(bed, pref, u);
    } else {
      if (pref[u] != (pref[v] ^ p)) throw(42);
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cout.tie(0);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > adj(n);
    vector<tuple<int, int, int> > edges;
    for (int i = 1, a, b, p; i < n; i++) {
      cin >> a >> b >> p;
      a--;
      b--;
      edges.push_back(make_tuple(a, b, p));
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
    vector<int> tin(n), tout(n);
    int cnt = 0;
    dfs(adj, 0, 0, tin, tout, cnt);
    vector<vector<pair<int, int> > > bedingungen(2 * n);
    int a, b, p;
    for (tuple<int, int, int> e : edges) {
      tie(a, b, p) = e;
      if (p == -1) continue;
      a = tin[a];
      b = tin[b];
      p = __builtin_popcount(p);
      bedingungen[a].push_back(make_pair(b, p % 2));
      bedingungen[b].push_back(make_pair(a, p % 2));
    }
    for (int v = 1; v < n; v++) {
      a = tin[v] - 1;
      b = tout[v];
      bedingungen[a].push_back(make_pair(b, 0));
      bedingungen[b].push_back(make_pair(a, 0));
    }
    for (int i = 0; i < m; i++) {
      cin >> a >> b >> p;
      a--;
      b--;
      a = tin[a];
      b = tin[b];
      bedingungen[a].push_back(make_pair(b, p));
      bedingungen[b].push_back(make_pair(a, p));
    }
    try {
      vector<int> pref(2 * n, -1);
      for (int v = 0; v < 2 * n; v++) {
        if (pref[v] == -1) {
          pref[v] = 0;
          update(bedingungen, pref, v);
        }
      }
      vector<int> vertices(2 * n);
      vertices[0] = 0;
      for (int i = 1; i < 2 * n; i++) {
        vertices[i] = pref[i - 1] ^ pref[i];
      }
      cout << "YES\n";
      for (tuple<int, int, int> e : edges) {
        tie(a, b, p) = e;
        if (p == -1) {
          if (tin[a] > tin[b]) swap(a, b);
          p = vertices[tin[b]];
        }
        cout << ++a << " " << ++b << " " << p << "\n";
      }
    } catch (int i) {
      cout << "NO\n";
    }
  }
}
