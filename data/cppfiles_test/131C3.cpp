#include <bits/stdc++.h>
using namespace std;
int n, res;
pair<int, int> ans = {1, 2};
map<int, pair<int, int> > f;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int a, L = 0;
    scanf("%d", &a);
    f[a] = {0, i};
  }
  int x = 2e9;
  for (;;) {
    auto it = --f.lower_bound(x);
    x = it->first;
    if (x == 0) break;
    int fa;
    for (int i = 0; i < 31; i++)
      if ((1 << i) >= x) {
        fa = (1 << i) - x;
        break;
      }
    pair<int, int> y = it->second;
    if (f.find(fa) == f.end()) f[fa] = {-1e9, 0};
    pair<int, int> F = f[fa];
    if (res < y.first + F.first + 1) {
      res = y.first + F.first + 1;
      ans = {y.second, F.second};
    }
    f[fa] = max(f[fa], {y.first + 1, y.second});
  }
  printf("%d %d %d", ans.first, ans.second, res);
}
