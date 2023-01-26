#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int main() {
  auto ask = [&](int x, int y) {
    static map<pair<int, int>, int> mp;
    if (mp.count({x, y})) return mp[{x, y}];
    cout << "? " << x << " " << y << endl;
    int z;
    cin >> z;
    return mp[{x, y}] = z;
  };
  int l = 1, r = INF;
  int mn = INT_MAX, pos = 0;
  while (l <= r) {
    int m1 = l + (r - l) / 3, m2 = r - (r - l) / 3;
    int y1 = ask(1, m1), y2 = ask(1, m2);
    if (y1 < mn) mn = y1, pos = m1;
    if (y2 < mn) mn = y2, pos = m2;
    if (ask(1, m1) < ask(1, m2))
      r = m2 - 1;
    else
      l = m1 + 1;
  }
  int x1 = 1 + mn;
  int y1 = 1 + (ask(1, 1) - mn);
  int y2 = INF - (ask(1, INF) - mn);
  int x2 = ask(INF, 1) - (y1 - 1) + 1;
  cout << "! " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
  return 0;
}
