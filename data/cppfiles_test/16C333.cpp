#include <bits/stdc++.h>
using namespace std;
long long i, j, k, n, m, M, s, len, ans, co, T, f, r, t, pos, pre;
char a[41], b[41];
int main() {
  scanf("%lld", &T);
  while (T--) {
    ans = 0;
    scanf("%lld", &n);
    scanf("%s", a + 1);
    for (i = 1; i <= n; i++) b[i] = a[i];
    sort(a + 1, a + n + 1);
    for (i = 1; i <= n; i++)
      if (a[i] != b[i]) ans++;
    printf("%lld\n", ans);
  }
  return 0;
}
