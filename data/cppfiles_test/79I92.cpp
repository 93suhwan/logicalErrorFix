#include <bits/stdc++.h>
const int Inf = 1e9;
using namespace std;
inline int read(void) {
  register int x = 0, sgn = 1, ch = getchar();
  while (ch < 48 || 57 < ch) {
    if (ch == 45) sgn = 0;
    ch = getchar();
  }
  while (47 < ch && ch < 58) {
    x = x * 10 + ch - 48;
    ch = getchar();
  }
  return sgn ? x : -x;
}
void write(int x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
int n;
int a[300005];
int b[300005];
vector<int> frm[300005];
pair<int, int> Min[1200005];
pair<int, int> dp[300005];
const pair<int, int> Imp = make_pair(Inf, -1);
pair<int, int> qry(int p, int l, int r, int nl, int nr) {
  if (r < nl || nr < l) return Imp;
  if (l <= nl && nr <= r) return Min[p];
  int mid = (nl + nr) / 2;
  return min(qry(p << 1, l, r, nl, mid), qry(p << 1 | 1, l, r, mid + 1, nr));
}
void upd(int p, int v, pair<int, int> x, int nl, int nr) {
  if (v < nl || nr < v) return;
  Min[p] = min(Min[p], x);
  int mid = (nl + nr) / 2;
  if (nl != nr) {
    upd(p << 1, v, x, nl, mid);
    upd(p << 1 | 1, v, x, mid + 1, nr);
  }
  return;
}
signed main() {
  n = read();
  for (int i = 1; i <= n; ++i) a[i] = i - read();
  for (int i = 1; i <= n; ++i) b[i] = read() + i;
  for (int i = 1; i <= n; ++i) {
    frm[b[i]].push_back(i);
  }
  for (int i = 1; i <= 1200000; ++i) Min[i] = Imp;
  upd(1, 0, make_pair(0, 0), 0, n);
  for (int i = 1; i <= n; ++i) {
    pair<int, int> mi = qry(1, a[i], i, 0, n);
    mi.first++;
    dp[i] = mi;
    for (int F : frm[i]) {
      upd(1, F, make_pair(mi.first, F), 0, n);
    }
  }
  if (dp[n].first < Inf) {
    write(dp[n].first);
    puts("");
    int p = dp[n].second;
    while (p > 0) {
      write(p);
      putchar(' ');
      p = dp[b[p]].second;
    }
    puts("0");
  } else {
    puts("-1");
  }
  return 0;
}
