#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n;
int a[N], b[N], bok[2][2];
long long ans = 0;
int gcd(int a, int b) {
  if (a % 2 == 0 && b % 2 == 0) return 0;
  if (a % 2 == 1 && b % 2 == 0) return 1;
  if (a % 2 == 0 && b % 2 == 1) return 1;
  if (a % 2 == 1 && b % 2 == 1) return 1;
}
int main() {
  scanf("%d", &n);
  for (int i = (1); i <= (n); ++i) {
    scanf("%d%d", &a[i], &b[i]);
    a[i] /= 2;
    b[i] /= 2;
    ++bok[a[i] % 2][b[i] % 2];
  }
  for (int i = (1); i <= (n); ++i)
    for (int j = (1); j <= (n); ++j)
      if (i != j) {
        int tmp = gcd(abs(a[i] - a[j]), abs(b[i] - b[j]));
        --bok[a[i] % 2][b[i] % 2];
        --bok[a[j] % 2][b[j] % 2];
        int tt = tmp % 2;
        if ((gcd(a[i] + 1, b[i] + 1) + gcd(a[j] + 1, b[j] + 1)) % 2 == tt)
          ans += bok[1][1];
        if ((gcd(a[i], b[i] + 1) + gcd(a[j], b[j] + 1)) % 2 == tt)
          ans += bok[0][1];
        if ((gcd(a[i], b[i]) + gcd(a[j], b[j])) % 2 == tt) ans += bok[0][0];
        if ((gcd(a[i] + 1, b[i]) + gcd(a[j] + 1, b[j])) % 2 == tt)
          ans += bok[1][0];
        ++bok[a[i] % 2][b[i] % 2];
        ++bok[a[j] % 2][b[j] % 2];
      }
  ans /= 6;
  printf("%lld\n", ans);
  return 0;
}
