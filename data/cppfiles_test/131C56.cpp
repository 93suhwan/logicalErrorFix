#include <bits/stdc++.h>
using namespace std;
struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
unordered_map<int, int, custom_hash> present_vals;
unordered_map<int, unordered_set<int>, custom_hash> children;
unordered_map<int, pair<int, int>, custom_hash> deepest_child;
int best = -1;
int l, r;
int parent(int k) {
  if (k <= 1) return 0;
  return (1 << (32 - __builtin_clz(k - 1))) - k;
}
void dfs(int v) {
  vector<pair<int, int>> childrenvals;
  for (int u : children[v]) {
    dfs(u);
    childrenvals.push_back(deepest_child[u]);
  }
  if (childrenvals.size() > 1) {
    nth_element(childrenvals.begin(), childrenvals.begin() + 1,
                childrenvals.end(), greater<pair<int, int>>());
    if (childrenvals[0].first + childrenvals[1].first > best) {
      best = childrenvals[0].first + childrenvals[1].first;
      l = childrenvals[0].second;
      r = childrenvals[1].second;
    }
  }
  if (childrenvals.size()) {
    deepest_child[v] = {childrenvals[0].first + 1, childrenvals[0].second};
    if (present_vals.count(v)) {
      if (childrenvals[0].first > best) {
        best = childrenvals[0].first;
        l = childrenvals[0].second;
        r = present_vals[v];
      }
    }
  } else {
    assert(present_vals.count(v));
    deepest_child[v] = {1, present_vals[v]};
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  map<int, pair<int, int>> farthest;
  for (int i = 1; i <= n; i++) {
    int a;
    cin >> a;
    present_vals[a] = i;
    while (1) {
      if (!a) break;
      children[parent(a)].insert(a);
      a = parent(a);
    }
  }
  dfs(0);
  cout << l << " " << r << " " << best << endl;
}
