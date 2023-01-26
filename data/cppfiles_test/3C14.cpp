#include <bits/stdc++.h>
using namespace std;
char ch[20];
int n, ans;
int flag, X;
int s;
void dfs(int x, int y) {
  if (x == n + 1) {
    if (s % 25 == 0 && s) ans++;
    return;
  }
  if (ch[x] == 'X') {
    if (x == 1 && y == 0) return;
    s = s * 10 + y;
    dfs(x + 1, y);
    s = (s - y) / 10;
    return;
  }
  if (ch[x] == '_') {
    for (int i = 0; i <= 9; i++) {
      if (x == 1 && !i) continue;
      if (x == n && i != 5 && i != 0) continue;
      if (x == n - 1 && i != 2 && i != 5 && i != 7 && i != 0) continue;
      s = s * 10 + i;
      dfs(x + 1, y);
      s = (s - i) / 10;
    }
  } else {
    if (x == 1 && ch[x] == '0') return;
    s = s * 10 + (ch[x] - '0');
    dfs(x + 1, y);
    s = (s - (ch[x] - '0')) / 10;
  }
}
int main() {
  scanf("%s", ch + 1);
  n = strlen(ch + 1);
  if (n == 1) {
    if (ch[1] == '0' || ch[1] == 'X' || ch[1] == '_')
      cout << 1;
    else
      cout << 0;
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    if (ch[i] == 'X') flag = 1;
  }
  int L = 0, R = 9;
  if (!flag) R = 0;
  for (int i = L; i <= R; i++) {
    dfs(1, i);
  }
  cout << ans;
  return 0;
}
