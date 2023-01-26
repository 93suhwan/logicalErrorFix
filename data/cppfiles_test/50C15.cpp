#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  char c = getchar();
  long long first = 0;
  bool f = 0;
  for (; !isdigit(c); c = getchar()) f ^= !(c ^ 45);
  for (; isdigit(c); c = getchar())
    first = (first << 1) + (first << 3) + (c ^ 48);
  if (f) first = -first;
  return first;
}
const long long Mod = 998244353;
const long long M = 5e5 + 10;
long long n, a[M], pp[M], p[M];
map<long long, long long> t;
struct segment_tree {
  struct tree {
    long long tl, tr, val, len, tag1, tag2;
  } t[M << 2];
  void pushup(long long k) {
    t[(k)].val = (t[(k << 1)].val + t[(k << 1 | 1)].val) % Mod;
  }
  void upd(long long k, long long a, long long b) {
    t[(k)].val = (t[(k)].val * a + b * t[(k)].len) % Mod;
    t[(k)].tag1 = t[(k)].tag1 * a % Mod,
    t[(k)].tag2 = (t[(k)].tag2 * a + b) % Mod;
  }
  void pushdown(long long k) {
    upd(k << 1, t[(k)].tag1, t[(k)].tag2),
        upd(k << 1 | 1, t[(k)].tag1, t[(k)].tag2);
    t[(k)].tag1 = 1, t[(k)].tag2 = 0;
  }
  void build(long long k, long long l, long long r) {
    t[(k)].tl = l, t[(k)].tr = r;
    t[(k)].tag1 = 1;
    if (l == r) {
      t[(k)].len = p[l] - p[l - 1];
      return;
    }
    long long Mid = (l + r) >> 1;
    build(k << 1, l, Mid), build(k << 1 | 1, Mid + 1, r);
    t[(k)].len = t[(k << 1)].len + t[(k << 1 | 1)].len;
  }
  void update(long long k, long long l, long long r, long long a, long long b) {
    if (t[(k)].tl >= l && t[(k)].tr <= r) {
      upd(k, a, b);
      return;
    }
    if (t[(k)].tl > r || t[(k)].tr < l) return;
    pushdown(k);
    update(k << 1, l, r, a, b), update(k << 1 | 1, l, r, a, b);
    pushup(k);
  }
  long long query(long long k, long long l, long long r) {
    if (t[(k)].tl > r || t[(k)].tr < l) return 0;
    if (t[(k)].tl >= l && t[(k)].tr <= r) return t[(k)].val;
    pushdown(k);
    return (query(k << 1, l, r) + query(k << 1 | 1, l, r)) % Mod;
  }
} T;
signed main() {
  n = read();
  for (long long i = 1; i <= n; i++) a[i] = pp[i] = read();
  sort(pp + 1, pp + 1 + n);
  long long cnt = 0;
  for (long long i = 1; i <= n; i++)
    if (pp[i] != pp[i - 1]) p[++cnt] = pp[i], t[pp[i]] = cnt;
  for (long long i = 1; i <= n; i++) a[i] = t[a[i]];
  T.build(1, 1, cnt);
  T.update(1, 1, a[1], 1, 1);
  for (long long i = 2; i <= n; i++) {
    long long sum = T.query(1, 1, cnt);
    T.update(1, a[i] + 1, cnt, 0, 0);
    T.update(1, 1, a[i], Mod - 1, sum);
  }
  long long ans = T.query(1, 1, cnt);
  cout << ans << endl;
  return 0;
}
