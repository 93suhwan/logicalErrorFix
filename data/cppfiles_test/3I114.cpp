#include <bits/stdc++.h>
using namespace std;
char s[15];
int ans, n;
void dfs(int u, bool f, int c, int x) {
  if (u > n) {
    if (c % 25 == 0) ans++;
    return;
  }
  if (!f && s[u] == '0') return;
  if (isdigit(s[u])) {
    dfs(u + 1, true, c * 10 + (s[u] - '0'), x);
    return;
  }
  if (s[u] == '_') {
    for (int i = 1; i <= 9; i++) dfs(u + 1, true, c * 10 + i, x);
    if (f) dfs(u + 1, true, c * 10, x);
    return;
  }
  if (s[u] == 'X') {
    if (x != -1)
      dfs(u + 1, f, c * 10 + x, x);
    else {
      for (int i = 1; i <= 9; i++) dfs(u + 1, true, c * 10 + i, i);
      if (f) dfs(u + 1, true, c * 10, 0);
    }
    return;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> (s + 1), n = strlen(s + 1);
  dfs(1, false, 0, -1);
  cout << ans << "\n";
  return 0;
}
