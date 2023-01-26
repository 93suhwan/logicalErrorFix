#include <bits/stdc++.h>
using namespace std;
int T, n;
char ch;
bool vis[2][110];
void work() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> ch, vis[0][i] = (ch == '1');
  for (int i = 1; i <= n; ++i) cin >> ch, vis[1][i] = (ch == '1');
  for (int i = 2; i < n; ++i)
    if (vis[0][i] && vis[1][i] && (vis[0][i - 1] || vis[1][i - 1])) {
      printf("NO\n");
      return;
    }
  printf("YES\n");
}
int main() {
  cin >> T;
  while (T--) work();
  return 0;
}
