#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, ev = 0, od = 0, x;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
      cin >> x;
      a[i] = x % 2;
      if (a[i] % 2 == 0)
        ev++;
      else
        od++;
    }
    if (abs(ev - od) > 1)
      cout << "-1\n";
    else {
      if (ev > od) {
        int j = 0, sum = 0;
        for (int i = 0; i < n; i++) {
          if (a[i] == 0) {
            sum += abs(i - j);
            j += 2;
          }
        }
        cout << sum << endl;
      } else if (od > ev) {
        int j = 0, sum = 0;
        for (int i = 0; i < n; i++) {
          if (a[i] == 1) {
            sum += abs(i - j);
            j += 2;
          }
        }
        cout << sum << endl;
      } else {
        int j = 0, sum = 0;
        for (int i = 0; i < n; i++) {
          if (a[i] == 0) {
            sum += abs(i - j);
            j += 2;
          }
        }
        int k = 0, sum2 = 0;
        for (int i = 0; i < n; i++) {
          if (a[i] == 1) {
            sum2 += abs(i - k);
            k += 2;
          }
        }
        cout << min(sum, sum2) << endl;
      }
    }
  }
}
