#include <bits/stdc++.h>
using namespace std;
const int mxN = 2e5 + 5;
vector<int> a[mxN];
int tree[4 * mxN];
void update(int x, int lx, int rx, int i, int v) {
  if (lx == rx) {
    tree[x] = max(tree[x], v);
    return;
  }
  int mx = (lx + rx) >> 1;
  if (i <= mx)
    update(x << 1, lx, mx, i, v);
  else
    update(x << 1 | 1, mx + 1, rx, i, v);
  tree[x] = max(tree[x << 1], tree[x << 1 | 1]);
}
int query(int x, int lx, int rx, int l, int r) {
  if (l > rx || lx > r) return 0;
  if (l <= lx && r >= rx) return tree[x];
  int mx = (lx + rx) >> 1;
  return max(query(x << 1, lx, mx, l, r), query(x << 1 | 1, mx + 1, rx, l, r));
}
void testCase() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    a[x].push_back(i);
  }
  for (int i = 1; i <= n; i++) {
    reverse(a[i].begin(), a[i].end());
    vector<int> ans(a[i].size());
    for (int j = 0; j < a[i].size(); j++) {
      if (i - a[i][j] > 0) continue;
      ans[j] = query(1, 1, n, 1, a[i][j] - i + 1) + 1;
    }
    for (int j = 0; j < a[i].size(); j++) {
      if (i - a[i][j] > 0) continue;
      update(1, 1, n, a[i][j] - i + 1, ans[j]);
    }
  }
  cout << query(1, 1, n, 1, n) << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  testCase();
  return 0;
}
