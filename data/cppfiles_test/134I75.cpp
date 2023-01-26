#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int res_even = a[0];
    for (int i = 1; i < n; i++) {
      if (i % 2 == 0) {
        res_even = gcd(res_even, a[i]);
      }
    }
    int res_odd = a[1];
    for (int i = 2; i < n; i++) {
      if (i % 2 != 0) {
        res_odd = gcd(res_odd, a[i]);
      }
    }
    if (res_odd == res_even || (res_odd == 1 && res_even == 1)) {
      cout << 0 << endl;
    } else {
      int ans = 0;
      bool odd = true;
      bool even = true;
      if (res_odd == 1) {
        for (int i = 0; i < n; i++) {
          if (i % 2 != 0) {
            if (gcd(res_even, a[i]) != 1) {
              even = false;
            }
          }
        }
        if (even) {
          cout << res_even << endl;
        } else {
          cout << 0 << endl;
        }
      } else if (res_even == 1) {
        for (int i = 0; i < n; i++) {
          if (i % 2 == 0) {
            if (gcd(res_odd, a[i]) != 1) {
              odd = false;
            }
          }
        }
        if (odd) {
          cout << res_odd << endl;
        } else {
          cout << 0 << endl;
        }
      } else {
        for (int i = 0; i < n; i++) {
          if (i % 2 == 0) {
            if (gcd(res_odd, a[i]) != 1) {
              odd = false;
            } else {
              if (gcd(res_even, a[i]) != 1) {
                even = false;
              }
            }
          }
        }
        if (odd) {
          cout << res_odd << endl;
        } else if (even) {
          cout << res_even << endl;
        } else {
          cout << 0 << endl;
        }
      }
    }
  }
}
