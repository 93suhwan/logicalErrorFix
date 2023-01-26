#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("popcnt")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
const int maxn = 1e5 + 11;
const int BLOCK_SIZE = 350;
int n, q, a[maxn];
int nxt[maxn], par[maxn];
void upd(int i) {
  i = par[i];
  int cur = i;
  for (int j = 1; j <= BLOCK_SIZE; j++) {
    cur = a[cur];
    par[cur] = i;
  }
  nxt[i] = a[cur];
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; ++i) {
    if (par[i] != 0) continue;
    par[i] = i;
    int cur = i;
    for (int j = 1; j <= BLOCK_SIZE; j++) {
      cur = a[cur];
      par[cur] = i;
    }
    nxt[i] = a[cur];
  }
  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int x, y;
      cin >> x >> y;
      swap(a[x], a[y]);
      upd(x);
      upd(y);
      upd(a[x]);
      upd(a[y]);
    } else {
      int i, k;
      cin >> i >> k;
      upd(i);
      while (k > 0 && i != par[i]) {
        i = a[i];
        k--;
      }
      while (k >= BLOCK_SIZE) {
        i = nxt[i];
        k -= BLOCK_SIZE;
      }
      while (k--) {
        i = a[i];
      }
      cout << i << '\n';
    }
  }
  return 0;
}
