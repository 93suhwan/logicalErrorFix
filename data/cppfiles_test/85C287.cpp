#include <bits/stdc++.h>
using namespace std;
int T;
char a[100005];
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%s", a);
    int len = strlen(a);
    int cut1 = 0, cut2 = 0;
    for (int i = 0; i < len; ++i) {
      if (a[i] == '0') {
        cut1++;
      } else
        cut2++;
    }
    if (!cut2) {
      puts("1");
      continue;
    }
    if (!cut1) {
      puts("0");
      continue;
    }
    int qwq = 0;
    int ans = 0;
    for (int i = 0; i < len; ++i) {
      if (a[i] == '1' && qwq == 1) {
        ans++;
        qwq = 0;
      }
      if (a[i] == '0') {
        qwq = 1;
      }
    }
    if (qwq) ans++;
    ans = min(ans, 2);
    printf("%d\n", ans);
  }
  return 0;
}
