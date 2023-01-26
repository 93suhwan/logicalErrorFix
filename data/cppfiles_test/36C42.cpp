#include <bits/stdc++.h>
using namespace std;
long long a[500500];
bool bl[500500];
bool is_prime[500500];
long long b[500500];
void prime(long long n) {
  int cnt = 0;
  memset(is_prime, 1, sizeof(is_prime));
  is_prime[1] = 0;
  for (int i = 2; i <= n; i++) {
    if (is_prime[i] == 1) {
      b[++cnt] = i;
    }
    for (int j = 1; j <= cnt && i * b[j] <= n; j++) {
      is_prime[i * b[j]] = 0;
      if (i % b[j] == 0) {
        break;
      }
    }
  }
}
int main() {
  long long t;
  prime(500500);
  scanf("%lld", &t);
  while (t--) {
    long long n;
    scanf("%lld", &n);
    long long sum = 0;
    for (int i = 0; i < n; i++) {
      scanf("%lld", &a[i]);
      if (a[i] % 2 == 1) {
        bl[i] = 1;
      }
      sum += a[i];
    }
    bool bb = 0;
    if (is_prime[sum]) {
      printf("%lld\n", n - 1);
      for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
          printf("%d ", i + 1);
        } else {
          if (bb == 1) {
            printf("%d ", i + 1);
          } else {
            bb = 1;
          }
        }
      }
    } else {
      printf("%lld\n", n);
      for (int i = 0; i < n; i++) {
        printf("%d ", i + 1);
      }
    }
  }
  return 0;
}
