#include <bits/stdc++.h>
using namespace std;
int t[2002][2002];
void inc(int d, int i, int delta, int n) {
  for (; i <= n; i |= i + 1) t[d][i] += delta;
}
int sum(int d, int i) {
  int res = 0;
  for (; i > 0; i = (i & (i + 1)) - 1) res += t[d][i];
  return res;
}
bool isFree(int n, int l, int r) { return sum(n, r) == sum(n, l - 1); }
bool a[1001][1001];
int n, m;
int diagonal(int x, int y) { return (n - x) + y; }
int diagonal_index(int x, int y) {
  int k = diagonal(x, y);
  if (k <= n)
    return y;
  else
    return x;
}
int diagonal_size(int x, int y) {
  int k = diagonal(x, y);
  if (k <= n && k <= m) return k;
  if (k <= max(n, m)) return min(n, m);
  return min(n, m) - (k - max(n, m));
}
int get_past(int x, int y) {
  if (x > n || y > m || a[x][y]) return 0;
  int d = diagonal(x, y);
  int i = diagonal_index(x, y);
  int n = diagonal_size(x, y);
  int l = i, r = n, m;
  while (l != r) {
    m = (l + r + 1) / 2;
    if (isFree(d, i, m))
      l = m;
    else
      r = m - 1;
  }
  return l - i + 1;
}
int get_tepa(int x, int y) {
  if (x < 1 || y < 1 || a[x][y]) return 0;
  int d = diagonal(x, y);
  int i = diagonal_index(x, y);
  int l = 1, r = i, m;
  while (l != r) {
    m = (l + r) / 2;
    if (isFree(d, m, i))
      r = m;
    else
      l = m + 1;
  }
  return i - l + 1;
}
void t_main() {
  long long res = 0;
  int q, x, y;
  cin >> n >> m >> q;
  long long Q, W;
  for (int i = 1; i < n; i++) {
    for (int j = 1; j < m; j++) {
      res += (diagonal_size(i, j) - diagonal_index(i, j) + 1) +
             (diagonal_size(i + 1, j) - diagonal_index(i + 1, j) + 1);
      res += (diagonal_size(i, j) - diagonal_index(i, j) + 1) +
             (diagonal_size(i, j + 1) - diagonal_index(i, j + 1) + 1);
      res--;
    }
  }
  res += (n + m - 2) * 2 + 1;
  int dia, ind, sz, xyp, xyt, xpyp, xymt, xypp, xmyt;
  bool f;
  for (int i = 0; i < q; i++) {
    cin >> x >> y;
    dia = diagonal(x, y);
    ind = diagonal_index(x, y);
    sz = diagonal_size(x, y);
    if (a[x][y]) {
      f = true;
      inc(dia, ind, -1, sz);
      a[x][y] = 0;
    } else
      f = false;
    xyp = get_past(x, y);
    xyt = get_tepa(x, y);
    xpyp = get_past(x + 1, y);
    xymt = get_tepa(x, y - 1);
    xypp = get_past(x, y + 1);
    xmyt = get_tepa(x - 1, y);
    Q = xyp + xpyp;
    Q += (xyt - 1 + xymt) * Q;
    W = xyp + xypp;
    W += (xyt - 1 + xmyt) * W;
    Q = Q + W - 1;
    if (f) {
      res += Q;
    } else {
      a[x][y] = 1;
      inc(dia, ind, 1, sz);
      res -= Q;
    }
    cout << res << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) t_main();
  return 0;
}
