#include <bits/stdc++.h>
using namespace std;
void solve() {
  int a[100];
  int n, i;
  scanf("%d", &n);
  getchar();
  for (i = 0; i < n; i++) {
    a[i] = getchar() - '0';
  }
  for (i = 0; i < n; i++) {
    if (a[i] == 1 || a[i] == 4 || a[i] == 6 || a[i] == 8 || a[i] == 9) {
      printf("%d\n%d\n", 1, a[i]);
      return;
    }
  }
  for (i = n - 1; i >= 0; i--) {
    if ((a[i] == 2 || a[i] == 5) && i != 0) {
      printf("%d\n%d%d\n", 2, a[0], a[i]);
      return;
    }
  }
  if (n >= 2) {
    for (i = 1; i < n; i++) {
      if (a[i] == a[0]) {
        printf("%d\n%d%d\n", 2, a[i], a[i]);
        return;
      }
    }
    for (i = 2; i < n; i++) {
      if (a[i] == a[1]) {
        printf("%d\n%d%d\n", 2, a[i], a[i]);
        return;
      }
    }
    for (i = 3; i < n; i++) {
      if (a[i] == a[2]) {
        printf("%d\n%d%d\n", 2, a[i], a[i]);
        return;
      }
    }
  }
  printf("%d\n", 2);
  for (i = 0; i < n; i++) {
    if (n != 2 && a[i] == 3) continue;
    printf("%d", a[i]);
  }
  printf("\n");
  return;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
