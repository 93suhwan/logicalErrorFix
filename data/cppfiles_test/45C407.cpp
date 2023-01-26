#include <bits/stdc++.h>
using namespace std;
int x[110];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &x[i]);
    int ans = 1;
    for (int i = 1; i <= n; i++) {
      if (i > 1 && x[i - 1] && x[i])
        ans += 5;
      else if (x[i])
        ans++;
      if (i > 1 && !x[i - 1] && !x[i]) {
        ans = -1;
        break;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
