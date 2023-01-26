#include <bits/stdc++.h>
using namespace std;
int p[1010];
int r[1010];
int q[1010];
int main() {
  int n;
  scanf("%d", &n);
  fflush(stdout);
  for (int i = n; i >= 1; i--) {
    for (int j = 1; j <= n; j++) q[j] = 2;
    q[i] = 1;
    printf("? ");
    fflush(stdout);
    for (int j = 1; j <= n; j++) {
      printf("%d ", q[j]);
      fflush(stdout);
    }
    printf("\n");
    fflush(stdout);
    int pt;
    scanf("%d", &pt);
    fflush(stdout);
    if (pt < i) r[pt] = i;
  }
  for (int i = n; i >= 1; i--) {
    for (int j = 1; j <= n; j++) q[j] = 1;
    q[i] = 2;
    printf("? ");
    fflush(stdout);
    for (int j = 1; j <= n; j++) {
      printf("%d ", q[j]);
      fflush(stdout);
    }
    printf("\n");
    fflush(stdout);
    int pt;
    scanf("%d", &pt);
    fflush(stdout);
    if (pt < i) r[i] = pt;
  }
  int pt = r[0], cnt = 0;
  while (pt) {
    p[pt] = ++cnt;
    pt = r[pt];
  }
  printf("! ");
  fflush(stdout);
  for (int i = 1; i <= n; i++) {
    printf("%d ", p[i]);
    fflush(stdout);
  }
  return 0;
}
