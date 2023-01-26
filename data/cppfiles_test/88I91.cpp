#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int inf = 1e9;
const int N = 3e5 + 9;
bool comp(pair<int, int> a, pair<int, int> b) {
  if (a.first < b.first)
    return 1;
  else if (a.first == b.first)
    return b.second < a.second;
  return 0;
}
struct segtree {
  int size;
  vector<long long> tree;
  void init(int n) {
    size = 1;
    while (size < n) size *= 2;
    tree.assign(2 * size, 0LL);
  }
  int merge(int u, int v) { return u + v; }
  void update(int x, int lx, int rx, int i, int v) {
    if (lx == rx) {
      tree[x] = v;
      return;
    }
    int mid = (lx + rx) / 2;
    if (i <= mid)
      update(2 * x, lx, mid, i, v);
    else
      update(2 * x + 1, mid + 1, rx, i, v);
    tree[x] = merge(tree[2 * x], tree[2 * x + 1]);
  }
  long long query(int l, int r, int x, int lx, int rx) {
    if (lx > r || rx < l) return 0LL;
    if (lx >= l && rx <= r) return tree[x];
    int mid = (lx + rx) / 2;
    int s1 = query(l, r, 2 * x, lx, mid);
    int s2 = query(l, r, 2 * x + 1, mid + 1, rx);
    return merge(s1, s2);
  }
};
void solve() {
  int n, m;
  cin >> n >> m;
  int sz = n * m + 1;
  vector<pair<int, int>> v;
  map<int, deque<int>> mp;
  for (int j = 1; j <= n; j++)
    for (int i = 1; i <= m; i++) {
      int x;
      cin >> x;
      mp[x].push_back((j - 1) * m + i);
      v.push_back({x, (j - 1) * m + i});
    }
  sort(v.begin(), v.end(), comp);
  vector<int> vis(n * m + 5, 0);
  int idx = 0;
  int ans = 0;
  int a[n + 1][m + 1];
  for (int i = 1; i <= n; i++) {
    segtree st;
    st.init(sz);
    for (int j = 1; j <= m; j++) {
    read:
      while (vis[v[idx].second]) idx++;
      auto now = v[idx];
      int x = now.first;
      if (j == 1 and mp[x].size() >= m) {
        for (int k = 0; k < m; k++) {
          vis[mp[x].front()] = 1;
          mp[x].pop_front();
        }
        break;
      }
      while (mp[x].size() && vis[mp[x].front()]) mp[x].pop_front();
      while (mp[x].size() && vis[mp[x].back()]) mp[x].pop_back();
      if (mp[x].empty()) goto read;
      int front = mp[x].front(), back = mp[x].back();
      if (st.query(1, front, 1, 1, sz) < st.query(1, back, 1, 1, sz)) {
        ans += st.query(1, front, 1, 1, sz);
        st.update(1, 1, sz, front, 1);
        mp[x].pop_front();
        vis[front] = 1;
        continue;
      } else {
        ans += st.query(1, back, 1, 1, sz);
        st.update(1, 1, sz, back, 1);
        mp[x].pop_back();
        vis[back] = 1;
        continue;
      }
    }
  }
  cout << ans << "\n";
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
