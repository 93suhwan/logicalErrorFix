#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int n;
char gr[2005][2005], ngr[2005][2005];
int val0[2005][2005], val1[2005][2005];
bool chk[2005][2];
int fsum(int x, int y, int d) {
  int ret = val1[x][y];
  ret -= y > 0 ? val0[x][y - 1] : 0;
  ret -= x >= d && y + d < n ? val1[x - d][y + d] : 0;
  ret += x >= d && y > d ? val0[x - d][y - 1 - d] : 0;
  return ret;
}
void calc(int x, int dir) {
  for (int i = 0; i < (int)(n); i++)
    for (int j = 0; j < (int)(n); j++)
      val0[i][j] = val1[i][j] =
          gr[i][j] != '.' && (gr[i][j] != 'G') != ((i & 1) ^ x);
  for (int i = 0; i < (int)(n); i++)
    for (int j = 0; j < (int)(n - 1); j++) val0[i][j + 1] += val0[i][j];
  for (int i = 0; i < (int)(n); i++)
    for (int j = 0; j < (int)(n); j++)
      if (j - 1 >= 0) val0[i][j] += val0[i - 1][j - 1];
  for (int i = 0; i < (int)(n); i++)
    for (int j = 0; j < (int)(n - 1); j++) val1[i][j + 1] += val1[i][j];
  for (int i = 0; i < (int)(n); i++)
    for (int j = 0; j < (int)(n); j++)
      if (j + 1 < n) val1[i][j] += val1[i - 1][j + 1];
  for (int i = 1; i <= (int)(n); i++)
    if (i % 2 == 0 && n % i == 0)
      for (int j = 0; j < n; j += i) {
        for (int k = 0; k < n; k += i)
          if (fsum(j + (i >> 1) - 1, k + (i >> 1) - 1, i >> 1))
            chk[i][x ^ (j / i & 1) ^ (k / i & 1) ^ ((n - 1) / i & 1 & dir)] =
                false;
      }
}
void cyc() {
  for (int i = 0; i < (int)(n); i++)
    for (int j = 0; j < (int)(n); j++) ngr[i][j] = gr[j][n - 1 - i];
  memcpy(gr, ngr, sizeof(gr));
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < (int)(n); i++) scanf("%s", gr[i]);
  if (n % 2 == 1) {
    printf("NONE\n");
    return 0;
  }
  for (int i = 1; i <= (int)(n); i++)
    if (i % 2 == 0 && n % i == 0) chk[i][0] = chk[i][1] = true;
  for (int i = 0; i < (int)(4); i++) {
    calc(0, i & 1);
    calc(1, i & 1);
    cyc();
  }
  int tmp = 0;
  for (int i = 1; i <= (int)(n); i++) {
    if (i % 2 == 0 && chk[i][0]) tmp = tmp == 0 ? i : -1;
    if (i % 2 == 0 && chk[i][1]) tmp = tmp == 0 ? i : -1;
  }
  if (tmp == 0)
    printf("NONE\n");
  else if (tmp == -1)
    printf("MULTIPLE\n");
  else {
    printf("UNIQUE\n");
    for (int i = 0; i < (int)(n); i++)
      for (int j = 0; j < (int)(n); j++) {
        int dis = min(min(i % tmp, j % tmp),
                      min((n - 1 - i) % tmp, (n - 1 - j) % tmp)) &
                  1;
        dis ^= (i / tmp & 1) ^ (j / tmp & 1) ^ chk[tmp][1];
        putchar(dis ? 'S' : 'G');
        if (j == n - 1) putchar('\n');
      }
  }
  return 0;
}
