#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
char a[N], b[N];
int num[4];
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    num[0] = num[1] = num[2] = num[3] = 0;
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
        for (int i = 1; i <= n; i++) {
          if (a[i] == '1' && b[i] == '0')
            num[0]++;
          else if (a[i] == '1' && b[i] == '1')
            num[1]++;
          else if (a[i] == '0' && b[i] == '1')
            num[2]++;
          else
            num[3]++;
        }
        int ans = -1;
        if (num[3] + 1 == num[1]) ans = num[3] + num[1];
        if (num[0] == num[2]) {
          if (ans == -1)
            ans = num[0] + num[2];
          else if (ans > num[0] + num[2])
            ans = num[0] + num[2];
        }
        printf("%d\n", ans);
      }
    }
  }
  return 0;
}
