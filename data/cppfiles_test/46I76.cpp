#include <bits/stdc++.h>
using namespace std;
long long int solve() {
  long long int n;
  cin >> n;
  vector<long long int> a(n);
  long long int mx = -1, mn = 1e10;
  for (long long int i = 0; i < n; i++)
    cin >> a[i], mx = max(mx, a[i]), mn = min(a[i], mn);
  long long int sec = a[n - 2];
  if (a[n - 1] == mx) return cout << 0 << "\n", 0;
  sort(a.begin(), a.end());
  long long int c = 1;
  for (long long int i = n - 1; i >= 0; i--) {
    if (a[i] == sec) return cout << c << "\n", 0;
    c++;
  }
  return 0;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int tests = 1;
  cin >> tests;
  while (tests--) solve();
  return 0;
}
