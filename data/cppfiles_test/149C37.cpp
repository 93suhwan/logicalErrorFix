#include <bits/stdc++.h>
using namespace std;
long long t, n, k, x;
char s[2010];
void dfs(long long pos, long long rest) {
  if (pos == 0) return;
  long long cnt = 0;
  while (pos && s[pos--] == '*') cnt++;
  dfs(pos, rest / (cnt * k + 1));
  if (s[pos + 1] == 'a') putchar('a');
  for (long long i = 1; i <= rest % (cnt * k + 1); i++) putchar('b');
}
signed main() {
  scanf("%lld", &t);
  while (t--) {
    scanf("%lld%lld%lld", &n, &k, &x);
    scanf("%s", s + 1);
    dfs(n, x - 1);
    putchar('\n');
  }
  return 0;
}
