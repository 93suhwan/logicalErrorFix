#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5, N1 = maxn + 7;
const long long inf = 0x3f3f3f3f3f3fll;
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
int n;
int a[N1], b[N1];
long long sa[N1], sb[N1];
long long calc3(long long x) { return x * (x - 1) * (x - 2) / 6; }
void solve() {
  read(n);
  long long ans = calc3(1ll * n), tmp;
  for (int i = 1; i <= n; i++) read(a[i]), read(b[i]);
  tmp = 0;
  for (int i = 1; i <= n; i++) {
    tmp += sa[a[i]] * sb[b[i]];
    sa[a[i]]++;
    sb[b[i]]++;
  }
  for (int i = 1; i <= n; i++) sa[i] = 0;
  for (int i = 1; i <= n; i++) {
    sb[b[i]]--;
    tmp += sa[a[i]] * sb[b[i]];
    sa[a[i]]++;
  }
  for (int i = 1; i <= n; i++) {
    sa[a[i]]--;
    tmp += sa[a[i]] * sb[b[i]];
    sb[b[i]]++;
  }
  for (int i = 1; i <= n; i++) sb[i] = 0;
  for (int i = n; i >= 1; i--) {
    tmp += sa[a[i]] * sb[b[i]];
    sa[a[i]]++;
    sb[b[i]]++;
  }
  for (int i = 1; i <= n; i++)
    tmp += calc3(sa[i]) + calc3(sb[i]), sa[i] = sb[i] = 0;
  ans -= tmp;
  printf("%lld\n", ans);
}
int main() {
  int Te;
  read(Te);
  while (Te--) solve();
  return 0;
}
