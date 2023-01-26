#include <bits/stdc++.h>
using namespace std;
const int maxn = 10005;
int n, k;
int sum[maxn], v[maxn];
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 2; i <= n; i++) {
    int x, y;
    printf("or 1 %d\n", i), fflush(stdout), scanf("%d", &x);
    printf("and 1 %d\n", i), fflush(stdout), scanf("%d", &y);
    sum[i] = x + y;
  }
  int a, b;
  puts("or 2 3"), fflush(stdout), scanf("%d", &a);
  puts("and 2 3"), fflush(stdout), scanf("%d", &b);
  v[1] = (a + b + sum[2] + sum[3]) / 2 - a - b;
  for (int i = 2; i <= n; i++) v[i] = sum[i] - v[1];
  sort(v + 1, v + 1 + n);
  printf("finish %d\n", v[k]), fflush(stdout);
  return 0;
}
