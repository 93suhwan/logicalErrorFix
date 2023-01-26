#include <bits/stdc++.h>
#pragma comment(linker, "/stack:1000000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
using namespace std;
const int N = int(1e5) + 2, mod = int(1e9) + 7;
int n, k;
int c[N];
vector<pair<int, int> > g[N];
long long cnt[N], d[N][21];
long long t[4 * N], add[4 * N], keep[4 * N];
inline void scanint(int &x) {
  register int c = getchar();
  x = 0;
  int neg = 0;
  for (; ((c < 48 || c > 57) && c != '-'); c = getchar())
    ;
  if (c == '-') {
    neg = 1;
    c = getchar();
  }
  for (; c > 47 && c < 58; c = getchar()) {
    x = (x << 1) + (x << 3) + c - 48;
  }
  if (neg) x = -x;
}
void inc(int v, long long x) {
  t[v] += x;
  keep[v] += x;
}
void push(int v) {
  if (keep[v] == 0) return;
  inc(v + v, keep[v]);
  inc(v + v + 1, keep[v]);
  keep[v] = 0;
}
void upd(int v, int tl, int tr, int l, int r, long long x) {
  if (l > tr || tl > r) return;
  if (l <= tl && tr <= r) {
    inc(v, x);
    return;
  }
  push(v);
  int tm = (tl + tr) >> 1;
  upd(v + v, tl, tm, l, r, x);
  upd(v + v + 1, tm + 1, tr, l, r, x);
  t[v] = min(t[v + v], t[v + v + 1]);
}
long long get(int v, int tl, int tr, int l, int r) {
  if (l > tr || tl > r) return (long long)(1e18);
  if (l <= tl && tr <= r) return t[v];
  push(v);
  int tm = (tl + tr) >> 1;
  return min(get(v + v, tl, tm, l, r), get(v + v + 1, tm + 1, tr, l, r));
}
void build(int v, int tl, int tr, int k) {
  keep[v] = 0;
  if (tl == tr) {
    t[v] = d[tl - 1][k - 1] + cnt[tl];
    return;
  }
  int tm = (tl + tr) >> 1;
  build(v + v, tl, tm, k);
  build(v + v + 1, tm + 1, tr, k);
  t[v] = min(t[v + v], t[v + v + 1]);
}
void precalc() {
  for (int i = 1; i < N; i++) {
    vector<int> dv;
    for (int j = 1; 1ll * j * j <= i; j++)
      if (i % j == 0) {
        dv.push_back(j);
        if (i / j != j) dv.push_back(i / j);
      }
    sort(dv.begin(), dv.end());
    for (int d : dv) c[d] = i / d;
    for (int x = dv.size() - 1; x >= 0; x--) {
      for (int y = x + 1; y < dv.size(); y++) {
        if (dv[y] % dv[x] == 0) c[dv[x]] -= c[dv[y]];
      }
    }
    for (int d : dv) g[i].push_back({d, c[d]});
  }
  int n = N - 1;
  for (int i = 1; i < N; i++) {
    d[i][0] = (long long)(1e18);
  }
  for (int k = 1; k <= 16; k++) {
    memset(t, 0, sizeof(t));
    build(1, 1, N - 1, k);
    for (int i = 1; i < N; i++) {
      for (auto p : g[i]) {
        upd(1, 1, N - 1, 1, p.first, p.second);
      }
      d[i][k] = get(1, 1, N - 1, 1, i);
    }
  }
}
void print(long long x) {
  string second;
  if (x == 0) {
    puts("0");
    return;
  }
  while (x > 0) {
    second += char(x % 10 + 'x');
    x /= 10;
  }
  reverse(second.begin(), second.end());
  for (char c : second) putchar(c);
  puts("");
}
void solve() {
  scanint(n);
  scanint(k);
  if (k > 16) {
    puts("0");
    return;
  }
  print(d[n][k]);
}
int main() {
  precalc();
  int T = 1;
  scanint(T);
  while (T--) {
    solve();
  }
  return 0;
}
