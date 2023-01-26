#include <bits/stdc++.h>
using namespace std;
int a[104];
int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    int n, k;
    long long ans = 0;
    cin >> n >> k;
    for (int j = 1; j <= n; j++) {
      cin >> a[j];
    }
    sort(a + 1, a + n + 1);
    int r = n;
    int l = n - k;
    for (int j = 1; j <= k; j++) {
      ans += a[l] / a[r];
      l--;
      r--;
    }
    for (int j = 1; j <= n - 2 * k; j++) {
      ans += a[j];
    }
    cout << ans << endl;
  }
}
