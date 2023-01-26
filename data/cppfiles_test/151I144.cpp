#include <bits/stdc++.h>
using namespace std;
int parent[500005];
int find_set(int a) {
  if (a == parent[a]) return a;
  return parent[a] = find_set(parent[a]);
}
void union_set(int u, int v) {
  u = find_set(u);
  v = find_set(v);
  if (u == v) return;
  parent[u] = v;
}
void init() {
  for (int i = 0; i < 500005; i++) {
    parent[i] = i;
  }
}
void solve() {
  init();
  long long q;
  cin >> q;
  vector<pair<int, pair<int, int>>> queries;
  vector<int> a;
  for (int i = 0; i < q; i++) {
    long long type, x, y;
    cin >> type;
    if (type == 1) {
      cin >> x;
      queries.push_back({1, {x, 0}});
    } else {
      cin >> x >> y;
      queries.push_back({2, {x, y}});
    }
  }
  for (int i = 0; i < q; i++) {
    long long type = queries[i].first;
    if (type == 1 && i != q - 1) {
      long long x = queries[i].second.first;
      a.push_back(x);
    } else if (type == 1 && i == q - 1) {
      long long x = queries[i].second.first;
      a.push_back(x);
      for (int i = 0; i < a.size(); i++) {
        cout << find_set(a[i]) << " ";
      }
    } else if (type == 2 && ((i == q - 1) || (queries[i + 1].first == 1))) {
      long long x, y;
      x = queries[i].second.first;
      y = queries[i].second.second;
      union_set(x, y);
      for (int i = 0; i < a.size(); i++) {
        cout << find_set(a[i]) << " ";
      }
      for (int i = 0; i < a.size(); i++) {
        parent[a[i]] = a[i];
      }
      parent[x] = x;
      a.clear();
    } else {
      long long x, y;
      x = queries[i].second.first;
      y = queries[i].second.second;
      union_set(x, y);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long test = 1;
  while (test--) {
    solve();
  }
  return 0;
}
