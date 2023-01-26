#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1e5 + 5;
int main() {
  int t, ans, i, j, n, temp;
  char p;
  string s;
  scanf("%d", &t);
  while (t--) {
    cin >> n;
    cin >> p;
    cin >> s;
    ans = 0;
    for (i = 1; i <= n; i++) {
      temp = 0;
      for (j = i; j <= n; j += i) {
        if (s[j - 1] != p) {
          temp = 1;
          break;
        }
      }
      if (temp == 0) {
        ans = i;
        break;
      }
    }
    if (ans == 1)
      printf("0\n");
    else if (ans == 0)
      printf("2\n%d %d\n", n, n - 1);
    else
      printf("1\n%d\n", ans);
  }
  return 0;
}
