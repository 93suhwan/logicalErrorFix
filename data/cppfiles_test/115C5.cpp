#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, m;
    cin >> n >> m;
    long long int i;
    long long int a[n + 2];
    long long int sum = 0;
    for (i = 0; i < n; i++) cin >> a[i];
    long long int l = 1;
    long long int r = m, mid;
    while (l <= r) {
      mid = (l + r) / 2;
      sum = 0;
      for (i = 0; i < n - 1; i++) {
        long long int d = a[i] + mid;
        if (d >= a[i + 1])
          sum = sum + a[i + 1] - a[i];
        else
          sum = sum + mid;
      }
      if (sum + mid >= m) {
        r = mid - 1;
      } else
        l = mid + 1;
    }
    cout << l;
    cout << "\n";
  }
}
