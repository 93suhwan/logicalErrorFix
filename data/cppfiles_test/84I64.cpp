#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;
const int N = 1e5;
const int H = 18;
ll dp[H + 1][N + 1];
class SegTree {
 private:
  const ll NEUT = 4 * (ll)1e18;
  vector<ll> seg, tag;
  int h = 1;
  void apply(int i, ll v) {
    seg[i] += v;
    if (i < h) tag[i] += v;
  }
  ll recGet(int a, int b, int i, int ia, int ib) {
    if (ib <= a || b <= ia) return NEUT;
    if (a <= ia && ib <= b) return seg[i];
    int im = (ia + ib) >> 1;
    return tag[i] +
           min(recGet(a, b, 2 * i, ia, im), recGet(a, b, 2 * i + 1, im, ib));
  }
  void recApply(int a, int b, ll v, int i, int ia, int ib) {
    if (ib <= a || b <= ia) return;
    if (a <= ia && ib <= b)
      apply(i, v);
    else {
      int im = (ia + ib) >> 1;
      recApply(a, b, v, 2 * i, ia, im);
      recApply(a, b, v, 2 * i + 1, im, ib);
      seg[i] = min(seg[2 * i], seg[2 * i + 1]) + tag[i];
    }
  }

 public:
  SegTree(int n) {
    while (h < n) h *= 2;
    seg.resize(2 * h, 0);
    tag.resize(h, 0);
  }
  ll rangeMin(int a, int b) { return recGet(a, b + 1, 1, 0, h); }
  void rangeAdd(int a, int b, ll v) { recApply(a, b + 1, v, 1, 0, h); }
};
void solve() {
  int n, k;
  cin >> n >> k;
  if (k <= H) {
    cout << dp[k][n] << '\n';
  } else {
    cout << n << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  vector<vector<pair<int, int>>> upd(N + 1);
  for (int i = 1; i <= N; ++i) {
    upd[i].emplace_back(i - 1, 1);
    for (int j = 2; i * j <= N; ++j) {
      upd[i * j].emplace_back(i - 1, j - 1);
    }
  }
  for (int i = 1; i <= N; ++i) dp[0][i] = INF;
  ll cur = 0;
  for (int i = 1; i <= N; ++i) {
    for (auto pr : upd[i]) cur += pr.second;
    dp[1][i] = cur;
  }
  for (int k = 2; k <= H; ++k) {
    SegTree seg(N + 1);
    for (int i = 1; i <= N; ++i) {
      for (auto pr : upd[i]) seg.rangeAdd(0, pr.first, pr.second);
      dp[k][i] = seg.rangeMin(0, i - 1);
      seg.rangeAdd(i, i, dp[k - 1][i]);
    }
  }
  int q;
  cin >> q;
  for (int qi = 0; qi < q; ++qi) solve();
}
