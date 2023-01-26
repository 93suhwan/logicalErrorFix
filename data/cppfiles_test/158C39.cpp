#include <bits/stdc++.h>
int ww[10000];
void sort(int *jj, int m) {
  static int kk[(10 + 1) * 2], jj_[10000];
  int j, w;
  memset(kk, 0, sizeof kk);
  for (j = 0; j < m; j++) {
    w = 10 + ww[j];
    kk[w + 1]++;
  }
  for (w = 1; w < (10 + 1) * 2; w++) kk[w] += kk[w - 1];
  for (j = 0; j < m; j++) {
    w = 10 + ww[j];
    jj_[kk[w]++] = jj[j];
  }
  memcpy(jj, jj_, m * sizeof *jj_);
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    static int xx[10], jj[10000], jj_[10000], pp[10000];
    static char cc[10][10000 + 1];
    int n, m, i, j, b, sum_, sum;
    scanf("%d%d", &n, &m);
    for (i = 0; i < n; i++) scanf("%d", &xx[i]);
    for (i = 0; i < n; i++) scanf("%s", cc[i]);
    sum_ = -1;
    for (b = 0; b < 1 << n; b++) {
      memset(ww, 0, m * sizeof *ww);
      sum = 0;
      for (i = 0; i < n; i++)
        if ((b & 1 << i) == 0) {
          sum += xx[i];
          for (j = 0; j < m; j++)
            if (cc[i][j] == '1') ww[j]--;
        } else {
          sum -= xx[i];
          for (j = 0; j < m; j++)
            if (cc[i][j] == '1') ww[j]++;
        }
      for (j = 0; j < m; j++) jj[j] = j;
      sort(jj, m);
      for (j = 0; j < m; j++) sum += ww[jj[j]] * (j + 1);
      if (sum_ < sum) {
        sum_ = sum;
        memcpy(jj_, jj, m * sizeof *jj);
      }
    }
    for (j = 0; j < m; j++) pp[jj_[j]] = j + 1;
    for (j = 0; j < m; j++) printf("%d ", pp[j]);
    printf("\n");
  }
  return 0;
}
