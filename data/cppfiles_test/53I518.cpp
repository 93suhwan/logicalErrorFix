#include <bits/stdc++.h>
int prim[1000000], num[1000000];
int pn = 0;
void table() {
  memset(num, -1, sizeof(num));
  for (int i = 2; i < 1000000; i++) {
    if (num[i]) prim[pn++] = i;
    for (int j = 0; j < pn && 1LL * i * prim[j] < 1000000; j++) {
      num[i * prim[j]] = 0;
      if (i % prim[j] == 0) break;
    }
  }
}
int c[300005], numc;
char s[300005];
int main() {
  table();
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    getchar();
    char cc = getchar();
    getchar();
    numc = 0;
    for (int i = 1; i <= n; i++) {
      s[i] = getchar();
      if (s[i] != cc) c[++numc] = i;
    }
    if (numc == 0) {
      printf("0\n");
      continue;
    }
    int flag = 0;
    int nowc = 1;
    for (nowc = 1; c[nowc] <= n / 2; nowc++) {
      if (nowc == numc) break;
    }
    if (c[nowc] <= n / 2) {
      printf("1\n%d\n", n);
      continue;
    }
    for (int i = (n / 2) + 1; i <= n; i++) {
      if (c[nowc] != i) {
        flag = 1;
        break;
      }
      if (nowc == numc) break;
      nowc++;
    }
    if (flag == 1) {
      printf("1\n%d\n", c[nowc]);
      continue;
    }
    printf("2\n%d %d\n", n, n - 1);
  }
  return 0;
}
