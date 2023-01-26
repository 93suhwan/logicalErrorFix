#include <bits/stdc++.h>
using namespace std;
char ch[100005];
int n, m, ii, k;
set<int> have[100005];
bool col[100005];
bool func() {
  if (n > m) return true;
  for (int i = 0; i < m; i++) {
    if (have[i].size() > 1) return true;
  }
  return false;
}
void solve() {
  scanf("%d%d", &m, &n);
  vector<vector<int>> ar(m + 2);
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      scanf("%d", &k);
      ar[i - 1].push_back(k);
    }
  }
  int be = 1, en = 1e9;
  int re = be;
  while (be <= en) {
    int mid = (be + en) / 2;
    bool take = false;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (ar[i][j] >= mid) have[i].insert(j), col[j] = 1;
      }
    }
    for (int i = 0; i < n; i++) {
      if (col[i] == false) take = true;
      col[i] = 0;
    }
    if (func() && !take) {
      re = mid;
      be = mid + 1;
    } else
      en = mid - 1;
    for (int j = 0; j < m; j++) have[j].clear();
  }
  printf("%d\n", re);
}
int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
