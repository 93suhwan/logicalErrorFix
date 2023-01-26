#include <bits/stdc++.h>
using namespace std;
int parent[500005];
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
  for (int i = q - 1; i >= 0; i--) {
    long long type = queries[i].first;
    if (type == 1) {
      long long x = queries[i].second.first;
      a.push_back(parent[x]);
    } else {
      long long x = queries[i].second.first;
      long long y = queries[i].second.second;
      parent[x] = parent[y];
    }
  }
  reverse(a.begin(), a.end());
  for (auto &i : a) cout << i << " ";
  cout << "\n";
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
