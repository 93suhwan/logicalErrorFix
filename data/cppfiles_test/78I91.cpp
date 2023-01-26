#include <bits/stdc++.h>
using namespace std;
int T;
const int N = 2e5 + 10;
int a[N], t[29], p[29];
void prework() {
  p[1] = 1;
  for (int i = 2; i <= 29; ++i) {
    p[i] = p[i - 1] * 2;
  }
}
void cal(int x) {
  for (int i = 30; i >= 1; --i) {
    if (x >= p[i]) {
      x -= p[i];
      t[i]++;
    }
  }
}
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  scanf("%d", &T);
  while (T--) {
    int n, ag = 1;
    memset(t, 0, sizeof t);
    scanf("%d", &n);
    prework();
    for (int i = 1; i <= n; ++i) {
      scanf("%d", a + i);
      if (a[i]) ag = 0;
      int x = a[i];
      cal(x);
    }
    if (ag) {
      for (int i = 1; i <= n; ++i) printf("%d ", i);
      puts("");
      continue;
    }
    ag = 0;
    for (int i = 1; i <= 29; ++i) {
      if (!ag && t[i])
        ag = t[i];
      else if (t[i])
        ag = gcd(ag, t[i]);
    }
    for (int i = 1; i <= n; ++i)
      if (!(ag % i)) printf("%d ", i);
    puts("");
  }
  return 0;
}
