#include <bits/stdc++.h>
using namespace std;
int n, k;
char s[5005];
long long C[5005][5005];
int main() {
  scanf("%d%d", &n, &k);
  C[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    C[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % 998244353;
    }
  }
  scanf("%s", s + 1);
  int cur = 0, x, y;
  for (int i = 1; i <= n; i++)
    if (s[i] == '1') cur++;
  if (cur < k) {
    printf("1\n");
    return 0;
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    cur = s[i] - '0';
    for (int j = i + 1; j <= n; j++) {
      cur += s[j] - '0';
      if (cur > k) break;
      x = cur;
      y = j - i + 1 - cur;
      if (s[i] == '0')
        x--;
      else
        y--;
      if (s[j] == '0')
        x--;
      else
        y--;
      if (x < 0 || y < 0) continue;
      ans += C[x + y][x];
      ans %= 998244353;
    }
  }
  printf("%lld\n", (ans + 1) % 998244353);
  return 0;
}
