#include <bits/stdc++.h>
typedef struct sem {
  long long strt;
} dur;
long long ar[100008][3];
long long fn[100008];
int cmpc(const void *a, const void *b);
int cmpi(const void *a, const void *b);
int cmps(const void *a, const void *b);
int cmpc(const void *a, const void *b) {
  if ((*(char *)a - *(char *)b) > 0) {
    return 1;
  } else if ((*(char *)a - *(char *)b) == 0) {
    return 0;
  } else {
    return -1;
  }
}
int cmpi(const void *a, const void *b) {
  if ((*(long long *)a - *(long long *)b) > 0) {
    return 1;
  } else if ((*(long long *)a - *(long long *)b) == 0) {
    return 0;
  } else {
    return -1;
  }
}
int cmps(const void *a, const void *b) {
  if ((((dur *)a)->strt - ((dur *)b)->strt) > 0) {
    return 1;
  } else if ((((dur *)a)->strt - ((dur *)b)->strt) == 0) {
    return 0;
  } else {
    return -1;
  }
}
int main() {
  long long a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, ans;
  scanf("%lld", &t);
  while (t--) {
    scanf("%lld", &n);
    scanf("%lld", &m);
    for (i = 0; i < m; i++) {
      scanf("%lld", &ar[i][0]);
      scanf("%lld", &ar[i][1]);
      fn[ar[i][1]] = 1;
      scanf("%lld", &ar[i][2]);
    }
    for (i = 1; i <= n; i++) {
      if (fn[i] == 0) {
        k = i;
      }
    }
    for (i = 1; i <= n; i++) {
      if (i != k) {
        printf("%lld %lld\n", k, i);
      }
    }
  }
  return 0;
}
