#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &x) {
  x = 0;
  T k = 1;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') k = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    x = x * 10 + c - '0';
    c = getchar();
  }
  x *= k;
}
const int N = 5005;
const int p = 998244353;
char s[N];
int nxt[N];
int fac[N];
int facinv[N];
inline long long qpow(long long a, int b) {
  long long ans = 1;
  while (b) {
    if (b & 1) (ans *= a) %= p;
    (a *= a) %= p;
    b >>= 1;
  }
  return ans;
}
inline long long C(int n, int m) {
  return m > n ? 0 : (long long)fac[n] * facinv[m] % p * facinv[n - m] % p;
}
inline int add(int a, int b) { return (a += b) >= p ? a - p : a; }
inline int sub(int a, int b) { return (a -= b) < 0 ? a + p : a; }
int main() {
  int n, k;
  read(n), read(k);
  scanf("%s", s + 1);
  if (k == 0) {
    puts("1");
    return 0;
  }
  int cnt = 0;
  for (int i = 1; i <= n; ++i) {
    cnt += (s[i] == '1');
  }
  fac[0] = 1;
  for (int i = 1; i <= n; ++i) {
    fac[i] = (long long)fac[i - 1] * i % p;
  }
  facinv[n] = qpow(fac[n], p - 2);
  for (int i = n; i; --i) {
    facinv[i - 1] = (long long)facinv[i] * i % p;
  }
  if (cnt < k) {
    puts("1");
    return 0;
  }
  if (cnt == k) {
    printf("%lld\n", C(n, k));
    return 0;
  }
  cnt = 0;
  s[n + 1] = '1';
  int l = 1, r = 0;
  while (cnt < k) cnt += (s[++r] == '1');
  while (s[r + 1] != '1') ++r;
  int ans = C(r - l + 1, k);
  while (r < n) {
    int r0 = r;
    ++r;
    while (s[r + 1] != '1') ++r;
    ++l;
    ans = add(ans, sub(C(r - l + 1, k), C(r0 - l + 1, k - 1)));
  }
  printf("%d\n", ans);
  return 0;
}
