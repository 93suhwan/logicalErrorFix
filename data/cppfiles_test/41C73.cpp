#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
int a[maxn][maxn];
int solve(int l, int r, int k, int col) {
  if (r - l + 1 == 1) return 0;
  int len = (r - l + 1 + k - 1) / k;
  int i = l;
  int ans = col;
  vector<vector<int>> g;
  while (i <= r) {
    int j = min(i + len - 1, r);
    vector<int> h;
    for (int c = i; c <= j; ++c) {
      h.push_back(c);
    }
    g.push_back(h);
    ans = max(ans, solve(i, j, k, col + 1));
    i = j + 1;
  }
  for (int i = 0; i < g.size(); ++i) {
    for (auto u : g[i]) {
      for (int j = i + 1; j < g.size(); ++j) {
        for (auto v : g[j]) {
          a[u][v] = col;
        }
      }
    }
  }
  return ans;
}
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  printf("%d\n", solve(1, n, k, 1));
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) printf("%d ", a[i][j]);
  }
  puts("");
}
