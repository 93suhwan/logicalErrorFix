#include <bits/stdc++.h>
using namespace std;
const int M = 17;
const int N = 1e5;
int n, q;
long long a[N];
long long f[2 << M][4];
int ql, qr;
long long g1[4], g2[4], g[4];
void merge(int x, int y, int z) {
  long long tmp = min(g1[x], g2[y]);
  g1[x] -= tmp;
  g2[y] -= tmp;
  g[z] += tmp;
}
void build(int o, int l, int r) {
  if (l == r) {
    if (a[l] > 0) f[o][1] = abs(a[l]);
    if (a[l] < 0) f[o][2] = abs(a[l]);
    return;
  }
  int lc = o << 1, rc = o << 1 | 1, mid = (l + r) / 2;
  build(lc, l, mid);
  build(rc, mid + 1, r);
  for (int i = 0; i < 4; i++) {
    g1[i] = f[lc][i];
    g2[i] = f[rc][i];
    g[i] = 0;
  }
  merge(2, 1, 0);
  merge(2, 0, 2);
  merge(0, 1, 1);
  merge(0, 0, 0);
  merge(3, 3, 3);
  merge(3, 2, 2);
  merge(1, 3, 1);
  merge(1, 2, 0);
  for (int i = 0; i < 4; i++) f[o][i] = g[i] + g1[i] + g2[i];
}
void query(int o, int l, int r) {
  if (ql <= l && r <= qr) {
    for (int i = 0; i < 4; i++) {
      g1[i] = g[i];
      g2[i] = f[o][i];
      g[i] = 0;
    }
    merge(2, 1, 0);
    merge(2, 0, 2);
    merge(0, 1, 1);
    merge(0, 0, 0);
    merge(3, 3, 3);
    merge(3, 2, 2);
    merge(1, 3, 1);
    merge(1, 2, 0);
    for (int i = 0; i < 4; i++) g[i] = g[i] + g1[i] + g2[i];
    return;
  }
  int lc = o << 1, rc = o << 1 | 1, mid = (l + r) / 2;
  if (ql <= mid) query(lc, l, mid);
  if (qr > mid) query(rc, mid + 1, r);
}
int main() {
  cin.tie(0), cout.tie(0);
  ios::sync_with_stdio(false);
  cin >> n >> q;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) {
    long long b;
    cin >> b;
    a[i] = b - a[i];
  }
  build(1, 0, n - 1);
  while (q--) {
    cin >> ql >> qr;
    for (int i = 0; i < 4; i++) g[i] = 0;
    ql--, qr--;
    query(1, 0, n - 1);
    bool flag = true;
    for (int i = 1; i < 4; i++)
      if (g[i] > 0) flag = false;
    if (flag)
      cout << g[0] << '\n';
    else
      cout << "-1\n";
  }
}
