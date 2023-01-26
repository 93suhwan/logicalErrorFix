#include <bits/stdc++.h>
using namespace std;
int n, k, gg, c[1 << 20], uu, mus, C[20][1 << 20], a[1 << 20];
set<int> s;
set<int>::iterator it;
void calc(int f1, int f2) {
  int pos = uu;
  mus = 0;
  for (int i = uu; i < k; ++i) {
    if (((f1 >> i) ^ (f2 >> i)) & 1) {
      pos = i + 1;
    }
  }
  for (int i = pos - 2; i >= uu; --i)
    if (((f1 >> i) ^ (f2 >> i)) & 1) {
      mus |= 1 << i;
    }
  for (int x, i = 0; i < (gg << 1); ++i) {
    x = mus | i;
    C[pos][x] = min(C[pos][x], abs((f1 ^ x) - (f2 ^ x)));
  }
}
void add(int l, int r, int x) {
  it = s.lower_bound(l);
  if (it != s.end()) {
    for (int i = c[*it]; a[i] <= r && i <= n; ++i) {
      if (a[i] != x) calc(a[i], x);
    }
  }
}
int i, mx, j, x, r;
int main() {
  cin >> n >> k;
  for (i = 1; i <= n; ++i) cin >> a[i], s.insert(a[i]);
  sort(a + 1, a + n + 1);
  for (i = 1; i <= n; ++i) c[a[i]] = i;
  mx = ((1 << k) / (n - 1));
  gg = 1;
  while (gg < mx) gg <<= 1, ++uu;
  memset(C, 0x3f, sizeof(C));
  for (i = 1; i < (1 << k); ++i) {
    if (c[i]) {
      x = i & ((1 << k) - gg);
      for (j = c[i] - 1; j && a[j] >= x; --j) {
        calc(a[j], i);
      }
      for (j = uu; j < k; ++j) {
        add((i ^ ((1 << j + 1) - gg)) & x,
            (i ^ ((1 << j + 1) - gg) & x) | (gg - 1), i);
      }
    }
  }
  for (i = 1; i < k; ++i) {
    for (j = 0; j < (1 << i); ++j) {
      C[i + 1][j] = min(C[i + 1][j], C[i][j]);
      C[i + 1][1 << i | j] = min(C[i + 1][1 << i | j], C[i][j]);
    }
  }
  for (j = 0; j < (1 << k); ++j) cout << min(mx, C[i][j]) << " ";
}
