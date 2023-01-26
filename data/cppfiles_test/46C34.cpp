#include <bits/stdc++.h>
using namespace std;
long long int solve() {
  long long int n;
  cin >> n;
  vector<long long int> a(n);
  for (long long int i = 0; i < n; i++) cin >> a[i];
  vector<long long int> copy(a);
  sort(copy.begin(), copy.end());
  long long int mx = copy[n - 1];
  long long int c = 0;
  long long int curmax = a[n - 1];
  for (long long int i = n - 1; i >= 0; i--) {
    if (a[i] > curmax) {
      c++;
      curmax = a[i];
    }
  }
  return cout << c << "\n", 0;
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
