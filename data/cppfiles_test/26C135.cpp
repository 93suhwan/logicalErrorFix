#include <bits/stdc++.h>
using namespace std;
const int n = 10;
char s[15];
int res(int step, int flag) {
  int ans = 0;
  for (int i = step; i <= n; i++) ans += (flag == (i & 1));
  return ans;
}
void dfs(int step, int sc1, int sc2, int &ans) {
  if (step > 10) return;
  if (step > ans) return;
  if (sc1 + res(step, 1) < sc2 || sc1 > res(step, 0) + sc2) {
    ans = min(ans, step - 1);
    return;
  }
  if (step & 1) {
    if (s[step] == '?') {
      dfs(step + 1, sc1, sc2, ans);
      dfs(step + 1, sc1 + 1, sc2, ans);
    } else
      dfs(step + 1, sc1 + (s[step] == '1'), sc2, ans);
  } else {
    if (s[step] == '?') {
      dfs(step + 1, sc1, sc2, ans);
      dfs(step + 1, sc1, sc2 + 1, ans);
    } else
      dfs(step + 1, sc1, sc2 + (s[step] == '1'), ans);
  }
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    scanf("%s", s + 1);
    int ans = 10;
    dfs(1, 0, 0, ans);
    cout << ans << "\n";
  }
  return 0;
}
