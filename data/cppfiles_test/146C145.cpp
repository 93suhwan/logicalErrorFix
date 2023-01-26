#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, magic = sqrt(N);
int p[N], r[N], J[N];
int jump(int i, int z = magic) {
  int k = i;
  for (int j = 1; j <= z; j++) {
    k = p[k];
    if (k == i) return -1;
  }
  return k;
}
int recalc(int x) {
  int y = jump(x);
  if (y < 0) return 0;
  for (int j = 1; j <= magic + 10; j++) {
    J[x] = y;
    x = r[x];
    y = r[y];
  }
  return 1;
}
void dfs_small(int v, int s, vector<int> &cycle) {
  if (v == s and cycle.size()) return;
  cycle.push_back(v);
  dfs_small(p[v], s, cycle);
}
int32_t main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) {
    cin >> p[i];
    r[p[i]] = i;
  }
  for (int i = 1; i <= n; i++) {
    J[i] = jump(i);
  }
  for (int i = 1; i <= q; i++) {
    int t;
    cin >> t;
    if (t == 1) {
      int x, y;
      cin >> x >> y;
      swap(r[p[x]], r[p[y]]);
      swap(p[x], p[y]);
      recalc(x);
      recalc(y);
    } else {
      int j, k;
      cin >> j >> k;
      if (jump(j) == -1) {
        vector<int> cycle;
        dfs_small(j, j, cycle);
        int len = cycle.size();
        cout << cycle[k % len] << endl;
      } else {
        while (k >= magic) {
          j = J[j];
          k -= magic;
        }
        cout << jump(j, k) << endl;
      }
    }
  }
}
