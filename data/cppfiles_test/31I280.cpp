#include <bits/stdc++.h>
using namespace std;
int a[100005];
void work() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  if (n % 2 == 0) {
    for (int i = 1; i <= n; i += 2) {
      printf("%d %d ", -a[i + 1], a[i]);
    }
    putchar('\n');
  } else {
    for (int i = 1; i <= n - 3; i += 2) {
      printf("%d %d ", -a[i + 1], a[i]);
    }
    printf("%d %d %d\n", -a[n], -a[n], a[n - 1] + a[n - 2]);
  }
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) work();
}
