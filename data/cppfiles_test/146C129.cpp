#include <bits/stdc++.h>
using namespace std;
const int k = 316;
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int n, q;
  cin >> n >> q;
  vector<int> p(n), b(n), jump(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
    b[--p[i]] = i;
  }
  for (int i = 0; i < n; ++i) {
    jump[i] = i;
    for (int j = 0; j < k; ++j) jump[i] = p[jump[i]];
  }
  for (int i = 0; i < q; ++i) {
    int t, x, y;
    cin >> t >> x >> y;
    if (t == 1) {
      x--;
      y--;
      swap(p[x], p[y]);
      b[p[x]] = x;
      b[p[y]] = y;
      swap(jump[x], jump[y]);
      int bx = x, by = y;
      for (int j = 0; j < k - 1; ++j) {
        bx = b[bx];
        by = b[by];
      }
      int fx = p[x], fy = p[y];
      for (int j = 0; j < k - 1; ++j) {
        jump[bx] = fx;
        jump[by] = fy;
        fx = p[fx];
        fy = p[fy];
        bx = p[bx];
        by = p[by];
      }
    } else {
      x--;
      while (k <= y) x = jump[x], y -= k;
      for (int j = 0; j < y; ++j) x = p[x];
      cout << x + 1 << "\n";
    }
  }
}
