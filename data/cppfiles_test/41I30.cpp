#include <bits/stdc++.h>
using namespace std;
int n, k;
int main() {
  scanf("%d%d", &n, &k);
  int ans = 0;
  for (int i = 1; i < n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      int l = i, r = j, num = 0;
      while (l != r) {
        l /= k;
        r /= k;
        num++;
      }
      ans = max(ans, num);
    }
  }
  printf("%d\n", ans);
  for (int i = 1; i < n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      int l = i, r = j, num = 0;
      while (l != r) {
        l /= k;
        r /= k;
        num++;
      }
      printf("%d ", num);
    }
  }
  return 0;
}
