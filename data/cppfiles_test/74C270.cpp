#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;
int s[maxn];
void solve() {
  long long n, m, i, j, f = 1, k, b, a, t = 0, c;
  scanf("%lld%lld", &a, &b);
  n = a + b;
  a = min(a, b);
  c = n / 2;
  if (n % 2) {
    for (i = n - (c + 1 + a);; i += 2) {
      s[++t] = i;
      if (t == a + 1) break;
    }
    for (i = 1; i <= t; i++)
      if (s[i] > c) s[i] = n - s[i];
    printf("%d\n", t * 2);
    sort(s + 1, s + t + 1);
    for (i = 1; i <= t; i++) printf("%d ", s[i]);
    for (i = t; i >= 1; i--) printf("%d ", n - s[i]);
    printf("\n");
  } else {
    for (i = n - (c + a); i <= c; i += 2) {
      s[++t] = i;
    }
    if (s[t] == c) {
      printf("%d\n", t * 2 - 1);
      for (i = 1; i < t; i++) printf("%d ", s[i]);
      for (i = t; i >= 1; i--) printf("%d ", n - s[i]);
    } else {
      printf("%d\n", t * 2);
      for (i = 1; i <= t; i++) printf("%d ", s[i]);
      for (i = t; i >= 1; i--) printf("%d ", n - s[i]);
    }
    printf("\n");
  }
}
int main() {
  int T = 1;
  scanf("%d", &T);
  while (T--) solve();
  return 0;
}
