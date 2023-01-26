#include <bits/stdc++.h>
using namespace std;
string s;
int n;
int ans = 0;
void dfs(int flag, int sum, int a) {
  if (a == n) {
    if (sum % 25 == 0) ans++;
    return;
  }
  if (s[a] != 'X' && s[a] != '_') {
    dfs(flag, sum += sum * 10 + s[a] - '0', a + 1);
  } else if (s[a] == '_') {
    int left = 0;
    if (a == 0 && n > 1) left = 1;
    for (int i = left; i <= 9; i++) dfs(flag, sum * 10 + i, a + 1);
  } else {
    if (flag != -1) {
      dfs(flag, sum * 10 + flag, a + 1);
    } else {
      int left = 0;
      if (a == 0 && n > 1) left = 1;
      for (int i = left; i <= 9; i++) {
        dfs(i, sum * 10 + i, a + 1);
      }
    }
  }
}
int main() {
  cin >> s;
  n = s.size();
  if (s[0] == '0' && s.size() > 1)
    cout << "0" << endl;
  else {
    dfs(-1, 0, 0);
    cout << ans << endl;
  }
}
