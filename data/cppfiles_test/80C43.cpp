#include <bits/stdc++.h>
using namespace std;
const int inf = 1 << 30;
const long long Inf = 1ll << 60ll;
namespace io {
char buf[(1 << 23)], *p1 = buf, *p2 = buf, c;
int f;
template <typename T>
T read() {
  T x = 0;
  f = 0;
  c = (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, (1 << 23), stdin), p1 == p2)
           ? EOF
           : *p1++);
  while (!isdigit(c))
    (c == '-') && (f = 1),
        c = (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, (1 << 23), stdin),
                          p1 == p2)
                 ? EOF
                 : *p1++);
  while (isdigit(c))
    x = x * 10 + (c & 15),
    c = (p1 == p2 &&
                 (p2 = (p1 = buf) + fread(buf, 1, (1 << 23), stdin), p1 == p2)
             ? EOF
             : *p1++);
  return f ? -x : x;
}
}  // namespace io
const int N = 1000005;
int pre[N], suf[N], a[N], b[N];
int ans[N];
void solve(int la, int ra, int lb, int rb) {
  if (lb > rb) return;
  int mid = lb + rb >> 1;
  pre[la] = 0;
  for (int i = la + 1; i <= ra; ++i) pre[i] = pre[i - 1] + (a[i - 1] > b[mid]);
  suf[ra] = 0;
  for (int i = ra - 1; i >= la; --i) suf[i] = suf[i + 1] + (a[i] < b[mid]);
  int mn = inf, pos = -1;
  for (int i = la; i <= ra; ++i) {
    if (pre[i] + suf[i] < mn) {
      mn = pre[i] + suf[i];
      pos = i;
    }
  }
  ans[mid] = pos;
  solve(la, pos, lb, mid - 1);
  solve(pos, ra, mid + 1, rb);
}
int c[N * 2];
bool cmp(int A, int B) { return c[A] != c[B] ? c[A] > c[B] : A > B; }
int t[N * 2], tot;
void update(int x, int v) {
  while (x <= tot) {
    t[x] += v;
    x += x & (-x);
  }
}
int query(int x) {
  int res = 0;
  while (x) {
    res += t[x];
    x -= x & (-x);
  }
  return res;
}
int n, m, id[N * 2];
int main() {
  int T = io::read<int>();
  while (T--) {
    n = io::read<int>();
    m = io::read<int>();
    for (int i = 1; i <= n; ++i) a[i] = io::read<int>();
    for (int i = 1; i <= m; ++i) b[i] = io::read<int>();
    sort(b + 1, b + m + 1);
    solve(1, n + 1, 1, m);
    int it = 0;
    tot = 0;
    for (int i = 1; i <= n; ++i) {
      while (it < m && ans[it + 1] <= i) {
        ++it;
        c[++tot] = b[it];
      }
      c[++tot] = a[i];
    }
    while (it < m) {
      ++it;
      c[++tot] = b[it];
    }
    for (int i = 1; i <= tot; ++i) id[i] = i, t[i] = 0;
    sort(id + 1, id + tot + 1, cmp);
    long long res = 0;
    for (int i = 1; i <= tot; ++i) {
      update(id[i], 1);
      res += query(id[i] - 1);
    }
    printf("%lld\n", res);
  }
  return 0;
}
