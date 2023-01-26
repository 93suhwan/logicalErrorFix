#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
int s[N][N], u[N];
vector<int> v[N];
int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      scanf("%d", &s[i][j]);
    }
  }
  int L = 1, x = 1, y = 1;
  while (L <= m) {
    if (s[x][y] == 1) {
      s[x][y] = 2;
      y++;
    } else if (s[x][y] == 2)
      x++;
    else {
      s[x][y] = 2;
      y--;
    }
    if (x > n) {
      v[L].push_back(y);
      int flag = 1;
      for (int i = 1; i <= n; i++)
        if (s[i][L] != 2) {
          flag = 0;
          break;
        }
      if (y != L && flag == 1) v[L].push_back(L);
      if (flag) L++;
      x = 1;
      y = L;
    }
  }
  while (k--) {
    int a;
    scanf("%d", &a);
    u[a]++;
    if (v[a].size() >= u[a])
      printf("%d ", v[a][u[a] - 1]);
    else
      printf("%d ", v[a][v[a].size() - 1]);
  }
  return 0;
}
