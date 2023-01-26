#include <bits/stdc++.h>
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N = 1e5, S = 300;
int n, q, p[N], nxt[N], prv[N], jump[N];
void recalc(int v) {
  int last = v, cnt = 0;
  while (cnt++ != S) last = prv[last];
  while (cnt--) {
    jump[last] = v;
    v = nxt[v];
    last = nxt[last];
  }
}
void solveTestCase() {
  cin >> n >> q;
  for (int(i) = 0; (i) < (n); ++(i)) {
    cin >> p[i], p[i]--;
    nxt[i] = p[i];
    prv[p[i]] = i;
  }
  for (int(i) = 0; (i) < (n); ++(i)) recalc(i);
  while (q--) {
    int t, x, y;
    cin >> t >> x >> y;
    if (t == 1) {
      x--, y--;
      nxt[x] = p[y];
      prv[p[y]] = x;
      nxt[y] = p[x];
      prv[p[x]] = y;
      recalc(x);
      recalc(y);
    } else {
      x--;
      int ans = x;
      while (y >= S) y -= S, ans = jump[ans];
      while (y--) ans = nxt[ans];
      cout << ans + 1 << "\n";
    }
  }
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout.precision(18);
  int t = 1;
  while (t--) solveTestCase();
}
