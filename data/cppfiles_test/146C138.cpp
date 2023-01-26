#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
using namespace std;
int way[100005][9];
int mem[(1 << (9 + 2))];
int p[100005];
int rev[100005];
void upd(int x) {
  int grv = (1 << (9 + 1));
  int tg = x;
  for (int i = 0; i <= (1 << (9 - 1)); i++) {
    mem[grv + i] = tg;
    tg = p[tg];
  }
  tg = x;
  for (int i = 0; i <= (1 << (9 - 1)); i++) {
    for (int j = 0; j < 9; j++) {
      way[tg][j] = mem[grv + (1 << j)];
    }
    tg = rev[tg];
    grv--;
    mem[grv] = tg;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q;
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    p[i]--;
    rev[p[i]] = i;
  }
  for (int i = 0; i < n; i++) {
    int tg = i, np = 0;
    for (int j = 1; j <= (1 << (9 - 1)); j++) {
      tg = p[tg];
      if (j == (1 << np)) {
        way[i][np] = tg;
        np++;
      }
    }
  }
  while (q > 0) {
    q--;
    int t, x, y;
    cin >> t >> x >> y;
    if (t == 1) {
      x--;
      y--;
      swap(p[x], p[y]);
      rev[p[x]] = x;
      rev[p[y]] = y;
      upd(x);
      upd(y);
    } else {
      x--;
      int res = x;
      int cp = 9 - 1;
      while (y > 0) {
        while (y < (1 << cp)) {
          cp--;
        }
        y -= (1 << cp);
        res = way[res][cp];
      }
      cout << res + 1 << '\n';
    }
  }
  return 0;
}
