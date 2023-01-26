#include <bits/stdc++.h>
using namespace std;
int i, n, t, a[200005];
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (i = 1; i <= n; i++) scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    for (i = 1; i <= n / 2; i++) printf("%d %d\n", a[i + 1], a[1]);
  }
}
