#include <bits/stdc++.h>
using namespace std;
int n, m;
int tu[100][100];
bool check(vector<int> v) {
  int tot = 0;
  for (int i = 0; i < v.size(); ++i)
    for (int j = i + 1; j < v.size(); ++j) tot += tu[v[i]][v[j]];
  return tot % 10 == 0;
}
int main() {
  scanf("%d%d", &n, &m);
  n = min(50, n);
  for (int i = 1; i <= m; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    if (x > n || y > n) continue;
    tu[x][y] = tu[y][x] = 1;
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      for (int k = j + 1; k <= n; ++k) {
        for (int l = k + 1; l <= n; ++l) {
          for (int m = l + 1; m <= n; ++m) {
            vector<int> v;
            v.push_back(i);
            v.push_back(j);
            v.push_back(k);
            v.push_back(l);
            v.push_back(m);
            if (check(v)) {
              printf("%d %d %d %d %d", i, j, k, l, m);
              return 0;
            }
          }
        }
      }
    }
  }
  printf("-1");
}
