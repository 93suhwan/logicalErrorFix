#include <bits/stdc++.h>
using namespace std;
char buff[100000];
void solve() {
  int n, m;
  scanf("%d%d", &n, &m);
  vector<int> x(n);
  for (int i = 0; i < n; ++i) scanf("%d", &x[i]);
  vector<vector<int>> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("\n%s", buff);
    for (int j = 0; j < m; ++j)
      if (buff[j] == '1') a[i].push_back(j);
  }
  long long ans = -(1LL << 62);
  vector<int> best;
  int mask_n = 1 << n;
  for (int mask = 0; mask < mask_n; ++mask) {
    vector<int> c(m);
    for (int i = 0; i < n; ++i) {
      if ((mask >> i) & 1) {
        for (int j = 0; j < a[i].size(); ++j) c[a[i][j]] -= 1;
      } else {
        for (int j = 0; j < a[i].size(); ++j) c[a[i][j]] += 1;
      }
    }
    vector<pair<int, int>> d(m);
    for (int j = 0; j < m; ++j) d[j] = pair<int, int>(c[j], j);
    sort(d.begin(), d.end());
    vector<int> p(m);
    for (int j = 0; j < m; ++j) p[d[j].second] = j + 1;
    long long res = 0;
    for (int i = 0; i < n; ++i) {
      int y = 0;
      for (int j = 0; j < a[i].size(); ++j) y += p[a[i][j]];
      res += abs(y - x[i]);
    }
    if (ans < res) {
      ans = res;
      best = p;
    }
  }
  for (int i = 0; i < m; ++i) printf("%d ", best[i]);
  printf("\n");
}
int main() {
  int t;
  scanf("%d", &t);
  for (int i = 0; i < t; ++i) solve();
  return 0;
}
