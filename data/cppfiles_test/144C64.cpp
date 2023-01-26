#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  if (n % m == 0) {
    for (int it = 0; it < k; ++it) {
      for (int i = 0; i < n; ++i) {
        if (i % (n / m) == 0) {
          if (i) cout << '\n';
          cout << n / m << ' ';
        }
        cout << i + 1 << ' ';
      }
      cout << '\n';
    }
    return;
  }
  int r = n % m;
  int t = m - r;
  int a = n / m + 1, b = n / m;
  set<pair<int, int>> s;
  for (int i = 0; i < n; ++i) s.emplace(0, i);
  for (int _ = 0; _ < k; ++_) {
    vector<pair<int, int>> v;
    for (int i = 0; i < a * r; ++i) {
      v.push_back(*s.begin());
      s.erase(*s.begin());
    }
    auto it = s.begin();
    for (int i = 0; i < b * t; ++i, ++it) {
      if (i % b == 0) {
        if (i) cout << '\n';
        cout << b << ' ';
      }
      cout << it->second + 1 << ' ';
    }
    for (int i = 0; i < a * r; ++i) {
      if (i % a == 0) {
        cout << '\n' << a << ' ';
      }
      cout << v[i].second + 1 << ' ';
      ++v[i].first;
      s.insert(v[i]);
    }
    cout << '\n';
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
    cout << '\n';
  }
  return 0;
}
