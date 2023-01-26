#include <bits/stdc++.h>
using namespace std;
typedef struct dur {
  long long num1;
  long long num2;
  char com[15];
} box;
bool compi(long long a, long long b) { return (a > b); }
long long ar1[40009];
long long ar2[40009];
long long slv(long long n) {
  long long i, j, m, h, ans, p;
  ans = 0;
  for (long long i = 0; i < n; i++) {
    ar2[i] = ar1[i] - ar1[(i - 1 + n) % n];
    ans += ar1[i];
  }
  p = n * (n + 1) / 2;
  if (ans % p == 0) {
    ans = ans / p;
  }
  return ans;
}
int main() {
  long long h, i, j, k, d, m, p, t, ans1, ans2, n, q, a, b;
  scanf("%lld", &t);
  while (t--) {
    scanf("%lld", &n);
    for (long long i = 0; i < n; i++) {
      scanf("%lld", &ar1[i]);
    }
    ans1 = slv(n);
    ans2 = 0;
    if (ans1 >= n) {
      for (long long i = 0; i < n; i++) {
        if ((ans1 - ar2[i]) % n != 0) {
          ans2 = 0;
          break;
        }
        ar2[i] = (ans1 - ar2[i]) / n;
        if (ar2[i] < 0) {
          ans2 = 0;
          break;
        }
        ans2 += ar2[i];
      }
    }
    if ((ans2 == ans1) && (ans1 >= n)) {
      printf("YES\n");
      for (long long i = 0; i < n; i++) {
        printf("%lld ", ar2[i]);
      }
    } else {
      printf("NO");
    }
    printf("\n");
  }
  return 0;
}
