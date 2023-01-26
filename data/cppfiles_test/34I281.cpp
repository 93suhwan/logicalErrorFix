#include <bits/stdc++.h>
using namespace std;
int a[200050];
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    int m = max((long long)0, n - 2 * k - 1);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    long long ans = 2 - k * (a[0] | a[1]);
    for (int i = m; i < n - 1; i++) {
      ans = max(
          ans, (long long)(i + 1) * (i + 2) - (long long)k * (a[i] | a[i + 1]));
    }
    cout << ans << endl;
  }
}
