#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, m, b[N], Q;
string a[N];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int j = 1; j < m; j++) {
    bool fl = 1;
    int i;
    for (i = 0; i < n; i++)
      if (a[i][j] == 'X') break;
    if (i == n) continue;
    for (i = i + 1; i < n; i++)
      if (a[i][j - 1] == '.') {
        fl = 0;
        break;
      }
    if (!fl)
      b[j] = 0;
    else
      b[j] = 1;
  }
  for (int i = 1; i < m; i++) b[i] += b[i - 1];
  scanf("%d", &Q);
  for (int i = 1, x, y; i <= Q; i++) {
    scanf("%d%d", &x, &y);
    x--;
    y--;
    if (x == y) {
      printf("YES\n");
      continue;
    }
    if (b[y] - b[x] > 0)
      printf("NO\n");
    else
      printf("YES\n");
  }
  return 0;
}
