#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<long long> a(n);
    long long odd = 0, swap = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] & 1) {
        odd++;
      }
    }
    if (abs(n - 2 * odd) > 1) {
      cout << -1 << endl;
      continue;
    }
    long long oi, ei;
    if (2 * odd > n) {
      oi = 0;
      ei = 1;
      for (int x = 0; x < n; x++) {
        if (a[x] & 1) {
          swap += max((long long)0, x - oi);
          oi += 2;
        } else {
          swap += max((long long)0, x - ei);
          ei += 2;
        }
      }
    } else if (2 * odd < n) {
      oi = 1;
      ei = 0;
      for (int x = 0; x < n; x++) {
        if (a[x] & 1) {
          swap += max((long long)0, x - oi);
          oi += 2;
        } else {
          swap += max((long long)0, x - ei);
          ei += 2;
        }
      }
    } else {
      if (a[0] & 1) {
        oi = 0;
        ei = 1;
      } else {
        oi = 1;
        ei = 0;
      }
      for (int x = 0; x < n; x++) {
        if (a[x] & 1) {
          swap += max((long long)0, x - oi);
          oi += 2;
        } else {
          swap += max((long long)0, x - ei);
          ei += 2;
        }
      }
    }
    cout << swap << endl;
  }
  return 0;
}
