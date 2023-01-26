#include <bits/stdc++.h>
using namespace std;
const int mxn = 1e6, inf = ~(1 << 31);
int seg[mxn << 1], lzy[mxn << 1];
int ll[mxn], rr[mxn], ww[mxn], idx[mxn];
int leftt(int x, int xl, int xr) { return x + 1; }
int right(int x, int xl, int xr) { return x + xr - xl - ((xl - xr) & 1); }
void push(int x, int xl, int xr) {
  if (xl + 1 == xr) return;
  int _leftt = leftt(x, xl, xr);
  int _right = right(x, xl, xr);
  lzy[_right] += lzy[x];
  lzy[_leftt] += lzy[x];
  seg[_leftt] += lzy[x];
  seg[_right] += lzy[x];
  lzy[x] = 0;
}
void update(int x, int xl, int xr, int l, int r, int val) {
  if (xl >= r || l >= xr) return;
  if (xl >= l && r >= xr) {
    seg[x] += val;
    lzy[x] += val;
    return;
  }
  push(x, xl, xr);
  update(leftt(x, xl, xr), xl, (xl + xr) >> 1, l, r, val);
  update(right(x, xl, xr), (xl + xr) >> 1, xr, l, r, val);
  seg[x] = min(seg[leftt(x, xl, xr)], seg[right(x, xl, xr)]);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int Tests = 1;
  for (int Test = 1; Test <= Tests; ++Test) {
    ;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> ll[i] >> rr[i] >> ww[i];
    iota(idx, idx + n, 0);
    sort(idx, idx + n, [&](int a, int b) { return ww[a] < ww[b]; });
    int ptr1 = 0, ptr2 = 0, ans = inf;
    ;
    update(0, 0, m, 0, 1, 1);
    while (ptr1 < n && ptr2 < n) {
      while (ptr2 < n && seg[0] == 0) {
        update(0, 0, m, ll[idx[ptr2]], rr[idx[ptr2]], 1);
        ptr2++;
      }
      if (!seg[0]) break;
      ;
      ;
      ans = min(ans, ww[idx[ptr2 - 1]] - ww[idx[ptr1]]);
      update(0, 0, m, ll[idx[ptr1]], rr[idx[ptr1]], -1);
      ptr1++;
    }
    cout << ans << endl;
  }
  return 0;
}
