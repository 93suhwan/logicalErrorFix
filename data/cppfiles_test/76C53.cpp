#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5, N = 50;
int a[maxn], f[N][N], n, m;
void deal() {
  int key = 0;
  for (int i = 1; i <= 5; i++) {
    for (int j = 1; j <= 5; j++) {
      if (i == j) continue;
      key += f[a[i]][a[j]];
    }
  }
  if (key == 0 or key == 20) {
    for (int i = 1; i <= 5; i++) cout << a[i] << " ";
    exit(0);
  }
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    if (max(u, v) > 49) continue;
    f[u][v] = f[v][u] = 1;
  }
  m = min(49, n);
  for (int i = 1; i <= m; i++)
    for (int j = i + 1; j <= m; j++)
      for (int k = j + 1; k <= m; k++)
        for (int l = k + 1; l <= m; l++)
          for (int q = l + 1; q <= m; q++)
            a[1] = i, a[2] = j, a[3] = k, a[4] = l, a[5] = q, deal();
  cout << (-1) << '\n';
  return 0;
}
