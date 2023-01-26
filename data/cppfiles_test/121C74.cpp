#include <bits/stdc++.h>
using namespace std;
int t, n;
char a[100010], b[100010];
int main() {
  cin >> t;
  while (t--) {
    scanf("%d", &n);
    scanf("%s%s", a + 1, b + 1);
    int cnta = 0, cntb = 0;
    for (int i = 1; i <= n; i++) {
      cnta += (a[i] == '1');
      cntb += (b[i] == '1');
    }
    int ans = 1e9;
    if (cnta == cntb || cnta + cntb == n + 1) {
      if (cnta == cntb) {
        int tmp = 0;
        for (int i = 1; i <= n; i++) {
          tmp += (a[i] != b[i]);
        }
        ans = min(ans, tmp);
      }
      if (cnta + cntb == n + 1) {
        int tmp = 0;
        for (int i = 1; i <= n; i++) {
          tmp += (a[i] == b[i]);
        }
        ans = min(ans, tmp);
      }
      printf("%d\n", ans);
    } else {
      puts("-1");
    }
  }
  return 0;
}
