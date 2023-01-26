#include <bits/stdc++.h>
using namespace std;
int t;
int n;
char a[100002];
char b[100002];
int ans;
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d%s%s", &n, a + 1, b + 1);
    ans = 0;
    for (int i = 1; i <= n; ++i) {
      if (a[i] != b[i]) {
        ans += 2;
        continue;
      }
      if (a[i] == '1') {
        while (i <= n) {
          ++i;
          if (a[i] == '0' || b[i] == '0') {
            ans += 2;
            break;
          }
        }
      } else {
        if (i == n)
          ++ans;
        else if (a[i + 1] == '0' && b[i + 1] == '0')
          ++ans;
        else if (a[i + 1] == '1' || b[i + 1] == '1') {
          ans += 2;
          ++i;
        } else
          ++ans;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
