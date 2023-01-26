#include <bits/stdc++.h>
unsigned int X;
int rand_() { return (X *= 3) >> 1; }
char composite[1000000 + 1];
int pp[1000000 + 1];
long long xx[1000000 + 1][2], yy[1000000 + 1][2];
void init() {
  struct timeval tv;
  int a, b;
  gettimeofday(&tv, NULL);
  X = tv.tv_sec ^ tv.tv_usec | 1;
  for (a = 2; a <= 1000000; a++) {
    if (composite[a]) continue;
    for (b = a + a; b <= 1000000; b += a) composite[b] = 1, pp[b] = a;
  }
  for (a = 2; a <= 1000000; a++)
    if (!composite[a]) {
      xx[a][0] = (long long)rand_() << 31 | rand_();
      xx[a][1] = (long long)rand_() << 31 | rand_();
    } else {
      xx[a][0] = xx[a / pp[a]][0] ^ xx[pp[a]][0];
      xx[a][1] = xx[a / pp[a]][1] ^ xx[pp[a]][1];
    }
  for (a = 1; a <= 1000000; a++)
    xx[a][0] ^= xx[a - 1][0], xx[a][1] ^= xx[a - 1][1];
}
long long (*zz)[2];
int compare(int i, int j) {
  return zz[i][0] != zz[j][0]
             ? (zz[i][0] < zz[j][0] ? -1 : 1)
             : (zz[i][1] == zz[j][1] ? 0 : (zz[i][1] < zz[j][1] ? -1 : 1));
}
void sort(int *ii, int l, int r) {
  while (l < r) {
    int i = l, j = l, k = r, i_ = ii[l + rand_() % (r - l)], tmp;
    while (j < k) {
      int c = compare(ii[j], i_);
      if (c == 0)
        j++;
      else if (c < 0) {
        tmp = ii[i], ii[i] = ii[j], ii[j] = tmp;
        i++, j++;
      } else {
        k--;
        tmp = ii[j], ii[j] = ii[k], ii[k] = tmp;
      }
    }
    sort(ii, l, i);
    l = k;
  }
}
int main() {
  static int ii[1000000 + 1], jj[1000000 + 1];
  static long long xx_[2];
  int n, h, i, j;
  init();
  scanf("%d", &n);
  for (i = 1; i <= n; i++) xx_[0] ^= xx[i][0], xx_[1] ^= xx[i][1];
  if (xx_[0] == 0 && xx_[1] == 0) {
    printf("%d\n", n);
    for (i = 1; i <= n; i++) printf("%d ", i);
    printf("\n");
    return 0;
  }
  for (i = 1; i <= n; i++) {
    yy[i][0] = xx_[0] ^ xx[i][0], yy[i][1] = xx_[1] ^ xx[i][1];
    if (yy[i][0] == 0 && yy[i][1] == 0) {
      printf("%d\n", n - 1);
      for (j = 1; j <= n; j++)
        if (j != i) printf("%d ", j);
      printf("\n");
      return 0;
    }
  }
  for (i = 1; i <= n; i++) ii[i] = i;
  for (j = 1; j <= n; j++) jj[j] = j;
  zz = xx, sort(ii, 1, n + 1);
  zz = yy, sort(jj, 1, n + 1);
  i = 1, j = 1;
  while (i <= n && j <= n)
    if (xx[ii[i]][0] == yy[jj[j]][0] && xx[ii[i]][1] == yy[jj[j]][1]) {
      printf("%d\n", n - 2);
      for (h = 1; h <= n; h++)
        if (h != ii[i] && h != jj[j]) printf("%d ", h);
      printf("\n");
      return 0;
    } else if (xx[ii[i]][0] < yy[jj[j]][0] ||
               xx[ii[i]][0] == yy[jj[j]][0] && xx[ii[i]][1] < yy[jj[j]][1])
      i++;
    else
      j++;
  printf("%d\n", n - 3);
  for (i = 1; i <= n; i++)
    if (i != 2 && i != n / 2 && i != n) printf("%d ", i);
  printf("\n");
  return 0;
}
