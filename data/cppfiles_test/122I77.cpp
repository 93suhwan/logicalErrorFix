#include <bits/stdc++.h>
using namespace std;
struct H {
  int x, y, z;
} e[200004];
int k, m, n, t, v, x, y, z, o[200004], p[200004];
int f(int x) {
  for (; x > 1;) x = (x & 1) ^ (x >> 1);
  return x;
}
int F(int x) {
  if (x != p[x]) return p[x] = F(p[x]);
  return x;
}
int U(int x, int y) {
  if (x != p[x] || y != p[y]) return p[x] = p[y] = U(p[x], p[y]);
  return p[y] = x;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  for (cin >> t; t--;) {
    cin >> n >> m;
    fill(o, o + n + 1, 0);
    iota(p, p + n + 1, 0);
    v = 1;
    for (int i = 0; i < n - 1; i++) {
      cin >> x >> y >> z;
      e[i] = {x, y, z};
      if (~z) {
        k = f(z);
        if (k) {
          if (!o[x]) o[x] = y;
          if (!o[y]) o[y] = x;
          U(x, o[y]);
          U(y, o[x]);
        } else {
          U(x, y);
          if (o[x] && !o[y]) o[y] = o[x];
          if (!o[x] && o[y]) o[x] = o[y];
          U(o[x], o[y]);
        }
      }
    }
    for (int i = 0; i < m; i++) {
      cin >> x >> y >> z;
      if (z) {
        if (!o[x]) o[x] = y;
        if (!o[y]) o[y] = x;
        U(x, o[y]);
        U(y, o[x]);
      } else {
        U(x, y);
        if (o[x] && !o[y]) o[y] = o[x];
        if (!o[x] && o[y]) o[x] = o[y];
        U(o[x], o[y]);
      }
    }
    for (int i = 0; i < n - 1; i++) {
      if (e[i].z == -1) {
        x = e[i].x;
        y = e[i].y;
        if (F(x) == F(y)) {
          e[i].z = 0;
          U(x, y);
          if (o[x] && !o[y]) o[y] = o[x];
          if (!o[x] && o[y]) o[x] = o[y];
          U(o[x], o[y]);
        } else {
          e[i].z = 1;
          if (!o[x]) o[x] = y;
          if (!o[y]) o[y] = x;
          U(x, o[y]);
          U(y, o[x]);
        }
      }
    }
    for (int i = 1; i <= n; i++) {
      if (F(i) == F(o[i])) v = 0;
    }
    if (v) {
      cout << "YES" << '\n';
      for (int i = 0; i < n - 1; i++)
        cout << e[i].x << " " << e[i].y << " " << e[i].z << '\n';
    } else
      cout << "NO" << '\n';
  }
}
