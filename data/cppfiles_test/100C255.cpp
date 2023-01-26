#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    int n, a[200005];
    scanf("%d", &n);
    for (int j = 0; j < n; j++) {
      scanf("%d", &a[j]);
    }
    sort(a, a + n);
    int ans = a[0];
    for (int j = 1; j < n; j++) ans = max(ans, a[j] - a[j - 1]);
    printf("%d\n", ans);
  }
  return 0;
}
