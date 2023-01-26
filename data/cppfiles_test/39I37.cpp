#include <bits/stdc++.h>
using namespace std;
int n, a[105], c;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    printf("?");
    for (int j = 1; j <= n; j++) printf(" %d", j != i);
    fflush(stdout);
    int x;
    scanf("%d", &x);
    if (!x) {
      a[i] = 1;
      c = i;
      break;
    }
  }
  for (int i = 2; i <= n; i++) {
    printf("?");
    for (int j = 1; j <= n; j++) printf(" %d", j == c ? i - 1 : 0);
    fflush(stdout);
    int x;
    scanf("%d", &x);
    a[x] = i;
  }
  printf("!");
  for (int j = 1; j <= n; j++) printf(" %d", a[j]);
}
