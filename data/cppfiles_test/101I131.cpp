#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  multiset<int> blue, red;
  vector<int> v(n);
  for (auto &c : v) cin >> c;
  string s;
  cin >> s;
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'R') {
      red.insert(v[i]);
    } else {
      blue.insert(v[i]);
    }
  }
  for (int i = 1; i <= n; ++i) {
    bool found = false;
    if (!blue.empty()) {
      auto it = blue.begin();
      if (*it == i) {
        blue.erase(blue.begin());
        found = true;
      }
    }
    if (!red.empty() && !found) {
      auto it = red.begin();
      if (*it == i) {
        red.erase(red.begin());
        found = true;
      }
    }
    if (!red.empty() && !found) {
      auto it = red.begin();
      if (*it < i) {
        red.erase(red.begin());
        found = true;
      }
    }
    if (!blue.empty() && !found) {
      auto it = blue.begin();
      if (*it > i) {
        blue.erase(blue.begin());
        found = true;
      }
    }
    if (!found) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}
