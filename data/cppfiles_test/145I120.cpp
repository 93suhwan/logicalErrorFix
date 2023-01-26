#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e5;
struct Mine {
  int x, y, time;
};
map<pair<int, int>, bool> vis;
Mine m[MAXN];
int n, k, cnt = 0;
void explode(int x, int y) {
  vis[{x, y}] = true;
  ++cnt;
  for (int i = 0; i < n; ++i) {
    if ((m[i].x == x && abs(y - m[i].y) <= k) ||
        (m[i].y == y && abs(m[i].x - x) <= k)) {
      if (!vis[{m[i].x, m[i].y}]) explode(m[i].x, m[i].y);
    }
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    vis.clear();
    cnt = 0;
    for (int i = 0; i < n; ++i) {
      int x, y, time;
      cin >> x >> y >> time;
      m[i] = Mine{x, y, time};
    }
    int ct = 0;
    for (ct = 0; cnt < n && ct < n; ++ct) {
      Mine mx = Mine{0, 0, -1};
      for (int i = 0; i < n; ++i) {
        if (!vis[{m[i].x, m[i].y}]) {
          if (m[i].time <= ct)
            explode(m[i].x, m[i].y);
          else {
            if (mx.time < m[i].time) mx = m[i];
          }
        }
      }
      if (mx.time != -1) explode(mx.x, mx.y);
      if (cnt == n) break;
    }
    cout << ct << endl;
  }
}
