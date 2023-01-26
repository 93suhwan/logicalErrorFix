#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    long long index = 0;
    long long count = 0;
    for (long long p = 0; p < n; p++) {
      if (a[p] >= 0) {
        index = p;
        break;
      }
      count++;
    }
    if (count == n) index = n;
    long long total = 0;
    long long i;
    for (long long p = n - 1; p >= index; p -= k) {
      if (p == (n - 1)) {
        total += (a[p]);
      } else {
        total += (2 * a[p]);
      }
    }
    for (long long p = 0; p < index; p += k) {
      if (p == 0) {
        total += abs(a[p]);
      } else {
        total += (2 * abs(a[p]));
      }
    }
    if (index != 0 && index != n) {
      if (abs(a[0]) > a[n - 1]) {
        total += a[n - 1];
      } else {
        total += (abs(a[0]));
      }
    }
    cout << total << "\n";
  }
  return 0;
}
