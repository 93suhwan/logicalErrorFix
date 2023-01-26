#include <bits/stdc++.h>
using namespace std;
class Graph {
  long long int n;
  vector<long long int> parent;
  vector<long long int> rank;

 public:
  void init(long long int n) {
    parent.resize(n + 1);
    rank.resize(n + 1);
    for (long long int i = 0; i <= n; i++) {
      parent[i] = i;
      rank[i] = 1;
    }
  }
  long long int findSet(long long int u) {
    return parent[u] == u ? u : parent[u] = findSet(parent[u]);
  }
  void unionSet(long long int x, long long int y) {
    long long int s1 = findSet(x);
    long long int s2 = findSet(y);
    if (s1 != s2) {
      if (rank[s1] < rank[s2]) {
        parent[s1] = s2;
        rank[s2] += rank[s1];
      } else {
        parent[s2] = s1;
        rank[s1] += rank[s2];
      }
    }
  }
};
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long int n, m1, m2;
  cin >> n >> m1 >> m2;
  Graph g1, g2;
  g1.init(n);
  g2.init(n);
  while (m1--) {
    long long int a, b;
    cin >> a >> b;
    g1.unionSet(a, b);
  }
  while (m2--) {
    long long int a, b;
    cin >> a >> b;
    g2.unionSet(a, b);
  }
  vector<pair<long long int, long long int>> ans;
  for (long long int i = 1; i <= n; i++) {
    if (g1.findSet(i) != g1.findSet(1) and g2.findSet(i) != g2.findSet(1)) {
      ans.push_back(make_pair(i, 1));
      g1.unionSet(i, 1);
      g2.unionSet(i, 1);
    }
  }
  long long int l = 1, r = 1;
  while (l <= n and r <= n) {
    while (l <= n and g1.findSet(l) == g1.findSet(1)) l++;
    while (r <= n and g2.findSet(r) == g2.findSet(1)) r++;
    if (l > n or r > n) break;
    g1.unionSet(l, 1);
    g2.unionSet(r, 1);
    ans.push_back(make_pair(l, r));
  }
  cout << ans.size() << "\n";
  for (long long int i = 0; i < ans.size(); i++) {
    cout << ans[i].first << " " << ans[i].second << "\n";
  }
}
