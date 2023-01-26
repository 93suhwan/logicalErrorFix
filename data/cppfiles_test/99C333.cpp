#include <bits/stdc++.h>
using namespace std;
long long process_brute(long long x, long long n) {
  for (int i = 1; i <= n; i++) {
    if (abs(x) % 2 == 0)
      x -= i;
    else
      x += i;
  }
  return x;
}
long long process(long long x, long long n) {
  long long b = 0;
  if (abs(x) % 2 == 0) {
    if (n % 4 == 0) b = 0;
    if (n % 4 == 1) b = -n;
    if (n % 4 == 2) b = 1;
    if (n % 4 == 3) b = n + 1;
  } else {
    if (n % 4 == 0) b = 0;
    if (n % 4 == 1) b = n;
    if (n % 4 == 2) b = -1;
    if (n % 4 == 3) b = -n - 1;
  }
  return x + b;
}
int main() {
  int T = 0;
  scanf("%d", &T);
  long long x = 0, n = 0;
  while (T--) {
    scanf("%lld%lld", &x, &n);
    printf("%lld\n", process(x, n));
  }
  return 0;
}
