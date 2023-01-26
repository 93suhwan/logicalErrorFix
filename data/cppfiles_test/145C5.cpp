#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int find_set(int v, vector<int> &parent) {
  if (parent[v] != v) {
    parent[v] = find_set(parent[v], parent);
  }
  return parent[v];
}
void union_sets(int a, int b, vector<int> &parent, vector<int> &size) {
  a = find_set(a, parent);
  b = find_set(b, parent);
  if (a != b) {
    if (size[a] < size[b]) swap(a, b);
    parent[b] = a;
    size[a] += size[b];
  }
  return;
}
void solve() {
  cin.ignore();
  int n, k;
  cin >> n >> k;
  vector<vector<int>> a(n, vector<int>(3));
  for (auto &i : a) {
    for (auto &j : i) {
      cin >> j;
    }
  }
  vector<int> parent(n), size(n);
  for (int i = 0; i < n; i++) {
    a[i].push_back(i);
    parent[i] = i;
    size[i] = 1;
  }
  sort(a.begin(), a.end());
  for (int i = 0; i < n; i++) {
    if (i && abs(a[i][1] - a[i - 1][0]) <= k && a[i][0] == a[i - 1][1]) {
      union_sets(a[i][3], a[i - 1][3], parent, size);
    }
    swap(a[i][0], a[i][1]);
  }
  sort(a.begin(), a.end());
  for (int i = 0; i < n; i++) {
    if (i && abs(a[i][1] - a[i - 1][1]) <= k && a[i][0] == a[i - 1][2]) {
      union_sets(a[i][3], a[i - 1][3], parent, size);
    }
    swap(a[i][0], a[i][2]);
  }
  set<int> active;
  for (int i = 0; i < n; i++) {
    active.insert(find_set(i, parent));
  }
  int ans = (int)active.size() - 1;
  sort(a.begin(), a.end());
  for (int i = 0; i < n; i++) {
    active.erase(find_set(a[i][3], parent));
    ans = min(ans, max(a[i][0], (int)active.size() - 1));
  }
  cout << ans << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  for (int i = 0; i < t; i++) {
    solve();
  }
  return 0;
}
