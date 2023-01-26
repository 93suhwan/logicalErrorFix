#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    int height = 1;
    if (a[0]) height++;
    for (int i = 1; i < n; i++) {
      if (!a[i] && !a[i - 1]) {
        height = 0;
        break;
      } else if (a[i] && a[i - 1])
        height += 5;
      else if (a[i] && !a[i - 1])
        height++;
    }
    if (height)
      printf("%d\n", height);
    else
      printf("-1\n");
  }
  return 0;
}
