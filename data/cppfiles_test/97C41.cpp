#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
const int INF = 1e9 + 239;
struct Line {
  int first;
  int step;
  Line() {
    first = -INF;
    step = -INF;
  }
  Line(int k_, int b_) {
    first = k_;
    step = b_;
  }
  bool ok() const { return *this != Line(); }
  Line operator+(const Line &other) const {
    if (!ok()) {
      return other;
    }
    if (!other.ok()) {
      return *this;
    }
    return Line(first + other.first, step + other.step);
  }
  Line skip(int len) const { return Line(first + len * step, step); }
  bool operator==(const Line &other) const {
    return first == other.first && step == other.step;
  }
  bool operator!=(const Line &other) const { return !((*this) == other); }
};
struct Segment {
  int l;
  int r;
  int first;
  int step;
  Segment() {
    l = 0;
    r = 0;
    first = 0;
    step = 0;
  }
  Segment(int l_, int r_, int first_, int step_) {
    l = l_;
    r = r_;
    first = first_;
    step = step_;
  }
};
const int N = 2e5 + 7;
const int L = 20;
const Line NONE = Line();
namespace ST {
int a[N];
Line mod_set[4 * N];
Line mod_add[4 * N];
vector<int> mod_points;
void apply_set(int v, Line x) {
  mod_set[v] = x;
  mod_add[v] = NONE;
}
void apply_add(int v, Line x) {
  if (mod_set[v].ok()) {
    mod_set[v] = mod_set[v] + x;
  } else {
    mod_add[v] = mod_add[v] + x;
  }
}
void push(int v, int l, int r) {
  assert(l + 1 < r);
  if (mod_set[v].ok()) {
    int m = (r + l) >> 1;
    apply_set(2 * v + 1, mod_set[v]);
    apply_set(2 * v + 2, mod_set[v].skip(m - l));
  }
  mod_set[v] = NONE;
  if (mod_add[v].ok()) {
    int m = (r + l) >> 1;
    apply_add(2 * v + 1, mod_add[v]);
    apply_add(2 * v + 2, mod_add[v].skip(m - l));
  }
  mod_add[v] = NONE;
}
void set(int v, int l, int r, int ql, int qr, Line x) {
  if (qr <= l || r <= ql) {
    return;
  } else if (ql <= l && r <= qr) {
    apply_set(v, x);
  } else {
    push(v, l, r);
    int m = (r + l) >> 1;
    set(2 * v + 1, l, m, ql, qr, x);
    set(2 * v + 2, m, r, ql, qr, x.skip(m - l));
  }
}
void add(int v, int l, int r, int ql, int qr, Line x) {
  if (qr <= l || r <= ql) {
    return;
  } else if (ql <= l && r <= qr) {
    apply_add(v, x);
  } else {
    push(v, l, r);
    int m = (r + l) >> 1;
    add(2 * v + 1, l, m, ql, qr, x);
    add(2 * v + 2, m, r, ql, qr, x.skip(m - l));
  }
}
void eval(int v, int l, int r, int pos, int &ans) {
  if (l + 1 == r) {
    if (mod_set[v].ok()) {
      ans = mod_set[v].first;
    } else {
      if (mod_add[v].ok()) {
        ans = mod_add[v].first;
      } else {
        assert(false);
        ans = 0;
      }
    }
  } else {
    push(v, l, r);
    int m = (r + l) >> 1;
    if (pos < m) {
      eval(2 * v + 1, l, m, pos, ans);
    } else {
      eval(2 * v + 2, m, r, pos, ans);
    }
  }
}
void set(int l, int r, Line x) {
  mod_points.push_back(l);
  mod_points.push_back(r);
  x.first -= l * x.step;
  set(0, 0, N, l, r + 1, x);
}
void add(int l, int r, Line x) {
  mod_points.push_back(l);
  mod_points.push_back(r);
  x.first -= l * x.step;
  add(0, 0, N, l, r + 1, x);
}
int eval(int x) {
  if (x == N) return 0;
  int ans = 0;
  eval(0, 0, N, x, ans);
  return ans;
}
void clear() {
  set(0, N - 1, Line(0, 0));
  mod_points.clear();
  mod_points.push_back(0);
}
void max_eq(int val) {
  if (eval(N - 1) >= val) {
    return;
  }
  int c = N - 1;
  for (int i = L - 1; i >= 0; i--) {
    if (c - (1 << i) >= 0 && eval(c - (1 << i)) < val) {
      c -= (1 << i);
    }
  }
  set(c, N - 1, Line(val, 0));
}
void sub() { add(0, N - 1, Line(0, -1)); }
void add(Segment f) { add(f.l, f.r, Line(f.first, f.step)); }
vector<Segment> get_vals() {
  sort(mod_points.begin(), mod_points.end());
  mod_points.resize(unique(mod_points.begin(), mod_points.end()) -
                    mod_points.begin());
  vector<Segment> ans;
  for (int i = 0; i < (int)mod_points.size(); i++) {
    int l = mod_points[i];
    int r = N - 1;
    if (i + 1 < (int)mod_points.size()) {
      r = mod_points[i + 1] - 1;
    }
    ans.push_back(Segment(l, r, eval(l), eval(l + 1) - eval(l)));
  }
  return ans;
}
}  // namespace ST
int sz[N];
vector<int> fg[N];
vector<int> sg[N];
void dfs_init(int cur, int p) {
  sz[cur] = 1;
  for (auto t : fg[cur]) {
    if (t != p) {
      dfs_init(t, cur);
      sz[cur] += sz[t];
      sg[cur].push_back(t);
    }
  }
  sort(sg[cur].begin(), sg[cur].end(),
       [&](int i, int j) { return sz[i] > sz[j]; });
}
int ans[N];
vector<pair<int, int *>> queries[N];
void dfs_solve(int cur) {
  if (sg[cur].empty()) {
    return;
  }
  vector<Segment> cadd;
  for (int i = 1; i < (int)sg[cur].size(); i++) {
    int t = sg[cur][i];
    ST::clear();
    dfs_solve(t);
    ST::sub();
    ST::max_eq(1);
    auto tmp = ST::get_vals();
    for (auto seg : tmp) {
      cadd.push_back(seg);
    }
  }
  {
    ST::clear();
    dfs_solve(sg[cur][0]);
    ST::sub();
    ST::max_eq(1);
    for (auto seg : cadd) {
      ST::add(seg);
    }
  }
  for (auto t : queries[cur]) {
    *t.second = ST::eval(t.first);
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i + 1 < n; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    fg[u].push_back(v);
    fg[v].push_back(u);
  }
  dfs_init(0, -1);
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int v, k;
    cin >> v >> k;
    v--;
    queries[v].push_back({k, &ans[i]});
  }
  dfs_solve(0);
  for (int i = 0; i < q; i++) {
    cout << ans[i] << '\n';
  }
}
