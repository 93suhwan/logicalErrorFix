#include <bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &x) {
  static char c;
  static int f;
  for (c = getchar(), f = 1; c < '0' || c > '9'; c = getchar())
    if (c == '-') f = -f;
  for (x = 0; c >= '0' && c <= '9'; c = getchar()) x = x * 10 + (c & 15);
  x *= f;
}
template <typename T>
void write(T x) {
  static char q[65];
  int cnt = 0;
  if (x < 0) putchar('-'), x = -x;
  q[++cnt] = x % 10, x /= 10;
  while (x) q[++cnt] = x % 10, x /= 10;
  while (cnt) putchar(q[cnt--] + '0');
}
const int N = 3e5 + 10;
int _, n, cur;
struct segmentTree {
  struct node {
    int l, r, L, R, sum, head;
  } tr[N << 3];
  inline void pushup(long long p) {
    tr[p].sum = min(tr[tr[p].l].sum, tr[tr[p].r].sum);
    if (tr[p].sum == tr[tr[p].l].sum)
      tr[p].head = tr[tr[p].l].head;
    else
      tr[p].head = tr[tr[p].r].head;
  }
  inline void pushdown(long long p) {}
  inline void build(long long l, long long r, long long p) {
    tr[p].l = p << 1;
    tr[p].r = p << 1 | 1;
    tr[p].L = l, tr[p].R = r;
    if (l == r) {
      tr[p].sum = 0x3f3f3f3f;
      tr[p].head = l;
      return;
    }
    long long mid = l + r >> 1;
    build(l, mid, tr[p].l), build(mid + 1, r, tr[p].r);
    pushup(p);
  }
  inline void add(long long l, long long r, long long p, int k) {
    if (tr[p].L >= l && tr[p].R <= r) {
      tr[p].sum = min(tr[p].sum, k);
      return;
    }
    pushdown(p);
    if (tr[tr[p].l].R >= l) add(l, r, tr[p].l, k);
    if (tr[tr[p].r].L <= r) add(l, r, tr[p].r, k);
    pushup(p);
  }
  inline pair<int, int> ask(long long l, long long r, long long p) {
    pair<int, int> ret;
    ret.first = 0x3f3f3f3f;
    pushdown(p);
    if (tr[p].L >= l && tr[p].R <= r) return {tr[p].sum, tr[p].head};
    if (tr[tr[p].l].R >= l) (ret = ask(l, r, tr[p].l));
    if (tr[tr[p].r].L <= r) {
      auto idy = ask(l, r, tr[p].r);
      if (idy.first < ret.first) ret = idy;
    }
    return ret;
  }
} T;
int head[N];
int a[N], b[N], f[N];
vector<int> cnt[N];
void solve() {
  read(n);
  for (auto i = 1; i <= n; ++i) {
    read(a[i]);
  }
  for (auto i = 1; i <= n; ++i) {
    read(b[i]);
    cnt[i + b[i]].push_back(i);
  }
  memset(f, 0x3f, sizeof f);
  T.build(1, n, 1);
  for (auto i = 1; i <= n; ++i) {
    int l = i - a[i], r = i - 1;
    if (l <= 0) {
      f[i] = 1;
    } else {
      if (l > r) continue;
      auto now = T.ask(l, r, 1);
      f[i] = now.first + 1;
      head[i] = now.second;
    }
    for (auto j : cnt[i]) {
      T.add(j, j, 1, f[i]);
    }
  }
  if (f[n] >= 0x3f3f3f3f) {
    puts("-1");
    exit(0);
  }
  write(f[n]);
  putchar('\n');
  int idx = head[n];
  while (idx != 0) {
    write(idx);
    putchar(' ');
    idx = head[idx + b[idx]];
  }
  putchar('0');
}
signed main(int argc, char const *argv[]) {
  solve();
  return 0;
}
