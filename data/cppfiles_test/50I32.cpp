#include <bits/stdc++.h>
using namespace std;
int i, j, k, n, m, t, op, a[500500], it = 1;
long long su(long long a, long long b) {
  a += b;
  return (a >= 998244353) ? a - 998244353 : a;
}
class SB {
 public:
  long long f[12005000], t1[12005000], t2[12005000];
  int x, y, ls[12005000], rs[12005000];
  long long res;
  void up(int id, int l, int r, long long t3, long long t4) {
    f[id] = f[id] * t4 % 998244353;
    f[id] = su(f[id], t3 * (r - l + 1) % 998244353);
    t1[id] = (t1[id] * t4 + t3) % 998244353;
    t2[id] = t2[id] * t4 % 998244353;
  }
  void upd(int id, int l, int r) {
    if (!ls[id]) {
      ls[id] = ++it;
      t2[it] = 1;
    }
    if (!rs[id]) {
      rs[id] = ++it;
      t2[it] = 1;
    }
    up(ls[id], l, ((l + r) >> 1), t1[id], t2[id]);
    up(rs[id], ((l + r) >> 1) + 1, r, t1[id], t2[id]);
    t1[id] = 0;
    t2[id] = 1;
  }
  void build(int id, int l, int r) {
    t2[id] = 1;
    if (l == r) {
      f[id] = a[l];
      return;
    }
    if (!ls[id]) {
      ls[id] = ++it;
      t2[it] = 1;
    }
    if (!rs[id]) {
      rs[id] = ++it;
      t2[it] = 1;
    }
    build(ls[id], l, ((l + r) >> 1));
    build(rs[id], ((l + r) >> 1) + 1, r);
    f[id] = (f[ls[id]] + f[rs[id]]) % 998244353;
  }
  void add(int id, int l, int r, long long w) {
    if (l == r) {
      f[id] = su(f[id], w);
      return;
    }
    if (!ls[id]) {
      ls[id] = ++it;
      t2[it] = 1;
    }
    if (!rs[id]) {
      rs[id] = ++it;
      t2[it] = 1;
    }
    upd(id, l, r);
    if (x <= l && r <= y) {
      f[id] += (r - l + 1) * w;
      f[id] %= 998244353;
      t1[id] = su(t1[id], w);
      return;
    }
    if (x <= ((l + r) >> 1)) add(ls[id], l, ((l + r) >> 1), w);
    if (y > ((l + r) >> 1)) add(rs[id], ((l + r) >> 1) + 1, r, w);
    f[id] = (f[ls[id]] + f[rs[id]]) % 998244353;
  }
  void mul(int id, int l, int r, long long w) {
    if (l == r) {
      f[id] = f[id] * w % 998244353;
      return;
    }
    if (!ls[id]) {
      ls[id] = ++it;
      t2[it] = 1;
    }
    if (!rs[id]) {
      rs[id] = ++it;
      t2[it] = 1;
    }
    upd(id, l, r);
    if (x <= l && r <= y) {
      f[id] = f[id] * w % 998244353;
      t1[id] = t1[id] * w % 998244353;
      t2[id] = t2[id] * w % 998244353;
      return;
    }
    if (x <= ((l + r) >> 1)) mul(ls[id], l, ((l + r) >> 1), w);
    if (y > ((l + r) >> 1)) mul(rs[id], ((l + r) >> 1) + 1, r, w);
    f[id] = (f[ls[id]] + f[rs[id]]) % 998244353;
  }
  void que(int id, int l, int r) {
    upd(id, l, r);
    if (x <= l && r <= y) {
      res = su(res, f[id]);
      return;
    }
    if (!ls[id]) {
      ls[id] = ++it;
      t2[it] = 1;
    }
    if (!rs[id]) {
      rs[id] = ++it;
      t2[it] = 1;
    }
    if (x <= ((l + r) >> 1)) que(ls[id], l, ((l + r) >> 1));
    if (y > ((l + r) >> 1)) que(rs[id], ((l + r) >> 1) + 1, r);
  }
} sb;
int main() {
  sb.t2[1] = 1;
  ios::sync_with_stdio(0);
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sb.x = 1;
  sb.y = a[1];
  sb.add(1, 1, 1000000000, 1);
  for (i = 2; i <= n; i++) {
    sb.res = 0;
    sb.que(1, 1, 1000000000);
    long long tmp = sb.res;
    sb.mul(1, 1, 1000000000, 998244353 - 1);
    sb.y = a[i];
    sb.add(1, 1, 1000000000, tmp);
    sb.x = a[i] + 1;
    sb.y = 1000000000;
    sb.mul(1, 1, 1000000000, 0);
    sb.x = 1;
    sb.y = a[i];
  }
  sb.res = 0;
  sb.que(1, 1, 1000000000);
  cout << sb.res;
}
