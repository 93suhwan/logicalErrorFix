#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long a[n];
    long long mx = 0;
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
      mx = max(mx, a[i]);
    }
    long long ans = 0;
    for (long long i = 0; i < n - 1; i++) {
      ans = max(ans, a[i] * a[i + 1]);
    }
    cout << ans << endl;
  }
  return 0;
}
