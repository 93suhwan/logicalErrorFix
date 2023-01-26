#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5, INF = 0x3f3f3f3f;
int h[maxn], t[maxn], e[maxn], ne[maxn], cur, idx;
int ans[maxn];
int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);
  memset(h, -1, sizeof h);
  memset(ne, -1, sizeof ne);
  int n;
  cin >> n;
  while (n--) {
    int op, x, y;
    cin >> op;
    if (op == 1) {
      cin >> x;
      e[idx] = ++cur;
      if (h[x] == -1) {
        h[x] = idx;
        t[idx] = idx;
      } else {
        ne[t[h[x]]] = idx;
        t[h[x]] = idx;
      }
      ++idx;
    } else {
      cin >> x >> y;
      if (x == y || h[x] == -1)
        continue;
      else if (h[y] == -1)
        h[y] = h[x];
      else {
        ne[t[h[y]]] = h[x];
        t[h[y]] = t[h[x]];
      }
      h[x] = -1;
    }
  }
  for (int x = 1; x <= 500000; x++) {
    for (int i = h[x]; ~i; i = ne[i]) ans[e[i]] = x;
  }
  for (int i = 1; i <= idx; i++) cout << ans[i] << ' ';
  cout << '\n';
}
