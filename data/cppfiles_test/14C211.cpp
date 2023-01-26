#include <bits/stdc++.h>
using namespace std;
void shift(vector<int>& v, int l, int r) {
  int x = v[r];
  for (int i = r; i > l; i--) {
    v[i] = v[i - 1];
  }
  v[l] = x;
}
void solve() {
  int n;
  cin >> n;
  std::vector<int> a;
  for (int i = 0; i < n; i++) {
    int e;
    cin >> e;
    a.push_back(e);
  }
  vector<int> b = a;
  sort(b.begin(), b.end());
  vector<pair<int, int>> p;
  for (int l = 0; l < n; l++) {
    if (a[l] == b[l]) {
      continue;
    }
    for (int r = l + 1; r < n; r++) {
      if (a[r] == b[l]) {
        p.push_back({l, r});
        shift(a, l, r);
        break;
      }
    }
  }
  cout << p.size() << endl;
  for (auto ps : p) {
    cout << ps.first + 1 << " " << ps.second + 1 << " " << ps.second - ps.first
         << endl;
  }
  for (int i = 0; i < n; i++) {
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    solve();
  }
  return 0;
}
