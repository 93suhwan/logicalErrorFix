#include <bits/stdc++.h>
using namespace std;
const int maxn = 312345;
struct Seg {
  int l, r;
  bool lzy;
  pair<int, int> v;
} T[maxn << 3];
vector<pair<int, int> > G[maxn];
int nxt[maxn];
bool ans[maxn];
void build(int o, int l, int r) {
  T[o].l = l, T[o].r = r;
  T[o].v = {0, -1};
  if (l < r) {
    int mi = l + r >> 1;
    build(o << 1, l, mi);
    build(o << 1 | 1, mi + 1, r);
  }
}
void push_down(int o) {
  if (T[o].lzy) {
    T[o << 1].v = T[o << 1 | 1].v = T[o].v;
    T[o << 1].lzy = T[o << 1 | 1].lzy = true;
    T[o].lzy = false;
  }
}
pair<int, int> query(int o, int l, int r) {
  if (l <= T[o].l && T[o].r <= r) return T[o].v;
  push_down(o);
  int mi = T[o].l + T[o].r >> 1;
  pair<int, int> ret = {0, -1};
  if (l <= mi) ret = max(ret, query(o << 1, l, r));
  if (r > mi) ret = max(ret, query(o << 1 | 1, l, r));
  return ret;
}
void update(int o, int l, int r, pair<int, int> v) {
  if (l <= T[o].l && T[o].r <= r) {
    T[o].lzy = true;
    T[o].v = v;
    return;
  }
  int mi = T[o].l + T[o].r >> 1;
  if (l <= mi) update(o << 1, l, r, v);
  if (r > mi) update(o << 1 | 1, l, r, v);
  T[o].v = max(T[o << 1].v, T[o << 1 | 1].v);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<int> tmp;
  for (int(i) = (1); (i) <= (m); (i)++) {
    int id, l, r;
    cin >> id >> l >> r;
    G[id].emplace_back(l, r);
    tmp.emplace_back(l);
    tmp.emplace_back(r);
  }
  sort((tmp).begin(), (tmp).end());
  (tmp).erase(unique((tmp).begin(), (tmp).end()), (tmp).end());
  auto loc = [&](int x) {
    return lower_bound((tmp).begin(), (tmp).end(), x) - tmp.begin() + 1;
  };
  for (int(i) = (1); (i) <= (n); (i)++)
    for (auto &[x, y] : G[i]) {
      x = loc(x);
      y = loc(y);
    }
  build(1, 1, tmp.size());
  for (int(i) = (1); (i) <= (n); (i)++) {
    pair<int, int> cur = {0, -1};
    for (auto [l, r] : G[i]) cur = max(cur, query(1, l, r));
    nxt[i] = cur.second;
    cur.first++, cur.second = i;
    for (auto [l, r] : G[i]) update(1, l, r, cur);
  }
  pair<int, int> mx = query(1, 1, tmp.size());
  cout << n - mx.first << '\n';
  for (int i = mx.second; i != -1; i = nxt[i]) ans[i] = true;
  for (int(i) = (1); (i) <= (n); (i)++)
    if (!ans[i]) cout << i << ' ';
}
