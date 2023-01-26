#include <bits/stdc++.h>
const int N = 1e6 + 10;
const int M = 9699690;
const int mod = 1e9 + 7, Gi = 332748118;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3fll;
const int SIZE = 1 << 21;
char ibuf[SIZE], *iS, *iT;
using std::pair;
template <class T>
void read(T &x) {
  x = 0;
  int f = 0;
  char c = getchar();
  while (!isdigit(c)) f |= c == '-', c = getchar();
  while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
  if (f) x = -x;
}
int random(int i) { return rand() % i + 1; }
template <class T>
void ckmax(T &x, T y) {
  x = x > y ? x : y;
}
template <class T>
void ckmin(T &x, T y) {
  x = x < y ? x : y;
}
template <class T>
T Abs(T x) {
  return x > 0 ? x : -x;
}
inline int plus(int x, int y) { return x + y >= mod ? x + y - mod : x + y; }
int qp(int d, int k) {
  int f = 1;
  while (k) {
    if (k & 1) f = (1ll * (f) * (d) % mod);
    d = (1ll * (d) * (d) % mod), k >>= 1;
  }
  return f;
}
int n, m, a[N], b[N], tmp[N];
pair<int, int> p[N];
long long ans;
void msort(int l, int r) {
  if (l == r) return;
  int mid = l + r >> 1;
  msort(l, mid), msort(mid + 1, r);
  int lp = l, rp = mid + 1, ct = 0;
  while (lp <= mid && rp <= r) {
    if (a[lp] <= a[rp])
      tmp[++ct] = a[lp++], ans += rp - 1 - mid;
    else
      tmp[++ct] = a[rp++];
  }
  while (lp <= mid) tmp[++ct] = a[lp++], ans += rp - 1 - mid;
  while (rp <= r) tmp[++ct] = a[rp++];
  for (int i = (l); i <= (r); i++) a[i] = tmp[i + 1 - l];
}
int tag[N << 2], mi[N << 2];
void build(int id, int l, int r) {
  tag[id] = 0;
  if (l == r) {
    mi[id] = l - 1;
    return;
  }
  int mid = l + r >> 1;
  build(id << 1, l, mid), build(id << 1 | 1, mid + 1, r);
  mi[id] = std::min(mi[id << 1], mi[id << 1 | 1]);
}
void pushdown(int id) {
  if (tag[id]) {
    tag[id << 1] += tag[id];
    tag[id << 1 | 1] += tag[id];
    mi[id << 1] += tag[id];
    mi[id << 1 | 1] += tag[id];
    tag[id] = 0;
  }
}
void upt(int id, int L, int R, int l, int r, int d) {
  if (l <= L && R <= r) {
    tag[id] += d;
    mi[id] += d;
    return;
  }
  if (l > R || r < L) return;
  int Mid = L + R >> 1;
  pushdown(id);
  upt(id << 1, L, Mid, l, r, d);
  upt(id << 1 | 1, Mid + 1, R, l, r, d);
  mi[id] = std::min(mi[id << 1], mi[id << 1 | 1]);
}
void work() {
  read(n), read(m);
  for (int i = (1); i <= (n); i++) read(a[i]), p[i] = std::make_pair(a[i], i);
  ans = 0;
  msort(1, n);
  for (int i = (1); i <= (m); i++) read(b[i]);
  std::sort(p + 1, p + 1 + n);
  std::sort(b + 1, b + 1 + m);
  build(1, 1, n + 1);
  int ld = 1, lu = 1;
  for (int i = (1); i <= (m); i++) {
    while (ld <= n && p[ld].first <= b[i])
      upt(1, 1, n + 1, p[ld++].second + 1, n + 1, -1);
    while (lu <= n && p[lu].first < b[i])
      upt(1, 1, n + 1, 1, p[lu++].second, 1);
    ans += mi[1];
  }
  printf("%lld\n", ans);
}
int main() {
  int T = 1;
  read(T);
  while (T--) work();
  return 0;
}
