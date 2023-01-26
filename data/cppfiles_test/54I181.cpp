#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 100;
int fa[maxn], col[maxn][2], dis[maxn];
int find(int x) {
  if (fa[x] == x) return x;
  int fn = find(fa[x]);
  dis[x] ^= dis[fa[x]];
  return fa[x] = fn;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    bool f = false;
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
      fa[i] = i;
      dis[i] = 0;
      col[i][0] = 1;
      col[i][1] = 0;
    }
    for (int i = 1; i <= m; i++) {
      int x, y, val;
      string s;
      cin >> x >> y >> s;
      if (s[0] == 'i')
        val = 1;
      else
        val = 0;
      int px = find(x), py = find(y);
      if (px == py) {
        if (dis[x] ^ dis[y] != val) {
          f = true;
          break;
        }
      } else {
        fa[py] = px;
        dis[py] = dis[x] ^ dis[y] ^ val;
        col[px][1] += col[py][dis[py] ^ 1];
        col[px][0] += col[py][dis[py]];
      }
    }
    if (f) {
      puts("-1");
      continue;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      if (find(i) == i) {
        ans += max(col[i][0], col[i][1]);
      }
    }
    cout << ans << endl;
  }
  return 0;
}
