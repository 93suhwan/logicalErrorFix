#include <bits/stdc++.h>
using namespace std;
int fun(int, int, int);
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, i;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> d(n + 1, -1);
    for (i = 1; i <= n - 2; i += 3) {
      a[i] = fun(i, i + 1, i + 2);
    }
    int iFalse, iTure;
    for (i = 1; i + 5 <= n; i += 3) {
      if (a[i] != a[i + 3]) {
        a[i + 1] = fun(i + 1, i + 2, i + 3);
        a[i + 2] = fun(i + 2, i + 3, i + 4);
        for (int j = i; j < i + 3; j++) {
          if (a[j] != a[j + 1]) {
            if (a[j] == 0) {
              iFalse = j;
              iTure = j + 3;
              d[j] = 0;
              d[j + 3] = 1;
            } else {
              iTure = j;
              iFalse = j + 3;
              d[j] = 1;
              d[j + 3] = 0;
            }
          }
        }
        break;
      }
    }
    for (i = 1; i <= n - 2; i += 3) {
      if (a[i] == 0) {
        if (fun(i, i + 1, iTure) == 1) {
          if (fun(i, iTure, iFalse) == 0)
            d[i] = 0, d[i + 1] = 1;
          else
            d[i] = 1, d[i + 1] = 0;
          d[i + 2] = 0;
        } else {
          d[i] = 0;
          d[i + 1] = 0;
          d[i + 2] = fun(i + 2, iTure, iFalse);
        }
      } else {
        if (fun(i, i + 1, iTure) == 0) {
          if (fun(i + 1, iTure, iFalse) == 0)
            d[i] = 0, d[i + 1] = 1;
          else
            d[i] = 1, d[i + 1] = 0;
          d[i + 2] = 1;
        } else {
          d[i] = d[i + 1] = 1;
          d[i + 2] = fun(i + 2, iTure, iFalse);
        }
      }
    }
    cout << "! ";
    cout << count(d.begin(), d.end(), 0);
    for (i = 1; i <= n; i++) {
      if (d[i] == 0) cout << " " << i;
    }
    cout << endl;
  }
  return 0;
}
int fun(int a, int b, int c) {
  int d;
  cout << "? " << a << ' ' << b << ' ' << c << endl;
  cin >> d;
  return d;
}
