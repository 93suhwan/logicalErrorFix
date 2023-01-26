#include <bits/stdc++.h>
using namespace std;
const int INF = (int)1e9 + 7;
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  freopen("input", "r", stdin);
  int tt;
  cin >> tt;
  for (int tc = 1; tc <= tt; tc++) {
    int sz;
    cin >> sz;
    vector<int> v(sz), sol;
    for (auto &x : v) {
      cin >> x;
    }
    int deja = 0;
    int initlast = INF;
    vector<int> guys = {INF, v[0]};
    int last = initlast;
    sol.push_back(v[0]);
    for (int i = 1; i < sz; i++) {
      if (guys.back() > guys[(int)guys.size() - 2]) {
        last = guys.back();
      }
      int x = v[i];
      if (x < guys.back()) {
        guys.back() = x;
        sol.push_back(x);
        continue;
      }
      if (0) {
        if (-x < guys.back()) {
          guys.back() = -x;
          sol.push_back(-x);
          continue;
        }
        if (x < last) {
          guys.push_back(x);
          sol.push_back(x);
          last = initlast;
          continue;
        }
      } else {
        if (x < last) {
          guys.push_back(x);
          sol.push_back(x);
          last = initlast;
          continue;
        }
        if (-x < guys.back()) {
          guys.back() = -x;
          sol.push_back(-x);
          continue;
        }
      }
      if (-x < last) {
        guys.push_back(-x);
        sol.push_back(-x);
        last = initlast;
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
