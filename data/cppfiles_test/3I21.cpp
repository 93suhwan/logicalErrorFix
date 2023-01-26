#include <bits/stdc++.h>
using namespace std;
char s[11];
int ans;
void dfs(int d, int num, int x) {
  if (!s[d]) {
    if (num % 25 == 0) {
      ans++;
    }
    return;
  }
  if (isdigit(s[d]))
    dfs(d + 1, num * 10 + s[d] - '0', x);
  else if (s[d] == '_') {
    int st = (d == 0) ? 1 : 0;
    for (int i = st; i <= 9; i++) {
      dfs(d + 1, num * 10 + i, x);
    }
  } else {
    if (x != -1) {
      dfs(d + 1, num * 10 + x, x);
    } else {
      int st = (d == 0) ? 1 : 0;
      for (x = st; x <= 9; x++) dfs(d + 1, num * 10 + x, x);
    }
  }
}
int main() {
  cin >> s;
  dfs(0, 0, -1);
  cout << ans << endl;
  return 0;
}
