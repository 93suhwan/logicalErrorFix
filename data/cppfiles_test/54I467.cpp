#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &n) {
  T w = 1;
  n = 0;
  char ch = getchar();
  while (!isdigit(ch) && ch != EOF) {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (isdigit(ch) && ch != EOF) {
    n = (n << 1) + (n << 3) + (ch & 15);
    ch = getchar();
  }
  n *= w;
}
const int N = 2e5 + 5;
int T, n, k;
long long a[N + 2], ia[N + 2], b[N + 2], s[N + 2];
long long ksm(long long a, long long b) {
  long long x = 1;
  while (b) {
    if (b & 1) x = x * a % 1000000007;
    a = a * a % 1000000007;
    b >>= 1;
  }
  return x;
}
long long dp(int i) {
  if (i > k) return 1;
  long long res = (s[(n - 1) >> 1] + (n & 1)) * dp(i + 1) % 1000000007;
  return (res + (n % 2 == 0) * ksm(b[k - i], n));
}
int main() {
  read(T);
  a[0] = ia[0] = 1;
  for (int i = 1; i < N; i++) {
    a[i] = a[i - 1] * i % 1000000007;
    ia[i] = ksm(a[i], 1000000007 - 2);
  }
  b[0] = 1;
  for (int i = 1; i < N; i++) b[i] = b[i - 1] * 2 % 1000000007;
  while (T--) {
    read(n);
    read(k);
    s[0] = 1;
    for (int i = 1; (i << 1) <= n; i++)
      s[i] = (s[i - 1] +
              a[n] * ia[n - (i << 1)] % 1000000007 * ia[i << 1] % 1000000007) %
             1000000007;
    printf("%lld\n", dp(1));
  }
  return 0;
}
