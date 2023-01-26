#include <bits/stdc++.h>
using namespace std;
int t, k;
char n[55];
int c[55], d[55];
bool isprime(long long n) {
  if (n == 1) return 0;
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) return 0;
  }
  return 1;
}
int f;
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &k);
    scanf("%s", n);
    memset(c, 0, sizeof(c));
    memset(d, 0, sizeof(d));
    int len = strlen(n);
    int b = 0;
    for (int i = 0; i < len; i++) {
      c[i] = n[i] - '0';
      d[c[i]]++;
      if (isprime(c[i]) == 0) {
        b = c[i];
        break;
      }
    }
    if (b != 0) {
      printf("1\n%d\n", b);
    } else {
      int ans, res;
      f = 1;
      if (d[2] > 0 && d[7] > 0) {
        printf("2\n27\n");
        f = 0;
      } else {
        for (int i = 0; i < len; i++) {
          if (d[c[i]] > 1) {
            ans = 2;
            res = c[i] * 10 + c[i];
            f = 0;
            break;
          }
        }
        if (f == 0) {
          printf("%d\n%d\n", ans, res);
        } else {
          printf("%d\n", k);
          printf("%s\n", n);
        }
      }
    }
  }
  return 0;
}
