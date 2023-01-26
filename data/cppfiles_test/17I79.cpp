#include <bits/stdc++.h>
using namespace std;
void update(int node, int start, int end, int pos, int value,
            vector<int>& tree) {
  if (start == end) {
    tree[node] += value;
  } else {
    int mid = (start + end) / 2;
    if (start <= pos && pos <= mid) {
      update(2 * node, start, mid, pos, value, tree);
    } else {
      update(2 * node + 1, mid + 1, end, pos, value, tree);
    }
    tree[node] = tree[2 * node] + tree[2 * node + 1];
  }
}
int query(int node, int start, int end, int l, int r, vector<int>& tree) {
  if (l > r)
    return 0;
  else if (start > r || end < l) {
    return 0;
  } else if (l <= start && end <= r) {
    return tree[node];
  } else {
    int mid = (start + end) / 2;
    int left = query(2 * node, start, mid, l, r, tree);
    int right = query(2 * node + 1, mid + 1, end, l, r, tree);
    return left + right;
  }
}
void solve() {
  int n;
  cin >> n;
  vector<int> a(n, 0);
  vector<pair<int, int>> vv;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    vv.push_back({a[i], i});
  }
  sort(vv.begin(), vv.end());
  int curr = 1;
  for (int i = 0; i < n; i++) {
    if (i == 0) {
      a[vv[i].second] = curr;
    } else {
      if (vv[i].first == vv[i - 1].first) {
        a[vv[i].second] = curr;
      } else {
        curr++;
        a[vv[i].second] = curr;
      }
    }
  }
  vector<int> tree(4 * n, 0);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans += min(query(1, 0, n - 1, 0, a[i] - 2, tree),
               query(1, 0, n - 1, a[i], n - 1, tree));
    update(1, 0, n - 1, a[i] - 1, 1, tree);
  }
  cout << ans << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
