#include <bits/stdc++.h>
using namespace std;
const int inf = 2e9;
const int N = 200001;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  for (int zz = 0; zz < t; zz++) {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> e;
    set<int> v;
    for (int i = 0; i < m; i++) {
      int a, b, c;
      cin >> a >> b >> c;
      if (v.find(a) != v.end() && v.find(c) != v.end()) continue;
      e.emplace_back(a, c);
      v.insert(a);
      v.insert(c);
    }
    int kek = *(v.begin());
    for (int i = 0; i < n; i++) {
      if (v.find(i) == v.end()) e.emplace_back(kek, i);
    }
    for (auto p : e) {
      cout << p.first + 1 << " " << p.second + 1 << "\n";
    }
  }
}
