#include <bits/stdc++.h>
using namespace std;
int a[7];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    for (int i = 0; i < 7; i++) scanf("%d", &a[i]);
    printf("%d %d ", a[0], a[1]);
    int i = 2;
    while (a[0] + a[1] + a[i] < a[6]) i++;
    printf("%d\n", a[i]);
  }
  return 0;
}
