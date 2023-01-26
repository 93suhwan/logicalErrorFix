#include <bits/stdc++.h>
const int mod = 998244353;
const int modd = 65536;
const int base = 233;
const double pi = acos(-1);
const int N = 2e5 + 10;
const int M = 1e9;
const double esp = 1e-6;
using namespace std;
int id = 0, n, m, tot = 0, ttt = 0, a[1000010];
vector<int> p[100010], ans;
bool vis[100010], pis[8192][8192];
void init() {
  for (int i = 0; i <= 8192; i++) p[i].push_back(0);
  memset(vis, 0, sizeof(vis));
  memset(pis, 0, sizeof(pis));
  vis[0] = 1;
}
int main() {
  int zt, i, j, flat = 0, iz = 0, ip = 0, l, r, ma = 0, mi, x, y, k;
  ios::sync_with_stdio(false);
  cin >> n;
  for (i = 1; i <= n; i++) cin >> a[i];
  init();
  for (i = 1; i <= n; i++) {
    id = a[i];
    for (j = 0; j < p[id].size(); j++) {
      x = p[id][j] ^ id;
      vis[x] = 1;
      for (l = id + 1; l < 520; l++) {
        if (!pis[l][x]) {
          p[l].push_back(x);
          pis[l][x] = 1;
        }
      }
    }
    p[a[i]].clear();
  }
  for (i = 0; i < 8192; i++)
    if (vis[i]) ans.push_back(i);
  cout << ans.size() << endl;
  for (i = 0; i < ans.size(); i++) cout << ans[i] << " ";
  return 0;
}
