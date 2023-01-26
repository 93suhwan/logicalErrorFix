#include <bits/stdc++.h>
using namespace std;
void solve() {
  int a, b, i, j, k, l, r, t, q, cnt1 = 0, cnt2 = 0, x, y, z, n, cnt = 0,
                                 ma = INT_MIN, mi = INT_MAX, sum = 0;
  vector<int> vc(7);
  for (auto &i : vc) cin >> i;
  n = vc[0];
  if (vc[1] == n && vc[2] == n)
    cout << n << " " << n << " " << n << endl;
  else {
    if (vc[1] == vc[2]) {
      n = vc[6];
      cout << n - vc[5] << " " << n - vc[4] << " " << n - vc[3] << endl;
    } else
      cout << vc[0] << " " << vc[1] << " " << vc[3] << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
