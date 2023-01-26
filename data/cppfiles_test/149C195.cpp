#include <bits/stdc++.h>
using namespace std;
inline void read(long long &x) {
  x = 0;
  long long f = 1;
  char ch = getchar();
  while (ch != 45 && (ch > '9' || ch < '0')) ch = getchar();
  if (ch == 45) {
    f = -1, ch = getchar();
  }
  while (ch <= '9' && ch >= '0') {
    x = x * 10 + ch - 48;
    ch = getchar();
  }
  x *= f;
}
void cmin(long long &a, long long b) { a = min(a, b); }
void cmax(long long &a, long long b) { a = max(a, b); }
const long long N = 2e3 + 10;
long long i, j, k, n, s, t, m;
char ch[N], ans[N];
long long a[N], b[N];
signed main() {
  read(t);
  while (t--) {
    read(n), read(k), read(s);
    m = 0;
    scanf("%s", ch + 1);
    memset(a, 0, sizeof(a));
    for (i = 1; i <= n; i++) {
      if (ch[i] != ch[i - 1]) ++m;
      if (ch[i] == 'a')
        a[m]--;
      else
        a[m]++;
    }
    s--;
    for (i = m; i >= 1; i--) {
      if (a[i] < 0) {
        b[i] = a[i];
        continue;
      }
      b[i] = s % (a[i] * k + 1);
      s /= (a[i] * k + 1);
    }
    for (i = 1; i <= m; i++) {
      for (j = 1; j <= abs(b[i]); j++) putchar((b[i] < 0 ? 'a' : 'b'));
    }
    cout << endl;
  }
  return 0;
}
