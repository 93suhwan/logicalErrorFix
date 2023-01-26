#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
struct ST {
  vector<int> add;
  vector<int> tree;
  int base = 1;
  ST(int n = 1) {
    while (base <= n) base *= 2;
    add.assign(2 * base, 0);
    tree.assign(2 * base, 0);
  }
  void insert(int b, int e, int val) {
    b += base, e += base;
    tree[b] += val, tree[e] += (b != e ? val : 0);
    while (b > 1) {
      if (b / 2 != e / 2) {
        if (b % 2 == 0) tree[b + 1] += val, add[b + 1] += val;
        if (e % 2 == 1) tree[e - 1] += val, add[e - 1] += val;
      }
      b /= 2, e /= 2;
      tree[b] = min(tree[2 * b], tree[2 * b + 1]) + add[b];
      tree[e] = min(tree[2 * e], tree[2 * e + 1]) + add[e];
    }
  }
  int query(int b, int e) {
    b += base, e += base;
    int rb = tree[b], re = tree[e];
    while (b > 1) {
      if (b / 2 != e / 2) {
        if (b % 2 == 0) rb = min(rb, tree[b + 1]);
        if (e % 2 == 1) re = min(re, tree[e - 1]);
      }
      b /= 2, e /= 2;
      rb += add[b], re += add[e];
    }
    return min(rb, re);
  }
};
void query() {
  int n, m;
  cin >> n >> m;
  vector<string> t(n);
  for (auto& i : t) cin >> i;
  vector<vector<int>> col(n, vector<int>(m, 0));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      col[i][j] = (i > 0 ? col[i - 1][j] : 0) + t[i][j] - '0';
  int res = inf;
  for (int a = 5; a <= 5; a++) {
    for (int i = 0; i <= n - a; i++) {
      ST tree(m);
      for (int j = 0; j < m; j++) {
        int A = col[i + a - 2][j] - col[i][j];
        if (j - 3 >= 0) res = min(res, tree.query(0, j - 3) + a - 2 - A);
        if (j > 0)
          tree.insert(
              0, j - 1,
              A + 2 - (int)(t[i][j] - '0') - (int)(t[i + a - 1][j] - '0'));
        tree.insert(j, j, (a - 2 - A));
      }
    }
  }
  cout << res << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int q = 1;
  cin >> q;
  while (q--) query();
  return 0;
}
