#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
char a[N], b[N];
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    scanf("%s%s", a + 1, b + 1);
    bool flag = false;
    int cnta = 0, cntb = 0;
    for (int i = 1; i <= n; i++) {
      if (a[i] != b[i]) {
        flag = true;
      }
      if (a[i] == '1') cnta++;
      if (b[i] == '1') cntb++;
    }
    if (!flag)
      puts("0");
    else {
      if (cnta == 0 && cntb)
        puts("-1");
      else if (cnta && cntb == 0)
        puts("-1");
      else {
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
          if (a[i] == b[i]) cnt++;
        }
        printf("%d\n", min(cnt, n - cnt));
      }
    }
  }
  return 0;
}
