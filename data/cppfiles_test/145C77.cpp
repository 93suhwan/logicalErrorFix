#include <bits/stdc++.h>
using namespace std;
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
class DSU {
 public:
  vector<int> Parent, Rank;
  DSU(int n) {
    Parent.resize(n + 1);
    Rank.resize(n + 1, 1);
    for (int i = 1; i <= n; i++) Parent[i] = i;
  }
  void Union(int a, int b);
  int Find(int a);
};
void DSU::Union(int a, int b) {
  a = Find(a);
  b = Find(b);
  if (a == b) return;
  if (Rank[a] < Rank[b]) swap(a, b);
  Parent[b] = a;
  if (Rank[a] == Rank[b]) Rank[a]++;
}
int DSU::Find(int a) {
  if (a == Parent[a]) return a;
  return Parent[a] = Find(Parent[a]);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<pair<pair<int, int>, int>> v(n + 1);
    map<int, vector<pair<int, int>>> x, y;
    for (long long int i = 1; i < n + 1; i++) {
      cin >> v[i].first.first >> v[i].first.second >> v[i].second;
      x[v[i].first.first].push_back({v[i].first.second, i});
      y[v[i].first.second].push_back({v[i].first.first, i});
    }
    for (auto j : x) sort(x[j.first].begin(), x[j.first].end());
    for (auto j : y) sort(y[j.first].begin(), y[j.first].end());
    DSU dsu = DSU(n);
    vector<vector<pair<int, int>>> X, Y;
    for (auto j : x) X.push_back(j.second);
    for (auto j : y) Y.push_back(j.second);
    for (long long int i = 0; i < (int)X.size(); i++) {
      for (long long int j = 1; j < (int)X[i].size(); j++) {
        if (abs(X[i][j].first - X[i][j - 1].first) <= k)
          dsu.Union(X[i][j].second, X[i][j - 1].second);
      }
    }
    for (long long int i = 0; i < (int)Y.size(); i++) {
      for (long long int j = 1; j < (int)Y[i].size(); j++) {
        if (abs(Y[i][j].first - Y[i][j - 1].first) <= k)
          dsu.Union(Y[i][j].second, Y[i][j - 1].second);
      }
    }
    set<int> R;
    vector<int> boom(n + 1, INT_MAX);
    for (long long int i = 1; i < n + 1; i++) {
      R.insert(dsu.Find(i));
      boom[dsu.Find(i)] = min(boom[dsu.Find(i)], v[i].second);
    }
    int ans = 0;
    multiset<int> times;
    for (int i : R) {
      times.insert(boom[i]);
    }
    while (!times.empty()) {
      while (!times.empty() && *times.begin() == ans) {
        times.erase(times.begin());
      }
      if (!times.empty()) times.erase(--times.end());
      ans++;
    }
    cout << ans - 1 << '\n';
  }
  return 0;
}
