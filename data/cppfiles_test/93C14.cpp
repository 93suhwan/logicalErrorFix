#include <bits/stdc++.h>
using namespace std;
int read() {
  int a = 0;
  int f = 0;
  char p = getchar();
  while (!isdigit(p)) {
    f |= p == '-';
    p = getchar();
  }
  while (isdigit(p)) {
    a = (a << 3) + (a << 1) + (p ^ 48);
    p = getchar();
  }
  return f ? -a : a;
}
const int INF = 998244353;
int T;
long long n, m;
int main() {
  T = read();
  while (T--) {
    scanf("%lld%lld", &n, &m);
    long long now = 1;
    long long ans = 0;
    while (now < n && now <= m) {
      now <<= 1;
      ans++;
    }
    if (now < n) ans += (n - now + m - 1) / m;
    printf("%lld\n", ans);
  }
  return 0;
}
