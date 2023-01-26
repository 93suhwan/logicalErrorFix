#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 1000006;
int n, m, qq;
int q[6];
void solv() {
  cin >> n >> m >> qq;
  map<pair<int, int>, int> mp;
  while (qq--) {
    int x, y, z;
    cin >> x >> y >> z;
    if (mp.find(make_pair(x, y)) != mp.end()) {
      int u = mp[make_pair(x, y)];
      if ((x + y) % 2 == u) --q[0];
      if ((x + y) % 2 != u) --q[1];
      if (x % 2 == u) --q[2];
      if (x % 2 != u) --q[3];
      if (y % 2 == u) --q[4];
      if (y % 2 != u) --q[5];
    }
    if (z == -1) {
      if (mp.find(make_pair(x, y)) != mp.end()) mp.erase(make_pair(x, y));
    } else
      mp[make_pair(x, y)] = z;
    if (mp.find(make_pair(x, y)) != mp.end()) {
      int u = mp[make_pair(x, y)];
      if ((x + y) % 2 == u) ++q[0];
      if ((x + y) % 2 != u) ++q[1];
      if (x % 2 == u) ++q[2];
      if (x % 2 != u) ++q[3];
      if (y % 2 == u) ++q[4];
      if (y % 2 != u) ++q[5];
    }
    int ans = 0;
    for (int i = 0; i < 6; ++i) ans += (q[i] == 0);
    cout << ans << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);
  int tt = 1;
  while (tt--) solv();
  return 0;
}
