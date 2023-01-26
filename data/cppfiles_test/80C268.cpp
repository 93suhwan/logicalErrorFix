#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  register long long x = 0, f = 0;
  register char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = 1;
    c = getchar();
  }
  while (c >= '0' && c <= '9')
    x = (x << 3) + (x << 1) + (c ^ '0'), c = getchar();
  return f ? -x : x;
}
inline void write(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
long long t, n;
string s;
signed main() {
  t = read();
  while (t--) {
    n = read();
    cin >> s;
    s = ' ' + s;
    for (register long long i = 1; i <= n; ++i)
      if (s[i] == '0') {
        if (i > n / 2)
          cout << "1 " << i << " 1 " << i - 1 << '\n';
        else
          cout << i << " " << n << " " << i + 1 << " " << n << '\n';
        goto end;
      }
    cout << "1 " << n - 1 << " 2 " << n << '\n';
  end:;
  }
  return 0;
}
