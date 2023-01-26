#include <bits/stdc++.h>
using namespace std;
const int N = 3e4 + 5;
int b[N], a[N], p[N];
int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= n - 1; i++) {
    printf("and %d %d\n", i, i + 1);
    fflush(stdout);
    int x;
    scanf("%d", &x);
    printf("or %d %d\n", i, i + 1);
    fflush(stdout);
    int y;
    scanf("%d", &y);
    b[i] = x + y;
  }
  printf("and %d %d\n", 1, 3);
  fflush(stdout);
  int x;
  scanf("%d", &x);
  printf("or %d %d\n", 1, 3);
  fflush(stdout);
  int y;
  scanf("%d", &y);
  a[1] = (x + y - b[2] + b[1]) / 2;
  for (int i = 1; i <= n - 1; i++) {
    a[i + 1] = b[i] - a[i];
  }
  sort(a + 1, a + 1 + n);
  printf("finish %d\n", a[k]);
  return 0;
}
