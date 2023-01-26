#include <bits/stdc++.h>
using namespace std;
void zanj0() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
void solve() {
  int n, m;
  cin >> n >> m;
  int S = int(0.45 * sqrt(n)) + 1;
  vector<int> v(n), rev_v(n), s_jump(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    v[i]--;
  }
  for (int i = 0; i < n; i++) {
    rev_v[v[i]] = i;
  }
  auto compute_s_jump = [&](int index) -> int {
    int x = index;
    for (int i = 0; i < S; i++) {
      x = v[x];
    }
    return s_jump[index] = x;
  };
  for (int i = 0; i < n; i++) compute_s_jump(i);
  while (m--) {
    int type;
    cin >> type;
    if (type == 2) {
      int x, k;
      cin >> x >> k;
      x--;
      while (S <= k) {
        k -= S;
        x = s_jump[x];
      }
      while (k--) {
        x = v[x];
      }
      cout << x + 1 << "\n";
    } else {
      int x, y;
      cin >> x >> y;
      x--;
      y--;
      swap(rev_v[v[x]], rev_v[v[y]]);
      swap(v[x], v[y]);
      int sx = compute_s_jump(x);
      int sy = compute_s_jump(y);
      for (int i = 0; i < S; i++) {
        s_jump[x] = sx;
        s_jump[y] = sy;
        x = rev_v[x];
        y = rev_v[y];
        sx = rev_v[sx];
        sy = rev_v[sy];
      }
    }
  }
}
int32_t main() {
  zanj0();
  solve();
  cerr << "Time : " << 1000 * (long double)clock() / (long double)CLOCKS_PER_SEC
       << "ms\n";
  return 0;
}
