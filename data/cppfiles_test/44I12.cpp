#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;
class Solver {
  int c, d;

 public:
  Solver() { cin >> c >> d; }

 public:
  void solve() {
    int x = min(c, d), y = max(c, d);
    if (x == 0) {
      if (y == 0) {
        cout << "0\n";
      } else {
        cout << "2\n";
      }
    } else if (x == y) {
      cout << "1\n";
    } else {
      if ((y - x) % 2) {
        cout << "-1\n";
      } else {
        cout << "2\n";
      }
    }
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    Solver solver;
    solver.solve();
  }
  return 0;
}
