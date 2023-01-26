#include <bits/stdc++.h>
using namespace std;
const int maxsize = 600005;
vector<pair<int, int>> tree(4 * maxsize + 10, {0, -1});
vector<pair<int, int>> d(4 * maxsize, {-1, -1});
void push(int p) {
  if (d[p].first != -1) {
    tree[2 * p + 1] =
        (d[p].first > tree[2 * p + 1].first) ? d[p] : tree[2 * p + 1];
    tree[2 * p + 2] =
        (d[p].first > tree[2 * p + 2].first) ? d[p] : tree[2 * p + 2];
    d[2 * p + 1] = d[p];
    d[2 * p + 2] = d[p];
    d[p] = {-1, -1};
  }
}
pair<int, int> get_ans(int p, int l, int r, int x, int y) {
  if (l >= y or r <= x) return {0, -1};
  if (l >= x and r <= y) return tree[p];
  int m = (l + r) >> 1;
  push(p);
  auto t1 = get_ans(2 * p + 1, l, m, x, y), t2 = get_ans(2 * p + 2, m, r, x, y);
  return (t1.first > t2.first) ? t1 : t2;
}
void rebuild(int p, int l, int r, int x, int y, pair<int, int> v) {
  if (l >= y or r <= x) return;
  if (l >= x and r <= y) {
    tree[p] = (v.first > tree[p].first) ? v : tree[p];
    d[p] = v;
    return;
  }
  int m = (l + r) >> 1;
  push(p);
  rebuild(2 * p + 1, l, m, x, y, v), rebuild(2 * p + 2, m, r, x, y, v);
  tree[p] = (tree[2 * p + 1].first > tree[2 * p + 2].first) ? tree[2 * p + 1]
                                                            : tree[2 * p + 2];
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> a[n];
  set<int> s;
  for (int i = 0; i < m; i++) {
    int t, x, y;
    cin >> t >> x >> y;
    t--;
    x--;
    s.insert(x);
    s.insert(y);
    a[t].push_back({x, y});
  }
  map<int, int> mp;
  int tt = 0;
  for (int x : s) mp[x] = tt++;
  for (int i = 0; i < n; i++) {
    for (auto &v : a[i]) v = {mp[v.first], mp[v.second]};
  }
  int ans = 0, en = 0;
  vector<int> predok(n, -1);
  for (int i = 0; i < n; i++) {
    int res = 0;
    for (auto v : a[i]) {
      auto x = get_ans(0, 0, maxsize, v.first, v.second);
      if (x.first + 1 > res) {
        res = x.first + 1;
        predok[i] = x.second;
      }
      if (res > ans) {
        ans = res;
        en = i;
      }
    }
    for (auto v : a[i]) rebuild(0, 0, maxsize, v.first, v.second, {res, i});
  }
  int x = en;
  map<int, bool> q;
  while (x != -1) {
    q[x] = 1;
    x = predok[x];
  }
  cout << n - ans << "\n";
  for (int i = 0; i < n; i++) {
    if (!q[i]) cout << i + 1 << " ";
  }
  return 0;
}
