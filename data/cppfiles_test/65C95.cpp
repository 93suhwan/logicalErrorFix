#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  char c = getchar();
  long long first = 0;
  bool f = 0;
  for (; !isdigit(c); c = getchar()) f ^= !(c ^ 45);
  for (; isdigit(c); c = getchar())
    first = (first << 1) + (first << 3) + (c ^ 48);
  if (f) first = -first;
  return first;
}
const long long M = 2e5 + 10;
long long n, a[M], c[M], ans[M], sum[M];
string s;
signed main() {
  n = read();
  for (long long i = 1; i <= n; i++) a[i] = read();
  sort(a + 1, a + 1 + n);
  cin >> s;
  long long f = 1;
  for (long long i = 1; i <= n; i++) c[i] = s[i - 1] == 'L' ? 1 : -1;
  if (c[n] == -1) {
    f = -1;
    for (long long i = 1; i <= n; i++) c[i] *= -1;
  }
  long long tl = 1, tr = n;
  for (long long i = (n & 1 ? 2 : 1); i <= n; i += 2) a[i] *= -1;
  for (long long i = 1; i <= n; i++) sum[i] = a[i] + sum[i - 1];
  for (long long i = n - 1; i >= 1; i--)
    if ((sum[tr - 1] - sum[tl - 1] > 0) == (c[i] == 1))
      ans[i + 1] = a[tr--];
    else
      ans[i + 1] = a[tl++];
  ans[1] = a[tl];
  for (long long i = 1; i <= n; i++) ans[i] *= f;
  for (long long i = 1; i <= n; i++)
    if (ans[i] > 0)
      printf("%lld L\n", ans[i]);
    else
      printf("%lld R\n", -ans[i]);
  return 0;
}
