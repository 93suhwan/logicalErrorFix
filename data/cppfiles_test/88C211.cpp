#include <bits/stdc++.h>
using namespace std;
struct SegTree {
  vector<int> tree;
  SegTree(vector<int> &a) {
    int n = 1;
    while (n < a.size()) {
      n *= 2;
    }
    while (a.size() != n) {
      a.push_back(0);
    }
    tree.resize(n * 2);
    for (int i = n; i < 2 * n; ++i) {
      tree[i] = a[i - n];
    }
    for (int i = n - 1; i >= 1; --i) {
      tree[i] = tree[i * 2] + tree[i * 2 + 1];
    }
  }
  int get_sum(int l, int r, int x, int y, int ind) {
    if (x <= l && y >= r) {
      return tree[ind];
    }
    if (y <= l || x >= r) {
      return 0;
    }
    int mid = (r + l) / 2;
    return get_sum(l, mid, x, y, ind * 2) + get_sum(mid, r, x, y, ind * 2 + 1);
  }
  void change(int ind, int l, int r, int x, int pos) {
    if (l + 1 == r) {
      tree[ind] = x;
      return;
    }
    int mid = (l + r) / 2;
    if (pos < mid) {
      change(ind * 2, l, mid, x, pos);
    } else {
      change(ind * 2 + 1, mid, r, x, pos);
    }
    tree[ind] = tree[ind * 2] + tree[ind * 2 + 1];
  }
};
int mex(string a) {
  int ans = 0;
  for (int i = 0; i < a.size(); ++i) {
    if (a[i] == '0' && ans == 0) {
      ans = 1;
    }
    if (a[i] == '1' && ans == 1) {
      ans = 2;
    }
  }
  return ans;
}
bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
  if (a.first.first == b.first.first) {
    if (a.second == b.second) {
      return a.first.second > b.first.second;
    }
    return a.second < b.second;
  }
  return a.first.first < b.first.first;
}
bool cmp1(pair<int, int> a, pair<int, int> b) {
  if (a.first == b.first) {
    return a.second > b.second;
  }
  return a.first < b.first;
}
int main() {
  int t;
  cin >> t;
  for (int z = 0; z < t; ++z) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n * m);
    vector<pair<pair<int, int>, int>> b(n * m);
    vector<pair<int, int>> b1(n * m);
    for (int i = 0; i < n * m; ++i) {
      cin >> a[i];
      b[i] = {{a[i], i}, i / m};
      b1[i] = {a[i], i};
    }
    sort(b1.begin(), b1.end());
    for (int i = 0; i < n * m; ++i) {
      b[b1[i].second].second = i / m;
    }
    vector<pair<int, int>> c(n * m);
    sort(b.begin(), b.end(), cmp);
    for (int i = 0; i < n * m; ++i) {
      c[b[i].first.second] = {b[i].first.first, i};
    }
    vector<vector<int>> trees_arrays(n, vector<int>(m));
    vector<SegTree> trees;
    for (int i = 0; i < n; ++i) {
      trees.push_back(SegTree(trees_arrays[i]));
    }
    int ans = 0;
    for (int i = 0; i < n * m; ++i) {
      int j = c[i].second / m;
      ans += trees[j].get_sum(1, trees[j].tree.size() / 2 + 1, 1,
                              c[i].second - (j * m) + 1, 1);
      trees[j].change(1, 1, trees[j].tree.size() / 2 + 1, 1,
                      c[i].second - (j * m) + 1);
    }
    cout << ans << '\n';
  }
}
