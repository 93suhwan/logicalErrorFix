#include <bits/stdc++.h>
using namespace std;
namespace IO {
int read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
void write(int x, char sp) {
  char ch[20];
  int len = 0;
  if (x < 0) x = -x, putchar('-');
  do {
    ch[len++] = x % 10 + '0';
    x /= 10;
  } while (x);
  for (int i = len - 1; ~i; i--) putchar(ch[i]);
  putchar(sp);
}
void ckmin(int& x, int y) { x = x < y ? x : y; }
void ckmax(int& x, int y) { x = x > y ? x : y; }
}  // namespace IO
using namespace IO;
int n, U, ans, mn[30], val[30], sum[1 << 20], buc[800010], tim[800010][21],
    f[1 << 20];
const int bs = 400000;
char ch[30];
signed main() {
  n = read();
  U = (1 << n) - 1;
  for (int i = 1; i <= n; i++) {
    scanf("%s", ch + 1);
    memset(buc, 0, sizeof(buc));
    int m = 0, now = 0, len = strlen(ch + 1);
    for (int j = 1; j <= len; j++) {
      now += ch[j] == '(' ? 1 : -1;
      if (m > now) tim[bs + m][i] = buc[bs + m], --m;
      ++buc[bs + now];
    }
    tim[bs + m][i] = buc[bs + m];
    mn[i] = m;
    val[i] = now;
  }
  for (int i = 1; i <= U; i++)
    for (int j = 0; j < n; j++)
      if (i & (1 << j)) sum[i] += val[j + 1];
  memset(f, 0xc0, sizeof(f));
  f[0] = 0;
  for (int i = 0; i <= U; i++)
    for (int j = 1; j <= n; j++)
      if (!(i & (1 << j - 1)) && sum[i] + mn[j] >= 0)
        ckmax(f[i | (1 << j - 1)], f[i] + tim[bs - sum[i]][j]);
  for (int i = 0; i < +U; i++)
    if (sum[i] >= 0) {
      ckmax(ans, f[i]);
      for (int j = 1; j <= n; j++)
        if (!(i & (1 << j - 1))) ckmax(ans, f[i] + tim[bs - sum[i]][j]);
    }
  write(ans, '\n');
  return 0;
}
