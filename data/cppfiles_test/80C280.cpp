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
    int flag = 0;
    for (int i = n; i >= 1; i--) {
      if (s[i] == '0') {
        flag = i;
        break;
      }
    }
    if (!flag) {
      printf("%d %d %d %d\n", 1, n - 1, 2, n);
    } else {
      if (flag > n / 2) {
        printf("%d %d %d %d\n", 1, flag, 1, flag - 1);
      } else {
        printf("%d %d %d %d\n", flag, n, flag + 1, n);
      }
    }
  }
  return 0;
}
