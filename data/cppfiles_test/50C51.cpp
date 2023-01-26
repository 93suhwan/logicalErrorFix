#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 99, mod = 998244353;
int n, t, a[N], dp[N][2], last[N], lazy[N];
struct node {
  int sum[2], sumd[2];
  node() { sum[0] = sum[1] = sumd[0] = sumd[1] = 0; }
} seg[N];
void shift(int, int, int);
node merge(node u, node v) {
  node ans;
  for (int i = 0; i < 2; i++) {
    ans.sum[i] = (u.sum[i] + v.sum[i]) % mod;
    ans.sumd[i] = (u.sumd[i] + v.sumd[i]) % mod;
  }
  return ans;
}
void read() {
  cin >> n;
  for (int i = 1; i < n + 1; i++) cin >> a[i];
  last[1] = 0;
  for (int i = 2; i < n + 1; i++) {
    last[i] = i - 1;
    while (last[i] != 0 && a[last[i]] > a[i]) {
      last[i] = last[last[i]];
    }
  }
}
void change(int L, int R, int val, int id = 1, int l = 0, int r = n) {
  if (r <= L || R <= l) return;
  if (L <= l && r <= R) {
    lazy[id] = val;
    for (int i = 0; i < 2; i++) {
      seg[id].sum[i] = 1ll * val * seg[id].sumd[i] % mod;
    }
    return;
  }
  int mid = (l + r) >> 1;
  shift(id, l, r);
  change(L, R, val, id * 2 + 0, l, mid);
  change(L, R, val, id * 2 + 1, mid, r);
  seg[id] = merge(seg[id * 2 + 0], seg[id * 2 + 1]);
}
void upd(int x, int id = 1, int l = 0, int r = n) {
  if (r <= x || x < l) return;
  if (l + 1 == r && l == x) {
    if (x & 1) {
      seg[id].sumd[0] = dp[x][1];
      seg[id].sumd[1] = dp[x][0];
    } else {
      seg[id].sumd[0] = dp[x][0];
      seg[id].sumd[1] = dp[x][1];
    }
    return;
  }
  int mid = (l + r) / 2;
  shift(id, l, r);
  upd(x, id * 2 + 0, l, mid);
  upd(x, id * 2 + 1, mid, r);
  seg[id] = merge(seg[id * 2 + 0], seg[id * 2 + 1]);
}
void shift(int id, int l, int r) {
  if (lazy[id] == -1) return;
  int mid = (l + r) / 2;
  change(l, mid, lazy[id], id * 2 + 0, l, mid);
  change(mid, r, lazy[id], id * 2 + 1, mid, r);
  lazy[id] = -1;
}
void solve() {
  dp[0][0] = 1;
  upd(0);
  for (int i = 1; i < n + 1; i++) {
    change(last[i], i, a[i]);
    if (i & 1) {
      dp[i][0] = seg[1].sum[0];
      dp[i][1] = seg[1].sum[1];
    } else {
      dp[i][0] = seg[1].sum[1];
      dp[i][1] = seg[1].sum[0];
    }
    if (i == n) break;
    upd(i);
  }
  cout << (dp[n][0] - dp[n][1] + mod) % mod;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  read();
  solve();
}
