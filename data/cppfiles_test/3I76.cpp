#include <bits/stdc++.h>
using namespace std;
string s;
int ans;
void dfs(int pos, int sum, int x) {
  if (pos == s.size()) {
    if (sum % 25 == 0) ans++;
    return;
  }
  if (s[pos] >= '0' && s[pos] <= '9') {
    sum = sum * 10 + s[pos] - '0';
    dfs(pos + 1, sum, x);
  }
  if (s[pos] == 'X') {
    if (x == -1) {
      for (int i = 0; i <= 9; i++) {
        if (pos == 0 && i == 0) continue;
        dfs(pos + 1, sum * 10 + i, i);
      }
    } else {
      dfs(pos + 1, sum * 10 + x, x);
    }
  }
  if (s[pos] == '_') {
    for (int i = 0; i <= 9; i++) {
      if (pos == 0 && i == 0) continue;
      dfs(pos + 1, sum * 10 + i, x);
    }
  }
}
int main() {
  cin >> s;
  dfs(0, 0, -1);
  if (s[0] == '0') {
    if (s.size() != 1) {
      printf("0\n");
      return 0;
    }
  }
  printf("%d\n", ans);
  return 0;
}
