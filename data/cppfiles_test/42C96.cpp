#include <bits/stdc++.h>
using namespace std;
const int N = 1001000;
const int M = 4 * N;
const int inf = 1e9;
int n, k, m;
int tree[M], lazy[M];
void update(int i, int j, int x, int idx = 1, int l = 0, int r = n - 1) {
  if (lazy[idx]) {
    tree[idx] += lazy[idx];
    if (r > l) {
      lazy[(idx << 1)] += lazy[idx];
      lazy[(idx << 1 | 1)] += lazy[idx];
    }
    lazy[idx] = 0;
  }
  if (j < l || i > r) return;
  if (l >= i && r <= j) {
    tree[idx] += x;
    if (r > l) {
      lazy[(idx << 1)] += x;
      lazy[(idx << 1 | 1)] += x;
    }
    return;
  }
  update(i, j, x, (idx << 1), l, ((l + r) >> 1));
  update(i, j, x, (idx << 1 | 1), ((l + r) >> 1) + 1, r);
  tree[idx] = min(tree[(idx << 1)], tree[(idx << 1 | 1)]);
}
int queryMin(int i, int j, int idx = 1, int l = 0, int r = n - 1) {
  if (lazy[idx] != 0) {
    tree[idx] += lazy[idx];
    if (r > l) {
      lazy[(idx << 1)] += lazy[idx];
      lazy[(idx << 1 | 1)] += lazy[idx];
    }
    lazy[idx] = 0;
  }
  if (i > r || j < l) return inf;
  if (i <= l && j >= r) return tree[idx];
  return min(queryMin(i, j, (idx << 1), l, ((l + r) >> 1)),
             queryMin(i, j, (idx << 1 | 1), ((l + r) >> 1) + 1, r));
}
pair<int, pair<int, int>> p[300300];
int main() {
  cin >> m >> n;
  for (int i = 0; i < m; i++) {
    int l, r, w;
    cin >> l >> r >> w;
    r--;
    p[i].first = w;
    p[i].second.first = l;
    p[i].second.second = r;
    update(l, r, 1);
  }
  sort(p, p + m);
  long long l = 0, r = m - 1;
  for (int i = 0; i < m; i++) {
    update(p[i].second.first, p[i].second.second, -1);
    if (queryMin(1, n - 1) == 0) {
      update(p[i].second.first, p[i].second.second, 1);
      l = i - 1;
      break;
    }
  }
  int ans = p[m - 1].first - p[l + 1].first;
  while (l < r) {
    if (queryMin(1, n - 1) == 0) {
      if (l < 0) break;
      update(p[l].second.first, p[l].second.second, 1);
      l--;
    } else {
      ans = min(ans, p[r].first - p[l + 1].first);
      update(p[r].second.first, p[r].second.second, -1);
      r--;
    }
  }
  cout << ans << endl;
  return 0;
}
