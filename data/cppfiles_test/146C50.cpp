#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, q;
  cin >> n >> q;
  int m = sqrt(n);
  vector<int> par(n + 1), ch(n + 1);
  vector<int> jmp(n + 1);
  for (int i = 1; i <= n; i++) cin >> par[i];
  for (int i = 1; i <= n; i++) ch[par[i]] = i;
  for (int i = 1; i <= n; i++) {
    int x = i;
    for (int j = 0; j < m; j++) x = par[x];
    jmp[i] = x;
  }
  while (q--) {
    int t, x, y;
    cin >> t >> x >> y;
    if (t == 2) {
      for (int i = 0; i < y / m; i++) x = jmp[x];
      for (int i = 0; i < y % m; i++) x = par[x];
      cout << x << '\n';
    } else {
      swap(ch[par[x]], ch[par[y]]);
      swap(par[x], par[y]);
      int xx = x;
      int yy = y;
      for (int i = 0; i < m; i++) {
        x = ch[x];
        y = ch[y];
      }
      for (int i = 0; i < m + 1; i++) {
        jmp[x] = xx;
        x = par[x];
        xx = par[xx];
        jmp[y] = yy;
        y = par[y];
        yy = par[yy];
      }
    }
  }
}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  while (t--) {
    solve();
  }
}
