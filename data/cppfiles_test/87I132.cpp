#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
char s[N], t[N];
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    scanf("%s%s", s + 1, t + 1);
    int res = 0;
    for (int i = 1; i <= n; ++i) {
      if (s[i] == '0') {
        if (t[i] == '1')
          res += 2;
        else {
          if (i + 1 <= n && (s[i + 1] == '1' && t[i + 1] == '1'))
            res += 2, ++i;
          else
            res++;
        }
      } else {
        if (t[i] == '0')
          res += 2;
        else {
          if (i + 1 <= n && (s[i + 1] == '0' || t[i + 1] == '0')) res += 2, ++i;
        }
      }
    }
    printf("%d\n", res);
  }
  return 0;
}
