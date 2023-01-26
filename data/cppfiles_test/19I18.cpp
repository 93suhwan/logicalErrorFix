#include <bits/stdc++.h>
using namespace std;
int a[1000005];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    int sign = 1;
    int x = 0;
    int l = 0, r = 0;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      x += sign * a[i];
      l = min(l, x);
      r = max(r, x);
      sign = -sign;
    }
    printf("%d\n", r - l + 1);
  }
  return 0;
}
