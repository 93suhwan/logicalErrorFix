#include <bits/stdc++.h>
using namespace std;
char s[105];
int n, ans = 0;
void DFS(int dep, int pre, int sum, int prez) {
  if (dep > 1 && prez) return;
  if (dep == n + 1) {
    ans += (sum % 25 == 0);
    return;
  }
  if (isdigit(s[dep]))
    DFS(dep + 1, pre, sum * 10 + s[dep] - '0', prez && s[dep] == '0');
  else if (s[dep] == '_') {
    for (int i = prez; i < 10; i++) DFS(dep + 1, pre, sum * 10 + i, 0);
  } else {
    if (pre == -1) {
      for (int i = prez; i < 10; i++) DFS(dep + 1, i, sum * 10 + i, 0);
    } else
      DFS(dep + 1, pre, sum * 10 + pre, prez && pre == 0);
  }
}
int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  DFS(1, -1, 0, 1);
  printf("%d\n", ans);
  return 0;
}
