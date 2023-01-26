#include <bits/stdc++.h>
using namespace std;
template <typename... Args>
void __logger(string vars, Args &&...values) {
  cerr << "\n" << vars << " = ";
  string delim = "";
  (..., (cerr << delim << values, delim = ", "));
  cerr << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long tt;
  cin >> tt;
  while (tt--) {
    long long n;
    cin >> n;
    long long a[n];
    double sum = 0;
    for (long long i = 0; i < n; ++i) {
      cin >> a[i];
      sum += a[i];
    }
    sort(a, a + n);
    cout << fixed << setprecision(10);
    double ans = -1e18;
    double x = 0;
    for (long long i = 0; i < n - 1; ++i) {
      x += a[i];
      double y = sum - x;
      ans = max(ans, ((x) / (double)(i + 1)) + (y / (n - i - 1)));
    }
    cout << ans << "\n";
  }
  return 0;
}
