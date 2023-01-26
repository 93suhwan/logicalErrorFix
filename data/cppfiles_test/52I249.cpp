#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n, i;
  cin >> n;
  long double a[n];
  for (i = 0; i < n; i++) cin >> a[i];
  stable_sort(a, a + n);
  long double s = 0;
  for (i = 0; i < n; i++) {
    s += a[i];
  }
  long double k = INT_MIN;
  long double q = 0;
  for (i = 0; i < n - 1; i++) {
    q += a[i];
    k = max(k, (q / (i + 1) + (s - q) / (n - 1 - i)));
  }
  cout << k << "\n";
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
