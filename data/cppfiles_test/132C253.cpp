#include <bits/stdc++.h>
using namespace std;
int a[10];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    for (int i = 1; i <= 7; i++) {
      scanf("%d", &a[i]);
    }
    if (a[1] == a[2] && a[2] == a[3]) {
      printf("%d %d %d", a[1], a[2], a[3]);
    } else {
      if (a[1] + a[2] != a[3]) {
        printf("%d %d %d", a[1], a[2], a[3]);
      } else
        printf("%d %d %d", a[1], a[2], a[4]);
    }
    puts("");
  }
}
