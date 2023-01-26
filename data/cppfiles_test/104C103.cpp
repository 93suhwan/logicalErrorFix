#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int a[N], b[N], eat_a[N], eat_b[N];
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, m;
    scanf("%d %d", &n, &m);
    long long suma = 0, sumb = 0;
    for (int i = 1; i <= n; ++i) {
      scanf("%d %d", &a[i], &b[i]);
      int eat = min(a[i], m);
      eat_a[i] = eat;
      eat_b[i] = m - eat;
      suma += a[i] - eat_a[i];
      sumb += b[i] - eat_b[i];
    }
    for (int i = 1; i <= n && sumb - suma >= 2; ++i) {
      long long tmp =
          min((sumb - suma) / 2, (long long)min(eat_a[i], b[i] - eat_b[i]));
      eat_a[i] -= tmp;
      eat_b[i] += tmp;
      suma += tmp;
      sumb -= tmp;
    }
    printf("%lld\n", abs(suma - sumb));
    for (int i = 1; i <= n; ++i) printf("%d %d\n", eat_a[i], eat_b[i]);
  }
  return 0;
}
