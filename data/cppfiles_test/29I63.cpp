#include <bits/stdc++.h>
const int MAXN = 3e5 + 15;
using namespace std;
long long A[MAXN];
long long st[4 * MAXN + 5][3];
long long lazy[4 * MAXN + 5];
void lazyup(int v, int tl, int tr) {
  if (lazy[v] == 0) return;
  st[v][3] += lazy[v];
  if (tl != tr) {
    lazy[2 * v] += lazy[v];
    lazy[2 * v + 1] += lazy[v];
  }
  lazy[v] = 0;
}
void update(int k, int v, int tl, int tr, int pos, long long val) {
  if (tl == pos && tr == pos) {
    st[v][k] += val;
    return;
  }
  int tm = (tl + tr) / 2;
  if (pos <= tm)
    update(k, 2 * v, tl, tm, pos, val);
  else
    update(k, 2 * v + 1, tm + 1, tr, pos, val);
  st[v][k] = st[2 * v][k] + st[2 * v + 1][k];
}
long long rsum(int k, int v, int tl, int tr, int l, int r) {
  if (l > r) return 0;
  if (tl == l && tr == r) return st[v][k];
  int tm = (tl + tr) / 2;
  return rsum(k, 2 * v, tl, tm, l, min(r, tm)) +
         rsum(k, 2 * v + 1, tm + 1, tr, max(tm + 1, l), r);
}
long long updateR(int v, int tl, int tr, int l, int r, long long val) {
  lazyup(v, tl, tr);
  if (l > r) return 0;
  if (tl == l && tr == r) {
    lazy[v] += val;
    lazyup(v, tl, tr);
    return st[v][3];
  }
  int tm = (tl + tr) / 2;
  return st[v][3] = updateR(2 * v, tl, tm, l, min(r, tm), val) +
                    updateR(2 * v + 1, tm + 1, tr, max(l, tm + 1), r, val);
}
long long rsumR(int v, int tl, int tr, int l, int r) {
  lazyup(v, tl, tr);
  if (l > r) return 0;
  if (tl == l && tr == r) return st[v][3];
  int tm = (tl + tr) / 2;
  return rsumR(2 * v, tl, tm, l, min(r, tm)) +
         rsumR(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
}
void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> A[i + 1];
  long long ans = 0, pre = 0;
  for (int i = 1; i <= n; i++) {
    long long x = A[i];
    if (x == 1) {
      update(0, 1, 1, MAXN, x, 1);
      update(1, 1, 1, MAXN, x, x);
    } else {
      for (int k = 0; k < MAXN; k += x) {
        long long cnt = rsum(0, 1, 1, MAXN, k + 1, min(MAXN + 0LL, k - 1 + x));
        ans += rsum(1, 1, 1, MAXN, k + 1, min(MAXN + 0LL, k - 1 + x)) - cnt * k;
      }
      update(0, 1, 1, MAXN, x, 1);
      update(1, 1, 1, MAXN, x, x);
    }
    ans += x * (i - 1) - rsumR(1, 1, MAXN, x, x);
    for (int k = 0; k * x < MAXN; k++) {
      updateR(1, 1, MAXN, max(k * x, 1LL), min(k * x + x - 1, 0LL + MAXN),
              k * x);
    }
    cout << ans << " ";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(0);
  cin.tie(0);
  cout << fixed << setprecision(12);
  int t = 1;
  for (int i = 1; i <= t; i++) {
    solve();
    cout << "\n";
  }
  return 0;
}
