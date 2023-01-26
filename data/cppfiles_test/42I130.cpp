#include <bits/stdc++.h>
using ll = long long;
using namespace std;
int n, m;
int const N = 3e5 + 2;
int const M = (1 << 21);
struct Triple {
  int fi;
  int se;
  int th;
  Triple(int f, int s, int t) : fi(f), se(s), th(t) {}
};
struct Compare {
  bool operator()(const Triple& f, const Triple& g) {
    if (f.th != g.th)
      return (f.th < g.th);
    else
      return pair<int, int>{f.fi, f.se} < pair<int, int>{g.fi, g.se};
  }
};
vector<Triple> seg;
int t[M];
int lazy[M];
int const INF = 1e9;
void push(int v) {
  t[v * 2] += lazy[v];
  lazy[v * 2] += lazy[v];
  t[v * 2 + 1] += lazy[v];
  lazy[v * 2 + 1] += lazy[v];
  lazy[v] = 0;
}
int query(int v, int l, int r, int tl, int tr) {
  if (r < l) return INF;
  if (l == tl && r == tr)
    return t[v];
  else {
    push(v);
    int mid = (tl + tr) / 2;
    int qw1 = query(v * 2, l, min(mid, r), tl, mid);
    int qw2 = query(v * 2 + 1, max(mid + 1, l), r, mid + 1, tr);
    return min(qw1, qw2);
  }
}
void update(int v, int l, int r, int tl, int tr, int val) {
  if (r < l) return;
  if (l == tl && r == tr) {
    t[v] += val;
    lazy[v] += val;
  } else {
    push(v);
    int mid = (tl + tr) >> 1;
    update(v << 1, l, min(mid, r), tl, mid, val);
    update((v << 1) + 1, max(mid + 1, l), r, mid + 1, tr, val);
    t[v] = min(t[v << 1], t[(v << 1) + 1]);
  }
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = (1); i <= (n); i++) {
    int l, r, w;
    scanf("%d %d %d", &l, &r, &w);
    seg.push_back(Triple({l, r, w}));
  }
  sort(seg.begin(), seg.end(), Compare());
  int mu = 0;
  int lb = seg[0].th;
  int rb = seg[0].th;
  int ans = INF;
  for (int i = (1); i <= (n); i++) {
    update(1, seg[i - 1].fi, seg[i - 1].se, 1, m, 1);
    rb = seg[i - 1].th;
    if (query(1, 1, m, 1, m) > 0) {
      ans = min(ans, rb - lb);
      while (seg[mu].th == lb) {
        update(1, seg[mu].fi, seg[mu].se, 1, m, -1);
        mu++;
      }
      lb = seg[mu].th;
    }
  }
  printf("%d", ans);
  return 0;
}
