#include <bits/stdc++.h>
const int N = 1e6 + 5;
int n, m;
int q;
std::string map[N];
bool f[N];
int x[3];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) std::cin >> map[i];
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < m; j++)
      if (map[i - 1][j] == 'X' and map[i][j - 1] == 'X') f[j + 1] = 1;
  }
  scanf("%d", &q);
  while (q--) {
    scanf("%d%d", &x[1], &x[2]);
    bool flag = 0;
    for (int i = x[1] + 1; i <= x[2]; i++)
      if (f[i]) {
        flag = 1;
        break;
      }
    if (flag)
      printf("NO\n");
    else
      printf("YES\n");
  }
  return 0;
}
