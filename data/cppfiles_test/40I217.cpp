#include <bits/stdc++.h>
using namespace std;
long long a[100005], b[100005];
int main() {
  long long t, m;
  cin >> t;
  while (t--) {
    cin >> m;
    long long max1 = 0, max2 = 0;
    for (int i = 0; i < m; i++) {
      cin >> a[i];
      if (i > 0) {
        max1 += a[i];
      }
    }
    for (int i = 0; i < m; i++) {
      cin >> b[i];
      if (i != m - 1) {
        max2 += b[i];
      }
    }
    int mid = m / 2;
    long long sum1 = 0, sum2 = 0;
    for (int i = mid + 1; i < m; i++) {
      sum1 += a[i];
    }
    for (int i = 0; i < mid; i++) {
      sum2 += b[i];
    }
    long long sum_e1 = 0, sum_e2 = 0;
    if (m % 2 == 0) {
      for (int i = mid + 2; i < m; i++) {
        sum_e1 += a[i];
      }
      for (int i = 0; i <= mid; i++) {
        sum_e2 += b[i];
      }
      if (min(max1, max2) <= max(sum1, sum2) ||
          min(max1, max2) <= max(sum_e1, sum_e2)) {
        cout << min(max1, max2) << endl;
      } else {
        cout << min(max(sum1, sum2), max(sum_e1, sum_e2)) << endl;
      }
    } else {
      if (max(sum1, sum2) >= min(max1, max2)) {
        cout << min(max1, max2) << endl;
      } else {
        cout << max(sum1, sum2) << endl;
      }
    }
  }
  return 0;
}
