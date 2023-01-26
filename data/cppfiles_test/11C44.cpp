#include <bits/stdc++.h>
using namespace std;
template <typename T>
struct BottomUpSegmentTree {
  int n;
  int N;
  vector<T> tree;
  T (*merge)(T, T);
  T defaultValue;
  BottomUpSegmentTree(int n, T defaultValue, T (*merge)(T, T)) {
    this->n = n;
    this->N = 2 * n;
    this->merge = merge;
    this->defaultValue = defaultValue;
    tree = vector<T>(N, defaultValue);
  }
  BottomUpSegmentTree(vector<T>& arr, T defaultValue, T (*merge)(T, T))
      : BottomUpSegmentTree(arr.size(), defaultValue, merge) {
    build(arr);
  }
  void build(vector<T>& arr) {
    for (int i = 0; i < n; i++) tree[n + i] = arr[i];
    for (int i = n - 1; i > 0; --i)
      tree[i] = merge(tree[i << 1], tree[i << 1 | 1]);
  }
  void updateTreeNode(int p, T value) {
    tree[p + n] = value;
    p = p + n;
    for (int i = p; i > 1; i >>= 1) tree[i >> 1] = merge(tree[i], tree[i ^ 1]);
  }
  T query(int l, int r) {
    T res = defaultValue;
    r++;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) res = merge(res, tree[l++]);
      if (r & 1) res = merge(res, tree[--r]);
    }
    return res;
  }
};
int merge(int x1, int x2) { return max(x1, x2); }
int main() {
  int n;
  scanf("%d", &n);
  vector<int> nums(n);
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", &nums[i]);
    if (nums[i] - i - 1 <= 0) cnt++;
  }
  vector<pair<int, int>> arr(cnt);
  cnt = 0;
  for (int i = 0; i < n; i++) {
    if (nums[i] - i - 1 <= 0) {
      arr[cnt] = {nums[i], -i};
      cnt++;
    }
  }
  vector<int> dp(cnt, 1);
  int ans = 0;
  sort(arr.begin(), arr.end());
  BottomUpSegmentTree<int> tree(n, 0, merge);
  for (int i = 0; i < cnt; i++) {
    int index = -arr[i].second - arr[i].first + 1;
    int val;
    if (index >= 0)
      val = tree.query(0, index);
    else
      val = 0;
    if (dp[i] <= val) dp[i] = val + 1;
    ans = max(ans, dp[i]);
    tree.updateTreeNode(index, dp[i]);
  }
  printf("%d", ans);
  return 0;
}
