#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 50;
int T, n, ans;
char s[2][N];
bool ban[N];
void solve() {
  scanf("%d", &n);
  ans = 0;
  scanf("%s%s", s[0] + 1, s[1] + 1);
  for (int i = 1, fl = 0; i <= n; i++) {
    if (s[0][i] != s[1][i]) ban[i] = 1, ans += 2, fl = 0;
    if (s[0][i] + s[1][i] == '0' + '0') {
      if (fl == 2)
        ans += 2, fl = 0;
      else
        fl = 1, ans++;
    }
    if (s[0][i] + s[1][i] == '1' + '1') {
      if (fl == 1)
        ans++, fl = 0;
      else
        fl = 2;
    }
  }
  printf("%d\n", ans);
}
int main() {
  scanf("%d", &T);
  while (T--) solve();
  return 0;
}
