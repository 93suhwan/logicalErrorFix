#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 10;
int n, m, k;
void solve() {
  scanf("%d%d%d", &n, &m, &k);
  vector<vector<int>> res;
  int cnt = n / m;
  int idx = 1;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < k; j++) {
      vector<int> cur;
      for (int j = 0; j < cnt; j++) cur.push_back(idx++);
      if (idx > n) idx = 1;
      res.push_back(cur);
    }
  }
  if (n % m) {
    int p = n % m;
    int idx = 0;
    for (int _i = 0; _i < k; _i++) {
      for (int i = n - p + 1, j = _i % m; i <= n; i++) {
        res[m * _i + j].push_back(i);
        int last = m * _i + j;
        j++;
        if (j >= m) j = 0;
        if (_i > k / 2) {
          swap(res[last][cnt], res[m * _i + j][idx]);
          if (++idx == cnt) idx = 0;
        }
      }
    }
  }
  for (auto it : res) {
    printf("%d ", it.size());
    for (int i : it) printf("%d ", i);
    puts("");
  }
  puts("");
}
int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
