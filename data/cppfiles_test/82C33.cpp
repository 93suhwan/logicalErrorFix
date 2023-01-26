#include <bits/stdc++.h>
using namespace std;
stack<pair<int, int>> st[300005];
long long res[300005];
vector<pair<int, int>> rr[300005];
vector<int> ll[300005];
bool vis[300005];
int arr[300005];
int M = 1e9;
struct SegTree {
  vector<int> t;
  SegTree(int n) {
    t.resize(4 * n, 1e9);
    build(1, 1, n);
  }
  void build(int v, int tl, int tr) {
    if (tl == tr) {
      t[v] = arr[tl];
      return;
    }
    int tm = (tl + tr) / 2;
    build(v * 2, tl, tm), build(v * 2 + 1, tm + 1, tr);
    t[v] = min(t[v * 2], t[v * 2 + 1]);
  }
  int get(int v, int tl, int tr, int l, int r) {
    if (tr < l || r < tl) return 1e9;
    if (l <= tl && tr <= r) {
      return t[v];
    }
    int tm = (tl + tr) / 2;
    return min(get(v * 2, tl, tm, l, r), get(v * 2 + 1, tm + 1, tr, l, r));
  }
};
struct SegTree2 {
  vector<pair<long long, int>> t;
  SegTree2(int n) { t.resize(4 * n, {0, 0}); }
  void upd(int v, int tl, int tr, int pos, pair<int, int> val) {
    if (tl == tr) {
      t[v].first += 1ll * val.first * val.second;
      t[v].second += val.second;
      return;
    }
    int tm = (tl + tr) / 2;
    if (pos <= tm)
      upd(v * 2, tl, tm, pos, val);
    else
      upd(v * 2 + 1, tm + 1, tr, pos, val);
    t[v] = {t[v * 2].first + t[v * 2 + 1].first,
            t[v * 2].second + t[v * 2 + 1].second};
  }
  pair<long long, int> get(int v, int tl, int tr, int l, int r) {
    if (tr < l || r < tl) return {0, 0};
    if (l <= tl && tr <= r) {
      return t[v];
    }
    int tm = (tl + tr) / 2;
    auto a = get(v * 2, tl, tm, l, r);
    auto b = get(v * 2 + 1, tm + 1, tr, l, r);
    return {a.first + b.first, a.second + b.second};
  }
};
void solve() {
  int n, q, k;
  cin >> n >> q >> k;
  vector<int> compress;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    compress.push_back(arr[i]);
  }
  sort(compress.begin(), compress.end());
  compress.resize(unique(compress.begin(), compress.end()) - compress.begin());
  M = compress.size();
  map<int, int> cmp;
  for (int i = 0; i < M; i++) {
    cmp[compress[i]] = i + 1;
  }
  for (int i = 1; i <= q; i++) {
    int l, r;
    cin >> l >> r;
    r += (k - (-(l % k) + (r % k) + k) % k);
    if (r <= n) {
      rr[r].push_back({i, l});
    }
    ll[l].push_back(i);
  }
  SegTree tree(n);
  SegTree2 trees(M);
  for (int x = n; x >= 1; x--) {
    if (vis[x]) break;
    vector<pair<int, int>> cancel;
    for (int i = x; i >= 1; i -= k) {
      vis[i] = 1;
      int nxt = min(n, i + k - 1);
      int md = i % k;
      int tot = 0;
      int num = tree.get(1, 1, n, i, nxt);
      while (st[md].size() && st[md].top().first >= num) {
        tot += st[md].top().second;
        trees.upd(1, 1, M, cmp[st[md].top().first],
                  {st[md].top().first, -st[md].top().second});
        cancel.push_back({st[md].top().first, -st[md].top().second});
        st[md].pop();
      }
      if (num == arr[i]) {
        tot++;
      }
      st[md].push({num, tot});
      trees.upd(1, 1, M, cmp[num], {num, tot});
      cancel.push_back({num, tot});
      if (num != arr[i]) {
        tot = 1;
        num = arr[i];
        st[md].push({num, tot});
        trees.upd(1, 1, M, cmp[num], {num, tot});
        cancel.push_back({num, tot});
      }
      long long tmp = trees.get(1, 1, M, 1, M).first;
      for (auto u : ll[i]) {
        res[u] += tmp;
      }
      for (auto u : rr[i]) {
        int tmp1 = tree.get(1, 1, n, u.second, i - 1);
        auto x = trees.get(1, 1, M, cmp[tmp1], M);
        res[u.first] += x.first;
        res[u.first] -= 1ll * x.second * tmp1;
        res[u.first] -= tmp;
      }
    }
    for (auto u : cancel) {
      trees.upd(1, 1, M, cmp[u.first], {u.first, -u.second});
    }
  }
  for (int i = 1; i <= q; i++) cout << res[i] << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  while (t--) {
    solve();
  }
}
