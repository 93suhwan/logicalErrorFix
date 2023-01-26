#include <bits/stdc++.h>
using namespace std;
int a[5];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int i;
    for (i = 1; i <= 3; i++) {
      scanf("%d", &a[i]);
    }
    sort(a + 1, a + 3 + 1);
    if (a[1] == a[2]) {
      if (a[3] & 1)
        printf("NO\n");
      else
        printf("YES\n");
    } else if (a[2] == a[3]) {
      if (a[1] & 1)
        printf("NO\n");
      else
        printf("YES\n");
    } else {
      if (a[1] + a[2] == a[3])
        printf("YES\n");
      else
        printf("NO\n");
    }
  }
}
