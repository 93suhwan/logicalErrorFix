#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int w, h;
int k1[N], k2[N], k3[N], k4[N];
int K1, K2, K3, K4;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int res1, res2, res3, res4;
    int mx = -0x3f3f3f3f, mn = 0x3f3f3f3f;
    cin >> w >> h;
    cin >> K1;
    for (int i = 1; i <= K1; i++) {
      cin >> k1[i];
      if (k1[i] > mx) mx = k1[i];
      if (k1[i] < mn) mn = k1[i];
    }
    res1 = mx - mn;
    mx = -0x3f3f3f3f, mn = 0x3f3f3f3f;
    cin >> K2;
    for (int i = 1; i <= K2; i++) {
      cin >> k2[i];
      if (k2[i] > mx) mx = k2[i];
      if (k2[i] < mn) mn = k2[i];
    }
    res2 = mx - mn;
    mx = -0x3f3f3f3f, mn = 0x3f3f3f3f;
    cin >> K3;
    for (int i = 1; i <= K3; i++) {
      cin >> k3[i];
      if (k3[i] > mx) mx = k3[i];
      if (k3[i] < mn) mn = k3[i];
    }
    res3 = mx - mn;
    mx = -0x3f3f3f3f, mn = 0x3f3f3f3f;
    cin >> K4;
    for (int i = 1; i <= K4; i++) {
      cin >> k4[i];
      if (k4[i] > mx) mx = k4[i];
      if (k4[i] < mn) mn = k4[i];
    }
    res4 = mx - mn;
    cout << max(max(res1, res2) * h, max(res3, res4) * w) << endl;
  }
  return 0;
}
