#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q;
  cin >> n >> q;
  int JUMP = int(0.445 * sqrt(n)) + 1;
  vector<int> p(n + 1), p_rev(n + 1), p_jump(n + 1);
  auto compute_p_jump = [&](int u) -> int {
    int steps = JUMP;
    while (steps--) u = p[u];
    return u;
  };
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
    p_rev[p[i]] = i;
  }
  for (int i = 1; i <= n; i++) {
    p_jump[i] = compute_p_jump(i);
  }
  while (q--) {
    int op;
    cin >> op;
    if (op == 1) {
      int x, y;
      cin >> x >> y;
      swap(p[x], p[y]);
      swap(p_rev[p[x]], p_rev[p[y]]);
      int px = compute_p_jump(x);
      int py = compute_p_jump(y);
      for (int i = 0; i < JUMP; i++) {
        p_jump[x] = px;
        p_jump[y] = py;
        x = p_rev[x];
        y = p_rev[y];
        px = p_rev[px];
        py = p_rev[py];
      }
    } else {
      int id, k;
      cin >> id >> k;
      while (k >= JUMP) {
        id = p_jump[id];
        k -= JUMP;
      }
      while (k--) {
        id = p[id];
      }
      cout << id << "\n";
    }
  }
  return 0;
}
