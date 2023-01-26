#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long w, h;
    cin >> w >> h;
    int k1, k2, k3, k4;
    cin >> k1;
    int* a1 = new int[k1];
    long long wmax, hmax, areaw, areah;
    for (int i = 0; i < k1; i++) {
      cin >> a1[i];
    }
    wmax = a1[k1 - 1] - a1[0];
    cin >> k2;
    int* a2 = new int[k2];
    for (int i = 0; i < k2; i++) {
      cin >> a2[i];
    }
    if (wmax < (a2[k2 - 1] - a2[0])) wmax = a2[k2 - 1] - a2[0];
    cin >> k3;
    int* a3 = new int[k3];
    for (int i = 0; i < k3; i++) {
      cin >> a3[i];
    }
    hmax = a3[k3 - 1] - a3[0];
    cin >> k4;
    int* a4 = new int[k4];
    for (int i = 0; i < k4; i++) {
      cin >> a4[i];
    }
    if (hmax < (a4[k4 - 1] - a4[0])) hmax = a4[k4 - 1] - a4[0];
    areaw = wmax * h;
    areah = hmax * w;
    if (areaw > areah)
      cout << areaw << endl;
    else
      cout << areah << endl;
  }
}
