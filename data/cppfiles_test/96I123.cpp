#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 9;
const long long inf = 0x3f3f3f3f;
int a[N];
long long sum(long long l, long long r) {
  if (l == r) return l;
  return (l + r) * (r - l + 1) / 2;
}
struct segment {
  struct node {
    int l, r, L, R, data, long long, rr, mark;
  } tr[N];
  void pushup(int p) {
    tr[p].data = tr[tr[p].l].data + tr[tr[p].r].data;
    tr[p].long long = tr[tr[p].l].long long;
    tr[p].rr = tr[tr[p].r].rr;
    if (a[tr[tr[p].l].R] <= a[tr[tr[p].r].L]) {
      tr[p].data += sum(1, tr[tr[p].r].long long + tr[tr[p].l].rr) -
                    sum(1, tr[tr[p].r].long long) - sum(1, tr[tr[p].l].rr);
      if (tr[tr[p].l].R - tr[tr[p].l].L + 1 == tr[tr[p].l].long long)
        tr[p].long long = tr[tr[p].l].long long + tr[tr[p].r].long long;
      if (tr[tr[p].r].R - tr[tr[p].r].L + 1 == tr[tr[p].r].rr)
        tr[p].rr = tr[tr[p].r].rr + tr[tr[p].l].rr;
    }
  }
  inline void build(int l, int r, int p) {
    tr[p].L = l, tr[p].R = r;
    tr[p].l = p << 1, tr[p].r = p << 1 | 1;
    int mid = (l + r) >> 1;
    if (l == r) {
      tr[p].data = 1;
      tr[p].long long = 1;
      tr[p].rr = 1;
      return;
    }
    build(l, mid, tr[p].l);
    build(mid + 1, r, tr[p].r);
    pushup(p);
  }
  inline void change(int pos, int ad, int p) {
    if (tr[p].L == pos && tr[p].R == pos) {
      a[pos] = ad;
      return;
    }
    if (pos <= tr[tr[p].l].R) change(pos, ad, tr[p].l);
    if (pos >= tr[tr[p].r].L) change(pos, ad, tr[p].r);
    pushup(p);
  }
  inline long long ask(int l, int r, int p) {
    long long ret = 0;
    if (tr[p].L >= l && tr[p].R <= r) return tr[p].data;
    long long long long = 0, rr = 0;
    if (tr[tr[p].l].R >= l) long long = ask(l, r, tr[p].l);
    if (tr[tr[p].r].L <= r) rr = ask(l, r, tr[p].r);
    if (long long != 0 && rr != 0) {
      if (a[tr[tr[p].l].R] <= a[tr[tr[p].r].L]) {
        int l_len = min(tr[tr[p].l].rr, tr[tr[p].l].R - l + 1),
            r_len = min(tr[tr[p].r].long long, r - tr[tr[p].r].L + 1);
        ret += sum(1, l_len + r_len) - sum(1, r_len) - sum(1, l_len);
      }
    }
    return ret + rr + long long;
  }
} T;
void solve() {
  int n, q;
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  T.build(1, n, 1);
  while (q--) {
    int op, x, y;
    scanf("%d%d%d", &op, &x, &y);
    if (op == 1)
      T.change(x, y, 1);
    else
      printf("%lld\n", T.ask(x, y, 1));
  }
}
signed main() {
  long long t = 1;
  while (t--) {
    solve();
  }
}
