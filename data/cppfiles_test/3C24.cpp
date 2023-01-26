#include <bits/stdc++.h>
using namespace std;
char s[10];
int now[10];
int n;
int ans;
void dfs(int now1, int flag1) {
  if (now1 == n) {
    int flag = 0;
    int temp1 = 0;
    if (n == 1 && now[0] == 0) {
      ans++;
      return;
    }
    for (int i = 0; i < n; i++) {
      if (now[i] != 0) flag = 1;
      if (now[i] == 0 && !flag) return;
      temp1 *= 10;
      temp1 += now[i];
    }
    if (temp1 % 25 == 0) ans++;
    return;
  }
  if (isdigit(s[now1])) {
    int temp2 = now[now1];
    now[now1] = s[now1] - '0';
    dfs(now1 + 1, flag1);
    now[now1] = temp2;
  }
  if (s[now1] == 'X') {
    if (flag1 != -1) {
      int temp2 = now[now1];
      now[now1] = flag1;
      dfs(now1 + 1, flag1);
      now[now1] = temp2;
    } else {
      for (int i = 0; i < 10; i++) {
        int temp2 = now[now1];
        now[now1] = i;
        dfs(now1 + 1, i);
        now[now1] = temp2;
      }
    }
  }
  if (s[now1] == '_') {
    for (int i = 0; i < 10; i++) {
      int temp2 = now[now1];
      now[now1] = i;
      dfs(now1 + 1, flag1);
      now[now1] = temp2;
    }
  }
}
int main() {
  cin >> s;
  n = strlen(s);
  dfs(0, -1);
  cout << ans;
  return 0;
}
