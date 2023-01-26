#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
void solve() {
  int n;
  cin >> n;
  vector<double> z(n);
  for (double &it : z) {
    cin >> it;
  }
  sort(z.begin(), z.end());
  double x = 0;
  for (int i = 0; i < n - 1; i++) {
    x += z[i];
  }
  double ans = z.back() + (x / ((n - 1) * 1.0));
  cout << fixed << setprecision(6) << ans << "\n";
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int tq = 1;
  cin >> tq;
  for (; tq; tq--) {
    solve();
  }
}
