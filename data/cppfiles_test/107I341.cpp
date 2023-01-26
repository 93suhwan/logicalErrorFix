#include <bits/stdc++.h>
using namespace std;
int t;
int n, a, b;
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d%d", &n, &a, &b);
    if (a >= (n + 1) / 2 || b >= (n + 1) / 2) {
      printf("-1\n");
      continue;
    }
    printf("1 ");
    for (int i = 2; i < n; i += 2) {
      printf("%d %d ", i + 1, i);
    }
    printf("%d\n", n);
  }
  return 0;
}
