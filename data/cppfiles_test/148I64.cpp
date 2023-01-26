#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 10;
long long w, h;
long long k1[N], k2[N], k3[N], k4[N];
long long K1, K2, K3, K4;
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    long long res1, res2, res3, res4;
    long long mx = -0x3f3f3f3f, mn = 0x3f3f3f3f;
    cin >> w >> h;
    cin >> K1;
    for (long long i = 1; i <= K1; i++) {
      cin >> k1[i];
      if (k1[i] > mx) mx = k1[i];
      if (k1[i] < mn) mn = k1[i];
    }
    res1 = mx - mn;
    mx = -0x3f3f3f3f, mn = 0x3f3f3f3f;
    cin >> K2;
    for (long long i = 1; i <= K2; i++) {
      cin >> k2[i];
      if (k2[i] > mx) mx = k2[i];
      if (k2[i] < mn) mn = k2[i];
    }
    res2 = mx - mn;
    mx = -0x3f3f3f3f, mn = 0x3f3f3f3f;
    cin >> K3;
    for (long long i = 1; i <= K3; i++) {
      cin >> k3[i];
      if (k3[i] > mx) mx = k3[i];
      if (k3[i] < mn) mn = k3[i];
    }
    res3 = mx - mn;
    mx = -0x3f3f3f3f, mn = 0x3f3f3f3f;
    cin >> K4;
    for (long long i = 1; i <= K4; i++) {
      cin >> k4[i];
      if (k4[i] > mx) mx = k4[i];
      if (k4[i] < mn) mn = k4[i];
    }
    res4 = mx - mn;
    long long num = max((res1, res2) * h, max(res3, res4) * w);
    cout << num << endl;
  }
  return 0;
}
