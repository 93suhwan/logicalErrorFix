#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    cin >> n >> m;
    if (n > m) {
      printf("0\n");
      continue;
    } else if (n == m) {
      for (int i = 0; i <= 31; i++) {
        if ((n & (1 << i)) == 0) {
          printf("%d\n", (1 << i));
          break;
        }
      }
      continue;
    }
    m++;
    int ans = 0;
    for (int i = 30; i >= 0; i--) {
      if (n & (1 << i) && ((m & (1 << i)) == 0)) break;
      if ((n & (1 << i)) == 0 && (m & (1 << i))) {
        ans += (1 << i);
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
