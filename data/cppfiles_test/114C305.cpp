#include <bits/stdc++.h>
using namespace std;
const double EPS = (1e-7);
int dcmp(double x, double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }
void solve() {
  int n;
  cin >> n;
  vector<int> vec(n);
  for (int i = 0; i < n; i++) cin >> vec[i];
  int x = *min_element(vec.begin(), vec.end());
  int cnt = n / 2;
  for (int i = 0; i < n; i++) {
    if (cnt == 0) return;
    if (vec[i] == x)
      continue;
    else {
      cout << vec[i] << " " << x << endl;
      cnt--;
    }
  }
}
signed main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
