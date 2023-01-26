#include <bits/stdc++.h>
using namespace std;
char s[12];
int len, ans, k;
int cal(int mask) { return __builtin_popcount(mask); }
void dfs(int lim, int pos, int mask, int sum) {
  if (pos == len + 1) {
    ans = sum;
    return;
  }
  int start = 0;
  if (lim) {
    start = s[pos];
  }
  for (int i = start; i <= 9; i++) {
    if (ans == 0 && cal(mask | (1 << i)) <= k) {
      dfs(lim && i == start, pos + 1, mask | (1 << i), sum * 10 + i);
    }
  }
}
int main() {
  int t;
  int n;
  cin >> t;
  while (t--) {
    scanf("%s", s + 1);
    cin >> k;
    len = strlen(s + 1);
    for (int i = 1; i <= len; i++) {
      s[i] -= '0';
    }
    ans = 0;
    dfs(1, 1, 0, 0);
    cout << ans << endl;
  }
  return 0;
}
