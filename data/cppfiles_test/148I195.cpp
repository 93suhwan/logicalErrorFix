#include <bits/stdc++.h>
using namespace std;
int w, h, k1, k2, k3, k4;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int Tests;
  cin >> Tests;
  while (Tests--) {
    cin >> w >> h;
    cin >> k1;
    vector<int> v(k1);
    for (int i = 0; i < k1; ++i) cin >> v[i];
    cin >> k2;
    vector<int> v2(k2);
    for (int i = 0; i < k2; ++i) cin >> v2[i];
    cin >> k3;
    vector<int> vv(k3);
    for (int i = 0; i < k3; ++i) cin >> vv[i];
    cin >> k4;
    vector<int> vv2(k4);
    for (int i = 0; i < k4; ++i) cin >> vv2[i];
    cout << (max(v[k1 - 1] - v[0], v2[k2 - 1] - v2[0]) * h,
             max(vv[k3 - 1] - vv[0], vv2[k4 - 1] - vv2[0]) * w);
    cout << '\n';
  }
  return 0;
}
