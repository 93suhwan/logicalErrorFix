#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int arr[n];
    long long int b[n];
    long long int o = 0, e = 0;
    for (long long int i = 0; i < n; i++) {
      cin >> arr[i];
      if (arr[i] % 2 == 0) {
        b[i] = 1;
        e++;
      } else {
        o++;
        b[i] = 0;
      }
    }
    if (n % 2 == 0) {
      if (e != o) {
        cout << -1 << endl;
      } else {
        if (b[0] == 1) {
          long long int d = 0;
          long long int ans = 0;
          for (long long int i = 1; i < n; i++) {
            if (i % 2 == 0 && b[i] == 1) {
              ans += d;
            }
            if (i % 2 == 0 && b[i] == 0) {
              d--;
              ans += d;
            }
            if (i % 2 != 0 && b[i] == 0) {
              ans += d;
            }
            if (i % 2 != 0 && b[i] == 1) {
              d++;
              ans += d;
            }
          }
          cout << abs(ans) << endl;
        }
        if (b[0] == 0) {
          long long int p = 0;
          long long int ans1 = 0;
          for (long long int i = 1; i < n; i++) {
            if (i % 2 == 0 && b[i] == 0) {
              ans1 += p;
            }
            if (i % 2 == 0 && b[i] == 1) {
              p--;
              ans1 += p;
            }
            if (i % 2 != 0 && b[i] == 1) {
              ans1 += p;
            }
            if (i % 2 != 0 && b[i] == 0) {
              p++;
              ans1 += p;
            }
          }
          cout << abs(ans1) << endl;
        }
      }
    }
    if (n % 2 != 0) {
      if (abs(o - e) > 1) {
        cout << -1 << endl;
      } else {
        long long int q = 0, ans2 = 0;
        if (b[0] == 0) {
          for (long long int i = 1; i < n; i++) {
            if (i % 2 == 0 && b[i] == 0) {
              ans2 += q;
            }
            if (i % 2 == 0 && b[i] == 1) {
              q--;
              ans2 += q;
            }
            if (i % 2 != 0 && b[i] == 1) {
              ans2 += q;
            }
            if (i % 2 != 0 && b[i] == 0) {
              q++;
              ans2 += q;
            }
          }
          cout << abs(ans2) << endl;
        } else {
          for (long long int i = 1; i < n; i++) {
            if (i % 2 == 0 && b[i] == 1) {
              ans2 += q;
            }
            if (i % 2 == 0 && b[i] == 0) {
              q--;
              ans2 += q;
            }
            if (i % 2 != 0 && b[i] == 0) {
              ans2 += q;
            }
            if (i % 2 != 0 && b[i] == 1) {
              q++;
              ans2 += q;
            }
          }
          cout << abs(ans2) << endl;
        }
      }
    }
  }
}
