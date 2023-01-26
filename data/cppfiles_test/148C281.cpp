#include <bits/stdc++.h>
using namespace std;
long long mod_power(int x, int n) {
  long long res = 1;
  while (n > 0) {
    if (n % 2 != 0) res = (res * x) % long long(1e9 + 7);
    x = (x * x) % long long(1e9 + 7);
    n /= 2;
  }
  return res;
}
long long power(int x, int n) {
  long long res = 1;
  while (n > 0) {
    if (n % 2 != 0) res *= x;
    x *= x;
    n /= 2;
  }
  return res;
}
void solve() {
  long long w, h;
  cin >> w >> h;
  long long maxh = 0, maxv = 0;
  vector<vector<long long>> v(4);
  for (int j = 0; j < 4; j++) {
    long long k;
    cin >> k;
    for (int i = 0; i < k; i++) {
      long long x;
      cin >> x;
      v[j].push_back(x);
    }
    if (j < 2) {
      if (abs(v[j][0] - v[j][k - 1]) > maxh) maxh = v[j][k - 1] - v[j][0];
    } else {
      if (abs(v[j][0] - v[j][k - 1]) > maxv) maxv = v[j][k - 1] - v[j][0];
    }
  }
  if (maxv * w > maxh * h)
    cout << maxv * w << endl;
  else
    cout << maxh * h << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
