#include <bits/stdc++.h>
using namespace std;
const int N = 103;
int a[2][N], b[2][N];
bool solve() {
  int n;
  scanf("%d", &n);
  for (register int i = 0; i < 2; i++) {
    getchar();
    for (register int j = 1; j <= n; j++) a[i][j] = getchar() - '0';
  }
  if (a[0][1] || a[1][n]) return 0;
  for (register int i = 1; i <= n; i++)
    if (a[0][i] && a[1][i]) return 0;
  return 1;
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) puts(solve() ? "YES" : "NO");
  return 0;
}
