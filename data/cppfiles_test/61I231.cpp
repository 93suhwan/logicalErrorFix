#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize(2)
#pragma GCC optimize(3)
inline int read() {
  int x = 0, f = 0;
  char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
  return f ? -x : x;
}
inline long long llread() {
  long long x = 0, f = 0;
  char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
  return f ? -x : x;
}
long long n, a[200010], b[200010], ta[200010], tb[200010];
void work() {
  n = llread();
  for (long long i = (1); i <= (n); i++) {
    a[i] = llread(), b[i] = llread();
    ta[a[i]]++;
    tb[b[i]]++;
  }
  long long ans = 0;
  for (long long i = (1); i <= (n); i++) {
    ta[a[i]]--;
    tb[b[i]]--;
    ans += ta[a[i]] * tb[b[i]];
  }
  printf("%lld\n", n * (n - 1) * (n - 2) / 6 - ans);
}
signed main() {
  long long T = llread();
  while (T--) work();
  return 0;
}
