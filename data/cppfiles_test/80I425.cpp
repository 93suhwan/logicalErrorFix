#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
const int maxm = 1e5 + 10;
const int inf = 0x3f3f3f3f;
const long long llinf = 0x3f3f3f3f3f3f3f3f;
char s[maxn];
int main() {
  int _;
  scanf("%d", &_);
  while (_--) {
    int n;
    scanf("%d", &n);
    scanf("%s", s + 1);
    if (n % 2 == 1) {
      int flag = 0;
      for (int i = n / 2 + 1; i <= n; i++) {
        if (s[i] == '0') {
          printf("%d %d %d %d\n", 1, i, 1, i - 1);
          flag = 1;
          break;
        }
      }
      if (flag) continue;
      printf("%d %d %d %d\n", n / 2, n - 1, n / 2 + 1, n);
      continue;
    } else {
      int flag = 0;
      for (int i = n / 2 + 1; i <= n; i++) {
        if (s[i] == '0') {
          printf("%d %d %d %d\n", 1, i, 1, i - 1);
          flag = 1;
          break;
        }
      }
      if (flag) continue;
      if (s[n / 2] != '0') {
        printf("%d %d %d %d\n", n / 2, n - 1, n / 2 + 1, n);
        continue;
      }
      printf("%d %d %d %d\n", n / 2, n, n / 2 + 1, n);
    }
  }
  return 0;
}
