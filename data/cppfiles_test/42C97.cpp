#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const int N = 1e6 + 10;
const double eps = 1e-8;
int n, m;
int minv[N << 2], tag[N << 2];
vector<pair<int, pair<int, int>>> v;
void push_down(int u) {
  if (tag[u]) {
    tag[(u << 1)] = tag[((u << 1) | 1)] = tag[u];
    minv[(u << 1)] = minv[((u << 1) | 1)] = tag[u];
    tag[u] = 0;
  }
}
void modify(int u, int tl, int tr, int L, int R, int d) {
  if (tl >= L && tr <= R)
    minv[u] = tag[u] = d;
  else {
    push_down(u);
    if (L <= ((tl + tr) >> 1)) modify((u << 1), tl, ((tl + tr) >> 1), L, R, d);
    if (R > ((tl + tr) >> 1))
      modify(((u << 1) | 1), ((tl + tr) >> 1) + 1, tr, L, R, d);
    minv[u] = min(minv[(u << 1)], minv[((u << 1) | 1)]);
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  m--;
  for (int i = 1; i <= n; ++i) {
    int l, r, w;
    cin >> l >> r >> w;
    r--;
    v.push_back({w, {l, r}});
  }
  sort(v.begin(), v.end());
  int res = INF;
  for (auto seg : v) {
    modify(1, 1, m, seg.second.first, seg.second.second, seg.first);
    if (minv[1]) res = min(res, seg.first - minv[1]);
  }
  cout << res << endl;
  return 0;
}
