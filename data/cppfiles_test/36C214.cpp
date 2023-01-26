#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long s = 0, w = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    s = (s << 1) + (s << 3) + (ch ^ 48);
    ch = getchar();
  }
  return s * w;
}
long long t, n, prime[20005], tot, ans, cnt, minn;
bool isprime[20005], flag;
void pre() {
  for (register long long i = 2; i <= 20000; i++) {
    if (!isprime[i]) prime[++tot] = i;
    for (register long long j = 1; j <= tot && i * prime[j] <= 20000; j++) {
      isprime[i * prime[j]] = 1;
      if (i % prime[j] == 0) break;
    }
  }
}
int main() {
  t = read();
  pre();
  while (t--) {
    n = read(), flag = 1, ans = 0, minn = 0x3fffffff;
    for (register long long i = 1; i <= n; i++) {
      long long x = read();
      if (x % 2 && x < minn) minn = x, cnt = i;
      ans += x;
    }
    for (register long long i = 1; i <= tot && flag; i++)
      if (prime[i] == ans) flag = 0;
    if (flag) {
      printf("%lld\n", n);
      for (register long long i = 1; i <= n; i++) printf("%lld ", i);
    } else {
      printf("%lld\n", n - 1);
      for (register long long i = 1; i <= n; i++)
        if (i != cnt) printf("%lld ", i);
    }
    printf("\n");
  }
  return 0;
}
