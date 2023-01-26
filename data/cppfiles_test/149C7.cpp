#include <bits/stdc++.h>
using namespace std;
const long long maxn = 2010;
char s[maxn], c[maxn], ans[maxn * maxn];
signed main() {
  long long T;
  scanf("%lld", &T);
  while (T--) {
    long long n, k;
    long long x;
    scanf("%lld%lld%lld", &n, &k, &x);
    scanf("%s", s + 1);
    x--;
    for (long long i = 1; i <= n; ++i) c[i] = s[n - i + 1];
    long long cnt = 0, pos = 0;
    c[n + 1] = 'a';
    for (long long i = 1; i <= n + 1; ++i) {
      if (c[i] == '*')
        cnt++;
      else if (c[i] == 'a') {
        cnt = cnt * k + 1;
        long long t = x % cnt;
        for (long long i = 1; i <= t; ++i) ans[++pos] = 'b';
        x /= cnt;
        ans[++pos] = 'a';
        cnt = 0;
      }
    }
    for (long long i = pos - 1; i >= 1; --i) printf("%c", ans[i]);
    printf("\n");
  }
  return 0;
}
