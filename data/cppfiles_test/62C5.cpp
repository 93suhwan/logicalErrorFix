#include <bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &x) {
  x = 0;
  long long f = 1;
  char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = -1;
  for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
  x = x * f;
}
long long n, m, q, s1, s2, ans = 0;
long long sav[120];
long long b[1020][1020];
long long Fquery(long long x, long long y) {
  if (abs(x - y) > 1) return 0;
  if (x == 1 and y == 1) return n * m;
  if (x == y) return 2 * (n - x + 1) * (m - y + 1);
  return (n - x + 1) * (m - y + 1);
}
long long find1(long long s, long long x, long long y, long long dir) {
  if ((dir == 0 and b[x - 1][y]) or (dir == 0 and x == 1)) return s;
  if ((dir == 1 and b[x][y - 1]) or (dir == 1 and y == 1)) return s;
  if (dir == 0)
    return find1(s + 1, x - 1, y, 1);
  else
    return find1(s + 1, x, y - 1, 0);
}
long long find2(long long s, long long x, long long y, long long dir) {
  if ((dir == 0 and b[x + 1][y]) or (dir == 0 and x == n)) return s;
  if ((dir == 1 and b[x][y + 1]) or (dir == 1 and y == m)) return s;
  if (dir == 0)
    return find2(s + 1, x + 1, y, 1);
  else
    return find2(s + 1, x, y + 1, 0);
}
signed main() {
  read(n), read(m), read(q);
  for (long long i = 1; i <= n; i++)
    for (long long j = 1; j <= m; j++) ans += Fquery(i, j);
  for (long long i = 1; i <= q; i++) {
    read(s1), read(s2);
    sav[1] = find1(1, s1, s2, 0);
    sav[2] = find1(1, s1, s2, 1);
    sav[3] = find2(1, s1, s2, 0);
    sav[4] = find2(1, s1, s2, 1);
    if (b[s1][s2] == 0)
      b[s1][s2] = 1, ans -= sav[1] * sav[4] + sav[2] * sav[3], ans++;
    else
      b[s1][s2] = 0, ans += sav[1] * sav[4] + sav[2] * sav[3], ans--;
    cout << ans << endl;
  }
  return 0;
}
