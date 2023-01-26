#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, sum1 = 0, sum2 = 0, p = INT_MAX, i;
    cin >> n;
    if (n == 1) {
      cout << "0" << endl;
      continue;
    }
    long long a[n], b[n];
    for (i = 0; i < n; i++) {
      cin >> a[i];
      sum1 += a[i];
    }
    for (i = 0; i < n; i++) cin >> b[i];
    for (i = 0; i < n - 1; i++) {
      sum1 = sum1 - a[i];
      p = min(p, max(sum1, sum2));
      sum2 += b[i];
    }
    cout << p << endl;
  }
}
