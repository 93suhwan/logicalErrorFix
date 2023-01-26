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
      if (idx + cnt > n) idx = 1;
      res.push_back(cur);
    }
  }
  if (n % m) {
    int p = n % m;
    int idx = 0;
    for (int i = n - p + 1; i <= n; i++) {
      for (int j = 0; j < k; j++) {
        res[idx++].push_back(i);
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
void strcpy1(char *p1, char *p2) {
  while (*p2) *p1++ = *p2++;
}
int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
