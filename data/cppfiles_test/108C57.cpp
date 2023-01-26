#include <bits/stdc++.h>
int a[100100], b[100100];
int g1[100100], g2[100100];
int tempa[100100], tempb[100100];
int z[100100];
int min(int aa, int bb) {
  if (aa < bb) {
    return aa;
  }
  return bb;
}
void mergesort(int *ar, int *aa, int n1, int n2) {
  int a1, a2, n12;
  int i, j;
  int z;
  if (n1 < n2) {
    n12 = (n1 + n2) / 2;
    mergesort(ar, aa, n1, n12);
    mergesort(ar, aa, n12 + 1, n2);
    for (i = n1; i <= n2; i++) {
      tempa[i] = aa[i];
    }
    a1 = n1;
    a2 = n12 + 1;
    for (i = n1; i <= n2; i++) {
      if (a1 > n12) {
        z = 2;
      } else if (a2 > n2) {
        z = 1;
      } else {
        if (ar[tempa[a1]] >= ar[tempa[a2]]) {
          z = 1;
        } else {
          z = 2;
        }
      }
      if (z == 1) {
        aa[i] = tempa[a1];
        a1++;
      } else {
        aa[i] = tempa[a2];
        a2++;
      }
    }
  }
}
int main(void) {
  int t, ii;
  int n, i;
  int g1min, g2min;
  int p1, p2;
  int nans;
  int p;
  int flag;
  scanf("%d", &t);
  for (ii = 1; ii <= t; ii++) {
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      g1[i] = i;
    }
    for (i = 1; i <= n; i++) {
      scanf("%d", &b[i]);
      g2[i] = i;
    }
    mergesort(a, g1, 1, n);
    mergesort(b, g2, 1, n);
    for (i = 1; i <= n; i++) {
      z[i] = 0;
    }
    p1 = 2;
    p2 = 1;
    p = g1[1];
    g1min = a[p];
    g2min = b[p];
    z[p] = 1;
    nans = 1;
    while (nans <= n) {
      flag = 1;
      for (i = p1; i <= n; i++) {
        p = g1[i];
        if (a[p] > g1min) {
          if (z[p] == 0) {
            z[p] = 1;
            nans++;
            g1min = min(g1min, a[p]);
            g2min = min(g2min, b[p]);
          }
          p1++;
        } else {
          break;
        }
        flag = 0;
      }
      for (i = p2; i <= n; i++) {
        p = g2[i];
        if (b[p] > g2min) {
          if (z[p] == 0) {
            z[p] = 1;
            nans++;
            g1min = min(g1min, a[p]);
            g2min = min(g2min, b[p]);
          }
          p2++;
        } else {
          break;
        }
        flag = 0;
      }
      if (flag) {
        break;
      }
    }
    for (i = 1; i <= n; i++) {
      printf("%d", z[i]);
    }
    printf("\n");
  }
  return 0;
}
