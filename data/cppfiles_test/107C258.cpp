#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int x[N];
int t;
int n, a, b;
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d%d", &n, &a, &b);
    if (a + b + 2 > n) {
      printf("-1\n");
      continue;
    }
    if (a > b + 1 || b > a + 1) {
      printf("-1\n");
      continue;
    }
    for (int i = 1; i <= n; i++) {
      x[i] = i;
    }
    if (a == b) {
      for (int i = 2; a; i += 2) {
        swap(x[i], x[i + 1]);
        a--;
      }
    } else if (a > b) {
      swap(x[n - 1], x[n]);
      for (int i = 2; b; i += 2) {
        swap(x[i], x[i + 1]);
        b--;
      }
    } else {
      swap(x[1], x[2]);
      for (int i = 3; a; i += 2) {
        swap(x[i], x[i + 1]);
        a--;
      }
    }
    for (int i = 1; i <= n; i++) {
      printf("%d ", x[i]);
    }
    printf("\n");
  }
  return 0;
}
