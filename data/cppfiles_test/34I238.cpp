#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    long long a[n];
    long long ans = -(1e18);
    for (long long i = 0; i < n; i++) cin >> a[i];
    for (long long i = n - 1; i >= 0 && i * (i + 1) > ans; i--)
      for (long long j = i - 1; j >= 0 && i * j > ans; j--) {
        ans = max(ans, (i + 1) * (j + 1) - k * (a[i] | a[j]));
      }
    cout << ans << '\n';
  }
}
