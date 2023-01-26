#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, a[5], i;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d%d", &a[1], &a[2], &a[3]);
    if (a[1] == a[2] && a[2] == a[3]) {
      printf("%d\n", 0);
      continue;
    }
    printf("1\n");
  }
  return 0;
}
