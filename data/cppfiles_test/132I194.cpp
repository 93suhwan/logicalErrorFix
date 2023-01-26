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
    printf("%d %d %d\n", a[1], a[2], a[4]);
    puts("");
  }
}
