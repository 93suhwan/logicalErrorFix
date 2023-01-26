#include <bits/stdc++.h>
using namespace std;
int n, a, b, minx, maxn, ans;
int main() {
  scanf("%d", &n);
  while (n--) {
    scanf("%d%d", &a, &b);
    minx = min(a, b);
    maxn = max(a, b);
    a = minx * 2, b = maxn - minx;
    if (b & 1) {
      printf("%d\n", a + 2);
      for (int i = 0; i <= a + 1; i++) printf("%d ", i + b / 2);
      printf("\n");
    } else {
      printf("%d\n", a / 2 + 1);
      for (int i = 0; i <= a; i += 2) printf("%d ", i + b / 2);
      printf("\n");
    }
  }
}
