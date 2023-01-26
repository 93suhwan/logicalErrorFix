#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int a[N];
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    sort(a + 1, a + n + 1);
    int ans = a[1];
    for (int i = 1; i < n; ++i) {
      ans = max(a[i + 1] - a[i], ans);
    }
    printf("%d\n", ans);
  }
  return 0;
}
