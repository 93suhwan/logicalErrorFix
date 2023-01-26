#include <bits/stdc++.h>
using namespace std;
struct H {
  int x, y, z;
} e[200004];
int k, m, n, t, v, x, y, z, p[400005];
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
void P(int x, int y, int k) {
  if (k) {
    U(x, n + y);
    U(y, n + x);
  } else {
    U(x, y);
    U(n + x, n + y);
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  for (cin >> t; t--;) {
    cin >> n >> m;
    iota(p, p + n + n + 1, 0);
    for (int i = 0; i < n - 1; i++) {
      cin >> x >> y >> z;
      e[i] = {x, y, z};
      if (~z) P(x, y, f(z));
    }
    for (int i = 0; i < m; i++) {
      cin >> x >> y >> z;
      P(x, y, z);
    }
    v = 1;
    for (int i = 1; i <= n; i++) {
      if (F(i) == F(n + i)) v = 0;
    }
    for (int i = 0; i < n - 1; i++) {
      if (e[i].z == -1) P(e[i].x, e[i].y, e[i].z = F(e[i].x) != F(e[i].y));
    }
    if (v) {
      cout << "YES" << '\n';
      for (int i = 0; i < n - 1; i++)
        cout << e[i].x << " " << e[i].y << " " << e[i].z << '\n';
    } else
      cout << "NO" << '\n';
  }
}
