#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const long double pi = 2 * acos(0.0);
const int mod = 1e9 + 7;
const int maxn = 2e5 + 5;
void solve() {
  int n = 7;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  cout << a[6] - a[5] << ' ' << a[6] - a[4] << ' ' << a[6] - a[3] << '\n';
  return;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
