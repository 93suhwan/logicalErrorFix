#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int b[7];
    for (int i = 0; i < 7; i++) {
      scanf("%d", &b[i]);
    }
    int a[3];
    a[0] = b[0];
    a[1] = b[1];
    if (b[2] == a[0] + a[1]) {
      a[2] = b[3];
    } else {
      a[2] = b[2];
    }
    for (int i = 0; i < 3; i++) {
      printf("%d", a[i]);
      printf(" ");
    }
    printf("\n");
  }
  return 0;
}
