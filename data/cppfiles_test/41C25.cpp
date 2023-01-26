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
int n, k, ans;
int col[1005][1005];
void solve(int l, int r, int c) {
  if (l == r) return;
  int len = (r - l + k) / k, tot = (r - l + len) / len;
  for (int i = 1, x, y; i < tot; i++)
    for (int j = i + 1; j <= tot; j++)
      for (int p = 1; p <= len; p++)
        for (int q = 1; q <= len; q++) {
          x = l + (i - 1) * len + p - 1, y = l + (j - 1) * len + q - 1;
          if (y > r) break;
          col[x][y] = c;
        }
  for (int i = 1; i <= tot; i++)
    solve(l + (i - 1) * len, min(l + i * len - 1, r), c + 1);
}
int main() {
  n = rd(), k = rd();
  solve(1, n, 1);
  for (int i = 1; i < n; i++)
    for (int j = i + 1; j <= n; j++) ans = max(ans, col[i][j]);
  printf("%d\n", ans);
  for (int i = 1; i < n; i++)
    for (int j = i + 1; j <= n; j++) printf("%d ", col[i][j]);
  printf("\n");
  return 0;
}
