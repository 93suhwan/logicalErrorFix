#include <bits/stdc++.h>
using namespace std;
int main() {
  long long tc, n, w, h, x, y, temp, flag, cnt, res;
  cin >> tc;
  while (tc--) {
    cin >> w >> h;
    cin >> n;
    vector<long long> vc1, vc2, vc3, vc4;
    for (long long i = 0; i < n; i++) cin >> temp, vc1.push_back(temp);
    cin >> n;
    for (long long i = 0; i < n; i++) cin >> temp, vc2.push_back(temp);
    res = -1;
    x = vc1[0], y = vc1[vc1.size() - 1];
    res = max(res, (y - x) * h);
    x = vc2[0], y = vc2[vc2.size() - 1];
    res = max(res, (y - x) * h);
    cin >> n;
    for (long long i = 0; i < n; i++) cin >> temp, vc3.push_back(temp);
    cin >> n;
    for (long long i = 0; i < n; i++) cin >> temp, vc4.push_back(temp);
    x = vc3[0], y = vc3[vc3.size() - 1];
    res = max(res, (y - x) * w);
    x = vc4[0], y = vc4[vc4.size() - 1];
    res = max(res, (y - x) * w);
    cout << res << endl;
  }
  return 0;
}
