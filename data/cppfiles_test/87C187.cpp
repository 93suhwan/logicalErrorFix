#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e4 + 5;
int a[MAXN];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (register int i = 1; i <= n; i++) scanf("%d", &a[i]);
    int ans = 0, p = 0;
    for (register int i = 1; i <= n; i++) {
      p++;
      ans += max(0, a[i] - p);
      p += max(0, a[i] - p);
    }
    printf("%d\n", ans);
  }
  return 0;
}
