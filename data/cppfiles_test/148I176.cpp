#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int w, hh;
    cin >> w >> hh;
    int k1, k2, k3, k4;
    cin >> k1;
    vector<int> xs(k1);
    for (int i = (int)0; i <= (int)k1 - 1; i++) cin >> xs[i];
    cin >> k2;
    vector<int> xs2(k2);
    for (int i = (int)0; i <= (int)k2 - 1; i++) cin >> xs2[i];
    cin >> k3;
    vector<int> ys1(k3);
    for (int i = (int)0; i <= (int)k3 - 1; i++) cin >> ys1[i];
    cin >> k4;
    vector<int> ys2(k4);
    for (int i = (int)0; i <= (int)k4 - 1; i++) cin >> ys2[i];
    int gapHor1 = abs(xs[k1 - 1] - xs[0]);
    int gapHor2 = abs(xs2[k2 - 1] - xs2[0]);
    int gapVer1 = abs(ys1[k3 - 1] - ys1[0]);
    int gapVer2 = abs(ys2[k3 - 1] - ys2[0]);
    long long area1 = 1ll * gapHor1 * hh;
    long long area2 = 1ll * gapHor2 * hh;
    long long area3 = 1ll * gapVer1 * w;
    long long area4 = 1ll * gapVer2 * w;
    cout << max({area1, area2, area3, area4}) << endl;
  }
  return 0;
}
