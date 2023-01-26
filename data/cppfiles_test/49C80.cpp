#include <bits/stdc++.h>
using namespace std;
const int N = 16, N2 = 16400;
int n;
int a[N];
long long G[N][N];
long long cr[N][N2];
long long prob[N2];
long long PowerMOD(long long a, int n, long long c = 1) {
  for (; n; n >>= 1, a = a * a % 1000000007)
    if (n & 1) c = c * a % 1000000007;
  return c;
}
long long cross(long long A, long long B) {
  long long ret = 1;
  for (; A; A &= A - 1) {
    ret = ret * cr[__builtin_ctz(A)][B] % 1000000007;
  }
  return ret;
}
int main() {
  long long ans = 0;
  cin >> n;
  long long ALL = (1 << n) - 1;
  for (long long i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < n; j++) {
      G[i][j] = PowerMOD(a[i] + a[j], 1000000007 - 2, a[i]);
    }
  }
  for (long long i = 0; i < n; i++) {
    cr[i][0] = 1;
    for (long long j = 1; j < ALL + 1; j++) {
      cr[i][j] = cr[i][j & (j - 1)] * G[i][__builtin_ctz(j)] % 1000000007;
    }
  }
  for (long long i = 1; i < ALL + 1; i++) {
    prob[i] = 1;
    for (int j = i & (i - 1); j; j = (j - 1) & i) {
      (prob[i] -= prob[j] * cross(j, i - j)) %= 1000000007;
    }
    (ans += prob[i] * cross(i, ALL - i) % 1000000007 * __builtin_popcount(i)) %=
        1000000007;
  }
  printf("%lld\n", (ans + 1000000007) % 1000000007);
  return 0;
}
