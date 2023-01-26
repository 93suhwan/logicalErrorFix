#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    k++;
    long long a[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      a[i] = pow(10, a[i]);
    }
    long long sta = 0, ans = 0;
    for (int i = 0; i < n - 1; i++) {
      long long x = a[i + 1] / a[i] - 1;
      if (x > k) break;
      ans += x * a[i];
      k -= x;
      sta++;
    }
    if (k > 0) {
      ans += a[sta] * k;
    }
    cout << ans << '\n';
  }
}
