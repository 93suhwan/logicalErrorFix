#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
  return x * f;
}
void write(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
long long ans[55][55];
void solve(void) {
  memset(ans, 0, sizeof(ans));
  long long n = read(), times = 0, p = 0, b = 0, tmp;
  string s;
  cin >> s;
  for (long long i = 0; i < s.length(); i++)
    if (s[i] == '2') times++;
  if (times && times <= 2) {
    cout << "NO\n";
    return;
  }
  for (long long i = 0; i < n; i++) {
    if (s[i] == '1')
      for (long long j = 0; j < n; j++) ans[i][j] = 1, ans[j][i] = 1;
  }
  for (long long i = 0; i < n; i++) {
    if (s[i] == '2') {
      p++;
      if (p == 1) {
        tmp = i + 1;
        while (s[tmp] == '1') tmp++;
        ans[i][tmp] = 2, b = i;
      } else if (p == 2) {
        tmp = i + 1;
        while (s[tmp] == '1') tmp++;
        ans[i][tmp] = 2;
      } else if (p == 3)
        ans[i][b] = 2;
      else
        for (long long j = 0; j < i; j++)
          if (!ans[i][j]) ans[i][j] = 2;
    }
  }
  cout << "YES\n";
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < n; j++) {
      if (i == j)
        putchar('X');
      else if (ans[i][j] == 1)
        putchar('=');
      else if (ans[i][j] == 2)
        putchar('+');
      else
        putchar('-');
    }
    putchar('\n');
  }
}
signed main(void) {
  long long t = read();
  while (t--) solve();
  return 0;
}
