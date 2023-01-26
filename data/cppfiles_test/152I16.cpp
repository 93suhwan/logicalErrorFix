#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 100;
const int inf = 1e9;
const long long mod = 998244353;
int n, bas;
int a[N];
int seg[N * 8], laz[N * 8];
void push_up(int k) {
  seg[k] = min(seg[(k << 1)], seg[(k << 1 | 1)]);
  return;
}
void push_down(int k) {
  if (laz[k]) {
    seg[(k << 1)] = seg[(k << 1 | 1)] = laz[k];
    laz[(k << 1)] = laz[(k << 1 | 1)] = laz[k];
    laz[k] = 0;
  }
}
void build(int l = 1, int r = n + bas, int k = 1) {
  laz[k] = 0;
  if (l == r) {
    return (void)(seg[k] = -inf);
  }
  build(l, ((l + r) >> 1), (k << 1));
  build(((l + r) >> 1) + 1, r, (k << 1 | 1));
  push_up(k);
}
int ask(int val, int l = 1, int r = n + bas, int k = 1) {
  if (l == r) {
    if (seg[k] <= val) return l;
    return n + bas + 1;
  }
  push_down(k);
  if (seg[(k << 1)] <= val) return ask(val, l, ((l + r) >> 1), (k << 1));
  return ask(val, ((l + r) >> 1) + 1, r, (k << 1 | 1));
}
int cal_val(int to, int l = 1, int r = n + bas, int k = 1) {
  if (l == r) return seg[k];
  if (l < r) push_down(k);
  if (to <= ((l + r) >> 1)) return cal_val(to, l, ((l + r) >> 1), (k << 1));
  return cal_val(to, ((l + r) >> 1) + 1, r, (k << 1 | 1));
}
void upd(int L, int R, int val, int l = 1, int r = n + bas, int k = 1) {
  if (l > R || r < L) return;
  if (L <= l && r <= R) {
    seg[k] = val;
    laz[k] = val;
    return;
  }
  if (l < r) push_down(k);
  upd(L, R, val, l, ((l + r) >> 1), (k << 1));
  upd(L, R, val, ((l + r) >> 1) + 1, r, (k << 1 | 1));
  push_up(k);
  return;
}
int lp[N], rp[N], ans[N], vvv[N][4];
struct Cg {
  int l, r, val;
  bool need;
} cg[N][4];
void dfs(int l = 1, int r = n + bas, int k = 1) {
  if (l == r) {
    cerr << seg[k] - bas << ' ';
    return;
  }
  if (l < r) push_down(k);
  dfs(l, ((l + r) >> 1), (k << 1));
  dfs(((l + r) >> 1) + 1, r, (k << 1 | 1));
  return;
}
void sol() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  bas = n + 2;
  build();
  auto get = [&](int id, int bg, int l, int r, int y) {
    cg[id][bg].need = 0;
    cg[id][bg + 1].need = 0;
    if (l > r) return;
    if (l <= y) {
      cg[id][bg].need = 1;
      int tmp = cal_val(y);
      cg[id][bg].l = y;
      cg[id][bg].val = tmp;
      vvv[id][bg] = tmp;
    }
    ++bg;
    {
      cg[id][bg].need = 1;
      cg[id][bg].l = max(l, y);
      cg[id][bg].val = y;
      vvv[id][bg] = cal_val(l);
    }
    return;
  };
  auto doit = [&](int l, int r, int val) {
    if (l <= r) upd(l, r, val);
  };
  for (int i = 1; i <= n; i++) {
    int x = -a[i] + bas;
    int y = a[i] + bas;
    if (seg[1] == inf) return (void)(cout << "NO" << '\n');
    lp[i] = ask(y);
    rp[i] = ask(x);
    get(i, 0, lp[i], n + bas, y);
    get(i, 2, rp[i], n + bas, x);
    upd(1, n + bas, inf);
    for (int j = 0; j < 4; j++) {
      if (cg[i][j].need) {
        cg[i][j].r = ask(cg[i][j].val) - 1;
        doit(cg[i][j].l, cg[i][j].r, cg[i][j].val);
      }
    }
  }
  if (seg[1] == inf) return (void)(cout << "NO" << '\n');
  int ps = n + bas;
  int val = seg[1];
  for (int i = n; i >= 1; i--) {
    bool flg = 0;
    for (int j = 0; j < 4; j += 2) {
      if (cg[i][j].l <= ps && cg[i][j].r >= ps && cg[i][j].val <= val) {
        flg = 1;
        if (j <= 1) {
          ans[i] = 1;
          ps = a[i] + bas;
          val = vvv[i][0];
        } else {
          ans[i] = -1;
          ps = -a[i] + bas;
          val = vvv[i][2];
        }
        break;
      }
    }
    if (!flg) {
      if (val == a[i] + bas) {
        ans[i] = 1;
        ps = lp[i];
        val = vvv[i][1];
      } else {
        ans[i] = -1;
        ps = rp[i];
        val = vvv[i][3];
      }
    }
  }
  cout << "YES" << '\n';
  for (int i = 1; i <= n; i++) cout << a[i] * ans[i] << ' ';
  cout << '\n';
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) sol();
}
