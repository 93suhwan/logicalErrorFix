#include <bits/stdc++.h>
using namespace std;
char s[55];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t, n, flag = 0;
  cin >> t;
  while (t--) {
    cin >> n;
    cin >> s;
    flag = 0;
    for (int i = 1; i < n; i++) {
      if (s[i] != s[i - 1]) {
        flag = i;
        break;
      }
    }
    if (flag == 0)
      printf("-1 -1\n");
    else
      printf("%d %d\n", flag, flag + 1);
  }
  return 0;
}
