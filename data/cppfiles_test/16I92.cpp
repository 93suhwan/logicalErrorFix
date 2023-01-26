#include <bits/stdc++.h>
const unsigned int MOD = 1000000007;
const long double r = 1e+9;
using namespace std;
int main() {
  int q;
  cin >> q;
  while (q--) {
    int n;
    cin >> n;
    int a1[n + 1], a2[n + 1], a3[n + 1], a4[n + 1], a5[n + 1];
    for (int i = 1; i < n + 1; i++) {
      int x1, x2, x3, x4, x5;
      cin >> x1 >> x2 >> x3 >> x4 >> x5;
      a1[i] = x1;
      a2[i] = x2;
      a3[i] = x3;
      a4[i] = x4;
      a5[i] = x5;
    }
    if (n == 1) {
      cout << 1 << endl;
      continue;
    }
    int v[6] = {0};
    int k1 = INT_MAX;
    int k2 = INT_MAX;
    int k3 = INT_MAX;
    int k4 = INT_MAX;
    int k5 = INT_MAX;
    for (int i = 1; i < n + 1; i++) {
      int j1 = k1;
      int j2 = k2;
      int j3 = k3;
      int j4 = k4;
      int j5 = k5;
      k1 = min(k1, a1[i]);
      if (k1 < j1) {
        v[1] = i;
      }
      k2 = min(k2, a2[i]);
      if (k2 < j2) {
        v[2] = i;
      }
      k3 = min(k3, a3[i]);
      if (k3 < j3) {
        v[3] = i;
      }
      k4 = min(k4, a4[i]);
      if (k4 < j4) {
        v[4] = i;
      }
      k5 = min(k5, a5[i]);
      if (k5 < j5) {
        v[5] = i;
      }
    }
    int p = 0;
    int z = 0;
    int x = 0;
    for (int j = 1; j < 6; j++) {
      z = 0;
      for (int i = 1; i < n + 1; i++) {
        x = 0;
        if (i != v[j]) {
          if (a1[v[j]] < a1[i]) {
            x++;
          }
          if (a2[v[j]] < a2[i]) {
            x++;
          }
          if (a3[v[j]] < a3[i]) {
            x++;
          }
          if (a4[v[j]] < a4[i]) {
            x++;
          }
          if (a5[v[j]] < a5[i]) {
            x++;
          }
          if (x >= 3) {
            z++;
          }
        }
      }
      if (z == n - 1) {
        p = 1;
        cout << v[j] << endl;
        break;
      }
    }
    if (p == 0) {
      cout << -1 << endl;
    }
  }
}
