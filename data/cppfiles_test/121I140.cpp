#include <bits/stdc++.h>
using namespace std;
class CMenora {
 public:
  void solveOne() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    int n01 = 0;
    int n10 = 0;
    int n11 = 0;
    int n00 = 0;
    for (int i = 0; i < n; ++i) {
      if (a[i] == '0' && b[i] == '0') ++n00;
      if (a[i] == '0' && b[i] == '1') ++n01;
      if (a[i] == '1' && b[i] == '0') ++n10;
      if (a[i] == '1' && b[i] == '1') ++n11;
    }
    if (n01 == 0 && n10 == 0) {
      cout << 0 << "\n";
      return;
    }
    if (n10 == 0 && n11 == 0) {
      cout << -1 << "\n";
      return;
    }
    if (n01 == 0 && n11 == 0) {
      cout << -1 << "\n";
      return;
    }
    int res = (int)1e9;
    if ((n01 + n10) % 2 == 0) {
      res = min(res, max(n01, n10) * 2);
    }
    if ((n00 + n11) % 2 == 1) {
      res = min(res, max(n11, n00 + 1) * 2 - 1);
    }
    if (res == (int)1e9) res = -1;
    cout << res << "\n";
  }
  void solve() {
    int nt;
    cin >> nt;
    for (int it = 0; it < nt; ++it) {
      solveOne();
    }
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  CMenora solver;
  solver.solve();
  return 0;
}
