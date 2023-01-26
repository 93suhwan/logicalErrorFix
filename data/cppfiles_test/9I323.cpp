#include <bits/stdc++.h>
using namespace std;
const int N = 66;
bool solve() {
  char str[N];
  scanf("%s", str + 1);
  int len = strlen(str + 1);
  bool a[N], b[N];
  for (int i = 1; i <= 26; i++) a[i] = b[i] = 0;
  int cnta = 0, cntb = 0;
  for (int i = 1; i <= len / 2; i++) {
    bool flag = 0;
    for (int j = 1; j <= len; j++) {
      if (str[j] == '0' || a[str[j] - 'a' + 1]) continue;
      a[str[j] - 'a' + 1] = 1;
      ++cnta, flag = 1;
      str[j] = '0';
      break;
    }
    if (!flag) break;
    flag = 0;
    for (int j = 1; j <= len; j++) {
      if (str[j] == '0' || b[str[j] - 'a' + 1]) continue;
      b[str[j] - 'a' + 1] = 1;
      ++cntb, flag = 1;
      str[j] = '0';
      break;
    }
    if (!flag) break;
  }
  printf("%d\n", min(cnta, cntb));
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
