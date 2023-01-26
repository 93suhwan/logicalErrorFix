#include <bits/stdc++.h>
using namespace std;
const int INF = (int)1e9 + 7;
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  for (int tc = 1; tc <= tt; tc++) {
    int sz;
    cin >> sz;
    vector<int> v(sz), sol;
    for (auto &x : v) {
      cin >> x;
    }
    int last = INF, deja = 0;
    vector<int> guys = {INF, v[0]};
    sol.push_back(v[0]);
    for (int i = 1; i < sz; i++) {
      int x = v[i];
      if (x < guys.back()) {
        guys.back() = x;
        sol.push_back(x);
        continue;
      }
      if (-x < guys.back()) {
        guys.back() = -x;
        sol.push_back(-x);
        continue;
      }
      if (x < guys[(int)guys.size() - 2]) {
        guys.push_back(x);
        sol.push_back(x);
        continue;
      }
      if (-x < guys[(int)guys.size() - 2]) {
        guys.push_back(-x);
        sol.push_back(-x);
        continue;
      }
      break;
    }
    if ((int)sol.size() != sz) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    for (auto &x : sol) {
      cout << -x << " ";
    }
    cout << "\n";
  }
  return 0;
}
