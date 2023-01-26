#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e5 + 5;
const long long inf = 1e18;
long long n, f[10][30], ans, flag;
char a[maxn];
long long dfs(long long pos, long long re, long long x) {
  if (pos <= 0) {
    if (re == 0)
      return 1;
    else
      return 0;
  }
  if (f[pos][re] != -1) return f[pos][re];
  long long tmp = 0;
  if (a[pos] == '_') {
    long long s = 0;
    if (pos == 1) s = 1;
    for (long long i = s; i <= 9; i++) {
      for (long long j = 0; j <= 24; j++) {
        if ((i + j * 10) % 25 == re) tmp += dfs(pos - 1, j, x);
      }
    }
  } else {
    long long now = 0;
    if (a[pos] == 'X')
      now = x, flag = 1;
    else
      now = a[pos] - '0';
    for (long long i = 0; i <= 24; i++) {
      if ((i * 10 + now) % 25 == re) tmp += dfs(pos - 1, i, x);
    }
    if (pos == 1 && now == 0) tmp = 0;
  }
  return f[pos][re] = tmp;
}
signed main() {
  cin >> (a + 1);
  n = strlen(a + 1);
  for (long long i = 0; i <= 9; i++) {
    memset(f, -1, sizeof(f));
    ans += dfs(n, 0, i);
  }
  if (!flag) ans /= 10;
  if (n == 1 && a[1] == '0') ans = 1;
  cout << ans;
  return 0;
}
