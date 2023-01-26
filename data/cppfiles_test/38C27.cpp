#include <bits/stdc++.h>
const int N = 1e6 + 5;
int n, m;
int q;
std::string map[N];
bool f[N];
int sum[N];
int x[3];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) std::cin >> map[i];
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j < m; j++)
      if (map[i - 1][j] == 'X' and map[i][j - 1] == 'X') f[j + 1] = 1;
  }
  for (int i = 1; i <= m; i++) sum[i] = sum[i - 1] + f[i];
  scanf("%d", &q);
  while (q--) {
    scanf("%d%d", &x[1], &x[2]);
    bool flag = 0;
    if (sum[x[2]] - sum[x[1]] != 0) flag = 1;
    if (flag)
      printf("NO\n");
    else
      printf("YES\n");
  }
  return 0;
}
