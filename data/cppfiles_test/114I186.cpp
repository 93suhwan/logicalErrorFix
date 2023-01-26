#include <bits/stdc++.h>
using namespace std;
const double EPS = (1e-7);
int dcmp(double x, double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }
void solve() {
  int n;
  cin >> n;
  vector<int> vec(n);
  for (int i = 0; i < n; i++) cin >> vec[i];
  sort(vec.begin(), vec.end());
  int i = 0;
  int j = n - 1;
  while (i < j) {
    cout << vec[i] << " " << vec[j] << endl;
    i++;
    j--;
  }
}
signed main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
    cout << "\n";
  }
  return 0;
}
