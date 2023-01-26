#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    vector<long long int> a(n);
    for (long long int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    long double sum = 0;
    for (long long int i = 0; i < n - 1; ++i) sum += a[i];
    long double ans = a[n - 1] + sum / (n - 1);
    cout << fixed << setprecision(8) << fixed << ans << endl;
  }
  return 0;
}
