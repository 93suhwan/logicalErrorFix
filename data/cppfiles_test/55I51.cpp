#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 7;
long long gcd(long long a, long long b) { return a == 0 ? b : gcd(b % a, a); }
long long exgcd(long long a, long long b, long long& x, long long& y) {
  if (b == 0) {
    x = 1, y = 0;
    return a;
  } else {
    long long r = exgcd(b, a % b, x, y), t = x;
    x = y;
    y = t - a / b * x;
    return r;
  }
}
int tr[N * 4], pos[N * 4];
inline int lc(int x) { return x << 1; }
inline int rc(int x) { return x << 1 | 1; }
void pu(int t) {
  tr[t] = tr[lc(t)];
  pos[t] = pos[lc(t)];
  if (tr[t] < tr[rc(t)]) {
    tr[t] = tr[rc(t)];
    pos[t] = pos[rc(t)];
  }
}
pair<int, int> query(int t, int l, int r, int ql, int qr) {
  if (ql <= l && r <= qr) {
    return make_pair(tr[t], pos[t]);
  } else {
    pair<int, int> res = make_pair(0, 0);
    int m = l + r >> 1;
    if (ql <= m) {
      pair<int, int> p = query(lc(t), l, m, ql, qr);
      if (p.first > res.first) res = p;
    }
    if (qr > m) {
      pair<int, int> p = query(rc(t), m + 1, r, ql, qr);
      if (p.first > res.first) res = p;
    }
    return res;
  }
}
void upd(int t, int l, int r, int p, int x, int id) {
  if (l == r) {
    if (tr[t] < x) {
      pos[t] = id;
      tr[t] = x;
    }
    return;
  } else {
    int m = l + r >> 1;
    if (p <= m) upd(lc(t), l, m, p, x, id);
    if (p > m) upd(rc(t), m + 1, r, p, x, id);
    pu(t);
  }
}
vector<pair<int, int> > g[N];
vector<pair<int, pair<int, int> > > d;
vector<int> alls;
int bp[N];
int gt(int x) {
  return lower_bound(alls.begin(), alls.end(), x) - alls.begin() + 1;
}
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int id, l, r;
    cin >> id >> l >> r;
    d.push_back(make_pair(id, make_pair(l, r)));
  }
  sort(d.begin(), d.end());
  for (int i = 0; i < m; i++) {
    int id, l, r;
    id = d[i].first, l = d[i].second.first, r = d[i].second.second;
    if (g[id].size() == 0 || g[id].back().second + 1 < l)
      g[id].push_back(make_pair(l, r));
    else
      g[id].back().second = max(g[id].back().second, r);
    alls.push_back(l), alls.push_back(r);
  }
  sort(alls.begin(), alls.end());
  alls.erase(unique(alls.begin(), alls.end()), alls.end());
  int w = alls.size();
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < g[i].size(); j++) {
      g[i][j].first = gt(g[i][j].first);
      g[i][j].second = gt(g[i][j].second);
    }
  }
  pair<int, int> ans = make_pair(0, 0);
  set<int> st;
  for (int i = 1; i <= n; i++) {
    st.insert(i);
    pair<int, int> res2 = make_pair(0, 0);
    for (int j = 0; j < g[i].size(); j++) {
      int l = g[i][j].first, r = g[i][j].second;
      pair<int, int> res = query(1, 1, w, l, r);
      res.first += 1;
      if (res.first > res2.first) res2 = res;
    }
    bp[i] = res2.second;
    for (int j = 0; j < g[i].size(); j++) {
      int l = g[i][j].first, r = g[i][j].second;
      upd(1, 1, w, l, res2.first, i);
      upd(1, 1, w, r, res2.first, i);
    }
    if (res2.first > ans.first) ans = res2, ans.second = i;
  }
  while (ans.second) {
    st.erase(ans.second);
    ans.second = bp[ans.second];
  }
  cout << st.size() << '\n';
  for (auto x : st) {
    cout << x << ' ';
  }
}
