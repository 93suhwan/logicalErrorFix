#include <bits/stdc++.h>
using namespace std;
const int N = 110, mod = 1e9 + 10;
int T;
int n, m;
int a[N], idx;
long long sum;
bool isprime(int n) {
  for (int i = 2; i <= n / i; ++i) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    int mi = 0;
    for (int i = 1; i <= n; i++) {
      int t = 0;
      scanf("%d", &a[i]);
      sum += a[i];
      if (a[i] % 2 == 1 && !mi) mi = i;
      if (a[mi] > a[i] && a[i] % 2 != 0) mi = i;
    }
    if (!isprime(sum)) mi = 0;
    if (mi == 0)
      printf("%d\n", n);
    else
      printf("%d\n", n - 1);
    for (int i = 1; i <= n; i++) {
      if (i == mi) continue;
      printf("%d ", i);
    }
    puts("");
  }
  return 0;
}
