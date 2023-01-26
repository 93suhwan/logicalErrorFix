#include <bits/stdc++.h>
using namespace std;
const int MK = 20, MN = 1 << MK, INF = 0x3f3f3f3f;
int N, K, M;
struct node {
  int mn, mx, ans;
  node(int mn = -1, int mx = -1, int ans = INF) : mn(mn), mx(mx), ans(ans) {}
  operator bool() { return mn > -1; }
} tree[MK][MN];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> K;
  M = 1 << K;
  for (int i = 0, x; i < N; i++) {
    cin >> x;
    tree[0][x] = {x, x, INF};
  }
  for (int lv = 1, sz, psz; sz = 1 << lv, psz = sz >> 1, lv <= K; lv++) {
    for (int i = 0; i < M; i += sz) {
      for (int bit = 0; bit < psz; ++bit) {
        node a = tree[lv - 1][i | bit], b = tree[lv - 1][i | psz | bit],
             &cur0 = tree[lv][i | bit], &cur1 = tree[lv][i | psz | bit];
        if (a && b) {
          cur0 = {a.mn, b.mx, min(b.mn - a.mx, min(a.ans, b.ans))};
          cur1 = {b.mn ^ psz, a.mx ^ psz,
                  min(sz - b.mx + a.mn, min(a.ans, b.ans))};
        } else {
          cur0 = a ? a : b;
          cur1 = cur0 ? node(cur0.mn ^ psz, cur0.mx ^ psz, cur0.ans) : cur0;
        }
      }
    }
  }
  for (int bit = 0; bit < M; ++bit) {
    printf("%d%c", tree[K][bit].ans, " \n"[bit == M - 1]);
  }
  return 0;
}
