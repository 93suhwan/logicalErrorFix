#include <bits/stdc++.h>
using namespace std;
struct incs {
  char c;
  int cnt;
} inc[30];
int len, ls, ans, s1um;
int main() {
  ios::sync_with_stdio(false);
  int test;
  string str;
  bool check;
  cin >> test;
  while (test--) {
    len = 0;
    cin >> str;
    ls = str.size();
    for (register int i = 0; i < ls; i++) {
      check = false;
      for (register int j = 1; j <= len; j++) {
        if (inc[j].c == str[i]) {
          inc[j].cnt++;
          check = true;
        }
      }
      if (!check) {
        len++;
        inc[len].c = str[i];
        inc[len].cnt = 1;
      }
    }
    ans = s1um = 0;
    for (register int i = 1; i <= len; i++) {
      if (inc[i].cnt >= 2)
        ans++;
      else
        s1um++;
    }
    printf("%d\n", ans + s1um / 2);
  }
  return 0;
}
