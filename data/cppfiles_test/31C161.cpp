#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;
    vector<long long int> a(n);
    for (int j = 0; j < n; j++) {
      cin >> a[j];
    }
    vector<long long int> b(n);
    if (n % 2 == 0) {
      for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
          b[i] = -a[i + 1];
        } else {
          b[i] = a[i - 1];
        }
      }
    } else {
      if (n >= 3) {
        if (a[1] + a[2] != 0) {
          b[0] = -(a[1] + a[2]);
          b[1] = a[0];
          b[2] = a[0];
        } else if (a[1] + a[0] != 0) {
          b[2] = -(a[1] + a[0]);
          b[1] = a[2];
          b[0] = a[2];
        } else if (a[0] + a[2] != 0) {
          b[1] = -(a[0] + a[2]);
          b[0] = a[1];
          b[2] = a[1];
        }
        for (int i = 3; i < n; i++) {
          if (i % 2 != 0) {
            b[i] = -a[i + 1];
          } else {
            b[i] = a[i - 1];
          }
        }
      }
    }
    for (int i = 0; i < n; i++) {
      cout << b[i] << " ";
    }
    cout << endl;
  }
}
