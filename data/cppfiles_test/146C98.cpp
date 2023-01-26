#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("popcnt")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
const int maxn = 1e5 + 11;
const int BLOCK_SIZE = 316;
int n, q, rev[maxn], p[maxn];
int nxt[maxn];
int compute(int i) {
  int cur = i;
  for (int j = 1; j <= BLOCK_SIZE; j++) {
    cur = p[cur];
  }
  return (nxt[i] = cur);
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) {
    cin >> p[i];
    rev[p[i]] = i;
  }
  for (int i = 1; i <= n; ++i) {
    compute(i);
  }
  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int x, y;
      cin >> x >> y;
      swap(rev[p[x]], rev[p[y]]);
      swap(p[x], p[y]);
      int sx = compute(x), sy = compute(y);
      for (int i = 1; i <= BLOCK_SIZE; i++) {
        nxt[x] = sx;
        nxt[y] = sy;
        x = rev[x];
        y = rev[y];
        sx = rev[sx];
        sy = rev[sy];
      }
    } else {
      int i, k;
      cin >> i >> k;
      while (k >= BLOCK_SIZE) {
        i = nxt[i];
        k -= BLOCK_SIZE;
      }
      while (k--) {
        i = p[i];
      }
      cout << i << '\n';
    }
  }
  return 0;
}
