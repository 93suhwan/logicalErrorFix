#include <bits/stdc++.h>
using namespace std;
int n, q, a[200001], o, x, y, l, r;
long long c;
struct p {
  int l, r;
  long long an, x, y;
} tr[800001], ec;
p unite(p aa, p bb) {
  p e;
  e.l = aa.l, e.r = bb.r;
  if (aa.r - aa.l + 1 == aa.x) {
    if (a[aa.r] <= a[bb.l]) {
      e.an = bb.an, e.x = aa.x + bb.x;
      if (bb.r - bb.l + 1 == bb.x)
        e.y = aa.x + bb.x;
      else
        e.y = bb.y;
    } else {
      if (bb.r - bb.l + 1 == bb.x)
        e.an = 0, e.x = aa.x, e.y = bb.y;
      else
        e.an = bb.x * (bb.x + 1) / 2 + bb.an, e.x = aa.x, e.y = bb.y;
    }
  } else if (bb.r - bb.l + 1 == bb.x) {
    e.x = aa.x;
    if (a[aa.r] <= a[bb.l])
      e.an = aa.an, e.y = aa.y + bb.x;
    else
      e.y = bb.y, e.an = aa.y * (aa.y + 1) / 2 + aa.an;
  } else {
    e.x = aa.x, e.y = bb.y, e.an = aa.an + bb.an;
    if (a[aa.r] <= a[bb.l])
      c = aa.y + bb.x, e.an += c * (c + 1) / 2;
    else
      e.an += aa.y * (aa.y + 1) / 2 + bb.x * (bb.x + 1) / 2;
  }
  return e;
}
void build(int rt, int lx, int rx) {
  if (lx == rx)
    tr[rt] = {lx, rx, 0, 1, 1};
  else {
    int mid = lx + rx >> 1;
    build(rt * 2, lx, mid);
    build(rt * 2 + 1, mid + 1, rx);
    tr[rt] = unite(tr[rt * 2], tr[rt * 2 + 1]);
  }
}
void update(int rt, int l, int r, int p, int k) {
  if (l == r)
    a[l] = k, tr[rt] = {l, r, 0, 1, 1};
  else {
    int mid = l + r >> 1;
    if (mid >= p)
      update(rt * 2, l, mid, p, k);
    else
      update(rt * 2 + 1, mid + 1, r, p, k);
    tr[rt] = unite(tr[rt * 2], tr[rt * 2 + 1]);
  }
}
p ask(int rt, int lx, int rx, int l, int r) {
  if (lx >= l && rx <= r) return tr[rt];
  int mid = lx + rx >> 1;
  if (mid < l)
    return ask(rt * 2 + 1, mid + 1, rx, l, r);
  else if (mid + 1 > r)
    return ask(rt * 2, lx, mid, l, r);
  else
    return unite(ask(rt * 2, lx, mid, l, r),
                 ask(rt * 2 + 1, mid + 1, rx, l, r));
}
signed main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> q;
  for (int i = 1; i <= n; i++) cin >> a[i];
  build(1, 1, n);
  while (q--) {
    cin >> o >> l >> r;
    if (o == 1)
      update(1, 1, n, l, r);
    else {
      ec = ask(1, 1, n, l, r);
      if (ec.r - ec.l + 1 == ec.x)
        cout << ec.x * (ec.x + 1) / 2 << endl;
      else
        cout << ec.an + ec.x * (ec.x + 1) / 2 + ec.y * (ec.y + 1) / 2 << endl;
    }
  }
}
