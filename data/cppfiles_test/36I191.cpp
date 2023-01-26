#include <bits/stdc++.h>
using namespace std;
const int N = 110, mod = 1e9 + 10;
int T;
int n, m;
long long a[N], b[N], idx;
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
      b[i] += a[i] + b[i - 1];
    }
    if (!isprime(b[n])) mi = 0;
    if (mi == 0)
      printf("%d\n", n);
    else {
      printf("%d\n", n - 1);
      for (int i = 1; i <= n; i++) {
        if (a[i] % 2 != 0) {
          mi = i;
          break;
        }
      }
    }
    for (int i = 1; i <= n; i++) {
      if (i != mi) {
        printf("%d ", i);
      }
    }
    puts("");
  }
  return 0;
}
