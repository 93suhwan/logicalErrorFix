#include <bits/stdc++.h>
using namespace std;
int a[100005];
void work() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  if (n % 2 == 0) {
    for (int i = 1; i <= n; i += 2) {
      if (a[i] + a[i + 1] != 0)
        printf("%d %d", -a[i + 1], a[i]);
      else
        printf("1 1 ");
      if (i != n - 1) putchar(' ');
    }
    putchar('\n');
  } else {
    for (int i = 1; i <= n - 3; i += 2) {
      if (a[i] + a[i + 1] != 0)
        printf("%d %d ", -a[i + 1], a[i]);
      else
        printf("1 1 ");
    }
    if (a[n] + a[n - 1] + a[n - 2] != 0)
      printf("%d %d %d\n", -a[n], -a[n], a[n - 1] + a[n - 2]);
    else
      printf("1 1 1\n");
  }
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) work();
}
