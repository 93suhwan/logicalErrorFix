#include <bits/stdc++.h>
using namespace std;
const long long inf = 0x3f3f3f3f3f3f3f3f;
template <typename T>
inline void read(T& X) {
  X = 0;
  int w = 0;
  char ch = 0;
  while (!isdigit(ch)) {
    w |= ch == '-';
    ch = getchar();
  }
  while (isdigit(ch)) X = (X << 3) + (X << 1) + (ch ^ 48), ch = getchar();
  if (w) X = -X;
}
long long a[20], p[20];
int main() {
  int t;
  for (int i = 0; i <= 9; i++) p[i] = pow(10, i);
  scanf("%d", &t);
  while (t--) {
    long long k, n;
    long long ans = 0;
    scanf("%lld %lld", &n, &k);
    for (int i = 1; i <= n; i++) {
      scanf("%lld", &a[i]);
      a[i] = p[a[i]];
    }
    for (int i = 1; i <= n; i++) {
      if (i == n) {
        ans = ans + (k + 1) * a[i];
        break;
      }
      long long now = (a[i + 1] - a[i]) / a[i];
      if (now <= k) {
        ans = ans + a[i + 1] - a[i];
        k = k - now;
      } else {
        ans = ans + a[i] * (k + 1);
        break;
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}
