#include <bits/stdc++.h>
const int N = (int)1e6 + 5;
const int M = (int)1e9 + 5;
const int mod = (int)1000000007;
const int max_prime = (int)1e6 + 3;
const int BLK = (int)700;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    long long int n, m, k;
    scanf("%lld %lld %lld", &n, &m, &k);
    if (m < n - 1 || m > n * (n - 1) / 2) {
      printf("NO\n");
      continue;
    }
    if (n == 1) {
      if (k > 1) {
        printf("YES\n");
      } else {
        printf("NO\n");
      }
      continue;
    }
    if (m == n * (n - 1) / 2) {
      if (k > 2) {
        printf("YES\n");
      } else {
        printf("NO\n");
      }
      continue;
    }
    if (m == n - 1) {
      if (k > 3) {
        printf("YES\n");
      } else {
        printf("NO\n");
      }
      continue;
    }
    if (k > 3) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }
  return 0;
}
