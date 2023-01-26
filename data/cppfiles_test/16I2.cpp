#include <bits/stdc++.h>
using std::pair;
const int maxn = 2e5 + 10;
int n, a[maxn], id[maxn];
std::vector<pair<int, int> > ans;
inline void solve() {
  ans.clear();
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
    id[i] = i;
  }
  std::sort(id + 1, id + n + 1, [&](int x, int y) { return a[x] < a[y]; });
  int i = n - 1, j = n;
  while (i > 0) {
    while (a[id[i]] && a[id[j]]) {
      --a[id[i]], --a[id[j]];
      ans.push_back(pair<int, int>(id[i], id[j]));
    }
    while (i > 0 && !a[id[i]]) --i;
    while (j > 1 && !a[id[j]]) {
      --j;
      i = j - 1;
    }
  }
  printf("%u\n", ans.size());
  for (pair<int, int> e : ans) printf("%d %d\n", e.first, e.second);
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
