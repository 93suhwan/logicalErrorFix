#include <bits/stdc++.h>
using namespace std;
int T, ans;
char s[15], t[15];
void check(int n) {
  int num1 = 0, num2 = 0, has1 = 0, has2 = 0;
  for (int i = 1; i <= n; ++i) {
    if (i & 1) {
      if (t[i] == '1') num1++;
    } else {
      if (t[i] == '1') num2++;
    }
  }
  for (int i = n + 1; i <= 10; ++i) {
    if (i & 1)
      has1++;
    else
      has2++;
  }
  if (num1 > num2 + has2 || num2 > num1 + has1) ans = min(ans, n);
}
void dfs(int u) {
  check(u - 1);
  if (u == 11) return;
  if (s[u] == '?') {
    t[u] = '1';
    dfs(u + 1);
    t[u] = '0';
    dfs(u + 1);
  } else {
    t[u] = s[u];
    dfs(u + 1);
  }
}
int main() {
  scanf("%d", &T);
  while (T--) {
    ans = 10;
    scanf("%s", s + 1);
    dfs(1);
    printf("%d\n", ans);
  }
}
