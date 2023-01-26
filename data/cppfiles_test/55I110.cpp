#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;
const int modu = 1e9 + 7;
const double eps = 1e-9;
int n, m;
vector<int> d;
vector<pair<int, int> > seg[maxn];
vector<int> maxt, mint;
vector<int> dp;
vector<bool> tg;
void pushdown(int o) {
  if (tg[o]) {
    maxt[(o << 1)] = min(maxt[o], maxt[(o << 1)]);
    maxt[((o << 1) | 1)] = min(maxt[o], maxt[((o << 1) | 1)]);
    mint[(o << 1)] = min(maxt[o], mint[(o << 1)]);
    mint[((o << 1) | 1)] = min(maxt[o], mint[((o << 1) | 1)]);
    tg[o] = 0;
  }
}
void upd(int o, int L, int R, int ql, int qr, int del) {
  if (maxt[o] <= del) return;
  if (ql <= L && R <= qr) {
    maxt[o] = del;
    mint[o] = min(mint[o], del);
    tg[o] = true;
    return;
  }
  pushdown(o);
  int mid = L + R >> 1;
  if (ql <= mid) upd((o << 1), L, mid, ql, qr, del);
  if (qr > mid) upd(((o << 1) | 1), mid + 1, R, ql, qr, del);
  maxt[o] = max(maxt[(o << 1)], maxt[((o << 1) | 1)]);
  mint[o] = min(mint[(o << 1)], mint[((o << 1) | 1)]);
}
int qry(int o, int L, int R, int ql, int qr) {
  if (ql <= L && R <= qr) return mint[o];
  pushdown(o);
  int res = 1e9;
  int mid = L + R >> 1;
  if (ql <= mid) res = min(res, qry((o << 1), L, mid, ql, qr));
  if (qr > mid) res = min(res, qry(((o << 1) | 1), mid + 1, R, ql, qr));
  return res;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  dp.resize(n + 1, 0);
  for (int i = 0; i < m; ++i) {
    int x, l, r;
    cin >> x >> l >> r;
    seg[x].push_back(make_pair(l, r));
    d.push_back(l);
    d.push_back(r);
  }
  sort(d.begin(), d.end());
  maxt.resize(6 * (int)d.size(), 0);
  mint.resize(6 * (int)d.size(), 0);
  tg.resize(6 * (int)d.size(), 0);
  int tot = (int)d.size();
  for (int i = 1; i <= n; ++i) {
    int res = 1e9;
    for (auto qj : seg[i]) {
      int l = lower_bound(d.begin(), d.end(), qj.first) - d.begin() + 1;
      int r = lower_bound(d.begin(), d.end(), qj.second) - d.begin() + 1;
      res = min(res, qry(1, 1, tot, l, r));
    }
    dp[i] = min(dp[i - 1] + 1, res + i - 1);
    for (auto qj : seg[i]) {
      int l = lower_bound(d.begin(), d.end(), qj.first) - d.begin() + 1;
      int r = lower_bound(d.begin(), d.end(), qj.second) - d.begin() + 1;
      upd(1, 1, tot, l, r, dp[i] - i);
    }
  }
  cout << dp[n] << "\n";
  vector<int> ways;
  for (int i = n; i >= 1; --i) {
    if (dp[i] == dp[i - 1] + 1) {
      ways.push_back(i);
      continue;
    }
    for (int j = i - 1; j >= 0; --j)
      if (dp[i] == dp[j] + i - j - 1) {
        i = j + 1;
        break;
      } else
        ways.push_back(j);
  }
  sort(ways.begin(), ways.end());
  for (int x : ways) cout << x << " ";
  cout << "\n";
  return 0;
}
