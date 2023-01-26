#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
const int mod = 998244353;
int n;
int a[N];
map<int, int> mp;
int pos[N], cnt = 0;
class node {
 public:
  int val, sz, tg1, tg2;
} ts[N << 2];
void build(int x, int l, int r) {
  if (l == r) {
    ts[x].sz = (pos[l] - (l ? pos[l - 1] : 0)) % mod;
    ts[x].tg1 = ts[x].tg2 = 0;
    ts[x].val = 0;
    return;
  }
  int mid = (l + r) >> 1;
  build(x << 1, l, mid);
  build(x << 1 | 1, mid + 1, r);
  ts[x].sz = (ts[x << 1].sz + ts[x << 1 | 1].sz) % mod;
  ts[x].tg1 = ts[x].tg2 = 0;
  ts[x].val = 0;
}
void pd(int x) {
  if (!ts[x].tg1 && !ts[x].tg2) return;
  if (ts[x].tg1) {
    ts[x << 1].val = ts[x << 1 | 1].val = 0;
    ts[x << 1].tg1 = ts[x << 1 | 1].tg1 = 1;
  }
  if (ts[x].tg2) {
    ts[x << 1].val =
        (ts[x << 1].val + 1ll * ts[x << 1].sz * ts[x].tg2 % mod) % mod;
    ts[x << 1 | 1].val =
        (ts[x << 1 | 1].val + 1ll * ts[x << 1 | 1].sz * ts[x].tg2 % mod) % mod;
    ts[x << 1].tg2 = (ts[x << 1].tg2 + ts[x].tg2) % mod;
    ts[x << 1 | 1].tg2 = (ts[x << 1 | 1].tg2 + ts[x].tg2) % mod;
  }
  ts[x].tg1 = ts[x].tg2 = 0;
}
void mdy(int x, int l, int r, int cl, int cr) {
  if (l == cl && r == cr) {
    if (l != r) pd(x);
    ts[x].tg1 = 1;
    ts[x].tg2 = 0;
    ts[x].val = 0;
    return;
  }
  pd(x);
  int mid = (l + r) >> 1;
  if (cr <= mid)
    mdy(x << 1, l, mid, cl, cr);
  else if (mid + 1 <= cl)
    mdy(x << 1 | 1, mid + 1, r, cl, cr);
  else
    mdy(x << 1, l, mid, cl, mid), mdy(x << 1 | 1, mid + 1, r, mid + 1, cr);
  ts[x].val = (ts[x << 1].val + ts[x << 1 | 1].val) % mod;
}
void upd(int x, int l, int r, int cl, int cr, int val) {
  if (l == cl && r == cr) {
    if (l != r) pd(x);
    ts[x].tg2 = (ts[x].tg2 + val) % mod;
    ts[x].val = (ts[x].val + 1ll * val * ts[x].sz % mod) % mod;
    return;
  }
  pd(x);
  int mid = (l + r) >> 1;
  if (cr <= mid)
    upd(x << 1, l, mid, cl, cr, val);
  else if (mid + 1 <= cl)
    upd(x << 1 | 1, mid + 1, r, cl, cr, val);
  else
    upd(x << 1, l, mid, cl, mid, val),
        upd(x << 1 | 1, mid + 1, r, mid + 1, cr, val);
  ts[x].val = (ts[x << 1].val + ts[x << 1 | 1].val) % mod;
}
int qry(int x, int l, int r, int pos) {
  if (l == r) return ts[x].val;
  pd(x);
  int mid = (l + r) >> 1;
  if (pos <= mid)
    return qry(x << 1, l, mid, pos);
  else
    return qry(x << 1 | 1, mid + 1, r, pos);
  return ts[x].val;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) mp[a[i]] = 1;
  for (map<int, int>::iterator it = mp.begin(); it != mp.end(); it++) {
    it->second = cnt;
    pos[cnt] = it->first;
    cnt++;
  }
  build(1, 0, n - 1);
  int tmp = 1;
  for (int i = 0; i < n; i++) {
    if (i == 0) {
      int pos = mp[a[i]];
      upd(1, 0, n - 1, 0, pos, 1);
    } else {
      if (a[i] >= a[i - 1]) {
        int pos = mp[a[i]], val = ts[1].val;
        upd(1, 0, n - 1, 0, pos, (mod - val) % mod);
      } else {
        int lp = mp[a[i - 1]], np = mp[a[i]], val = ts[1].val;
        upd(1, 0, n - 1, 0, np, (mod - val) % mod);
        mdy(1, 0, n - 1, np + 1, lp);
      }
      tmp = -tmp;
    }
  }
  int ans = ts[1].val;
  ans = (ans * tmp + mod) % mod;
  cout << ans << endl;
  return 0;
}
