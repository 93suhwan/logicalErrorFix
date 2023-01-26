#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;
class Solver {
  int p;

 public:
  Solver() { cin >> p; }

 public:
  void solve() { cout << 2 << " " << p - 1 << "\n"; }
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
