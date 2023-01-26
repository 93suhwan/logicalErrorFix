#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
const int mod = 998244353;
const double pi = acos(-1.0);
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int a[maxn];
struct SegmentTree {
  int l, r, f, pv, sv;
  long long v;
} t[maxn << 2];
void cal(int o, int l, int r) {
  int mid = (l + r) >> 1;
  int ls = o << 1, rs = o << 1 | 1;
  if (t[ls].f && t[rs].f) {
    if (a[mid] > a[mid + 1]) {
      t[o].f = 0;
      t[o].v = 0;
      t[o].pv = mid - l + 1;
      t[o].sv = r - mid;
    } else {
      t[o].f = 1;
      t[o].v = 0;
      t[o].pv = 0;
      t[o].sv = 0;
    }
  } else if (t[ls].f) {
    t[o].f = 0;
    if (a[mid] > a[mid + 1]) {
      t[o].pv = mid - l + 1;
      t[o].sv = t[rs].sv;
      t[o].v = t[rs].v + 1LL * t[rs].pv * (t[rs].pv + 1) / 2;
    } else {
      t[o].pv = mid - l + 1 + t[rs].pv;
      t[o].sv = t[rs].sv;
      t[o].v = t[rs].v;
    }
  } else if (t[rs].f) {
    t[o].f = 0;
    if (a[mid] > a[mid + 1]) {
      t[o].pv = t[ls].pv;
      t[o].sv = r - mid;
      t[o].v = t[ls].v + 1LL * t[ls].sv * (t[ls].sv + 1) / 2;
    } else {
      t[o].pv = t[ls].pv;
      t[o].sv = r - mid + t[ls].sv;
      t[o].v = t[ls].v;
    }
  } else {
    t[o].f = 0;
    if (a[mid] > a[mid + 1]) {
      t[o].pv = t[ls].pv;
      t[o].sv = t[rs].sv;
      t[o].v = t[ls].v + t[rs].v + 1LL * t[ls].sv * (t[ls].sv + 1) / 2 +
               1LL * t[rs].pv * (t[rs].pv + 1) / 2;
    } else {
      t[o].pv = t[ls].pv;
      t[o].sv = t[rs].sv;
      int tp = t[ls].sv + t[rs].pv;
      t[o].v = t[ls].v + t[rs].v + 1LL * tp * (tp + 1) / 2;
    }
  }
}
void build(int o, int l, int r) {
  t[o].l = l, t[o].r = r;
  if (l == r) {
    t[o].f = 1;
    return;
  }
  int mid = (l + r) >> 1;
  build(o << 1, l, mid), build(o << 1 | 1, mid + 1, r);
  cal(o, l, r);
}
void update(int o, int l, int r, int d) {
  if (t[o].l == t[o].r) {
    a[l] = d;
    return;
  }
  int mid = (t[o].l + t[o].r) >> 1;
  if (l <= mid) update(o << 1, l, r, d);
  if (r > mid) update(o << 1 | 1, l, r, d);
  cal(o, t[o].l, t[o].r);
}
long long ans;
int now;
void query(int o, int l, int r) {
  if (l <= t[o].l && r >= t[o].r) {
    if (t[o].f) {
      if (a[t[o].l - 1] > a[t[o].l]) {
        ans += 1LL * now * (now + 1) / 2;
        now = t[o].r - t[o].l + 1;
      } else {
        now += t[o].r - t[o].l + 1;
      }
    } else {
      if (a[t[o].l - 1] > a[t[o].l]) {
        ans += 1LL * now * (now + 1) / 2 + 1LL * t[o].pv * (t[o].pv + 1) / 2 +
               t[o].v;
        now = t[o].sv;
      } else {
        now += t[o].pv;
        ans += 1LL * now * (now + 1) / 2 + t[o].v;
        now = t[o].sv;
      }
    }
    return;
  }
  int mid = (t[o].l + t[o].r) >> 1;
  if (l <= mid) query(o << 1, l, r);
  if (r > mid) query(o << 1 | 1, l, r);
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  build(1, 1, n);
  while (q--) {
    int op, l, r;
    cin >> op >> l >> r;
    if (op == 1) {
      update(1, l, l, r);
    } else {
      ans = 0;
      now = 0;
      query(1, l, r);
      cout << ans + 1LL * now * (now + 1) / 2 << "\n";
    }
  }
  return 0;
}
