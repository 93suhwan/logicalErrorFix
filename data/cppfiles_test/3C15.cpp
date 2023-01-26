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
int n, ans, Least = 1;
int Pow[10];
char num[10];
void dfs(int x, int sum) {
  if (x == n) {
    if (sum < Pow[n]) return;
    int isx = -1;
    for (int tmp = sum, i = n; tmp; tmp /= 10, i--) {
      if (num[i] == 'X') {
        if (isx != -1 && isx != tmp % 10)
          return;
        else if (isx == -1)
          isx = tmp % 10;
      } else if (isdigit(num[i]) && tmp % 10 + '0' != num[i])
        return;
    }
    ans++;
    return;
  }
  if (isdigit(num[n - x]))
    dfs(x + 1, sum + (num[n - x] - '0') * Pow[x + 1]);
  else
    for (int i = 0; i <= 9; i++) dfs(x + 1, sum + i * Pow[x + 1]);
}
int main() {
  scanf("%s", num + 1), n = strlen(num + 1);
  if (n == 1) {
    printf("%d\n", (num[1] == '0' || num[1] == '_' || num[1] == 'X') ? 1 : 0);
    return 0;
  }
  Pow[1] = 1;
  for (int i = 2; i <= n; i++) Pow[i] = Pow[i - 1] * 10;
  if (n == 1)
    dfs(1, 0), dfs(1, 5);
  else
    dfs(2, 0), dfs(2, 25), dfs(2, 50), dfs(2, 75);
  printf("%d\n", ans);
  return 0;
}
