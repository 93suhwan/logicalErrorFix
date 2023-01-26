#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int a[N], f[N], pos[N], n;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    pos[a[i] + 1] = n + 1;
  }
  for (int i = n; i >= 1; i--) {
    f[i] = f[pos[a[i] + 1]] + 1;
    pos[a[i]] = i;
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] <= i) {
      ans = max(ans, f[i]);
    }
  }
  printf("%d\n", ans);
  return 0;
}
