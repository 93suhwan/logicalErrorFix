#include <bits/stdc++.h>
using namespace std;
inline int rd() {
  int x = 0;
  char ch, t = 0;
  while (!isdigit(ch = getchar())) t |= ch == '-';
  while (isdigit(ch)) x = x * 10 + (ch ^ 48), ch = getchar();
  return x = t ? -x : x;
}
inline long long maxll(long long x, long long y) { return x > y ? x : y; }
inline long long minll(long long x, long long y) { return x < y ? x : y; }
inline long long absll(long long x) { return x > 0ll ? x : -x; }
inline long long gcd(long long x, long long y) {
  return (y == 0) ? x : gcd(y, x % y);
}
int n, m;
int mp[50][50];
inline bool check(int a, int b, int c, int d, int e) {
  if (mp[a][b] && mp[a][c] && mp[a][d] && mp[a][e] && mp[b][c] && mp[b][d] &&
      mp[b][e] && mp[c][d] && mp[c][e] && mp[d][e])
    return true;
  if (!mp[a][b] && !mp[a][c] && !mp[a][d] && !mp[a][e] && !mp[b][c] &&
      !mp[b][d] && !mp[b][e] && !mp[c][d] && !mp[c][e] && !mp[d][e])
    return true;
  return false;
}
int main() {
  n = rd(), m = rd();
  for (int i = 1, x, y; i <= m; i++) {
    x = rd(), y = rd();
    if (x <= 48 && y <= 48) mp[x][y] = mp[y][x] = true;
  }
  for (int a = 1; a <= min(n, 48); a++)
    for (int b = a + 1; b <= min(n, 48); b++)
      for (int c = b + 1; c <= min(n, 48); c++)
        for (int d = c + 1; d <= min(n, 48); d++)
          for (int e = d + 1; e <= min(n, 48); e++)
            if (check(a, b, c, d, e)) {
              printf("%d %d %d %d %d\n", a, b, c, d, e);
              return 0;
            }
  printf("-1\n");
  return 0;
}
