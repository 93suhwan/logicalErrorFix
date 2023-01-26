#include <bits/stdc++.h>
using namespace std;
int n, a[5000005][3], at, p[100005][2], pt;
char s[2005][2005], tans[2005][2005];
inline int F(int k, int x, int y) {
  x--, y--;
  int nw = (x / k) + (y / k);
  int u = x % k, v = y % k;
  nw ^= min(min(u, v), min(k - 1 - u, k - 1 - v));
  return nw;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
  for (int i = 1; i <= n; i++)
    if (n % i == 0 && i % 2 == 0) p[++pt][0] = i;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (s[i][j] != '.') {
        a[++at][0] = i;
        a[at][1] = j;
        a[at][2] = (s[i][j] == 'G');
      }
  for (int i = 1; i <= at; i++) {
    for (int j = 1; j <= pt; j++) {
      int k = p[j][0], x = a[i][0], y = a[i][1], nw = a[i][2];
      p[j][1] |= ((nw ^ F(k, x, y)) & 1) + 1;
      if (p[j][1] == 3) {
        for (int l = j + 1; l <= pt; l++)
          p[l - 1][0] = p[l][0], p[l - 1][1] = p[l][1];
        j--, pt--;
      }
    }
  }
  if (!pt)
    printf("NONE\n");
  else if (pt >= 2 || p[1][1] == 0)
    printf("MULTIPLE\n");
  else {
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++) {
        int nw = F(p[1][0], i, j) ^ (p[1][1] - 1);
        if (nw & 1)
          tans[i][j] = 'G';
        else
          tans[i][j] = 'S';
      }
    printf("UNIQUE\n");
    for (int i = 1; i <= n; i++) printf("%s\n", tans[i] + 1);
  }
  return 0;
}
