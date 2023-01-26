#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
char str[maxn];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d%d", &n, &m);
    int w = 0, s = 0;
    int a = 0, d = 0;
    int nowx = 0, nowy = 0;
    scanf("%s", str + 1);
    int h = strlen(str + 1);
    int a1 = 1, a2 = 1;
    for (int i = 1; i <= h; i++) {
      if (str[i] == 'R') {
        nowx++;
      }
      if (str[i] == 'L') {
        nowx--;
      }
      if (str[i] == 'U') {
        nowy++;
      }
      if (str[i] == 'D') {
        nowy--;
      }
      d = max(d, nowx);
      a = max(a, -nowx);
      w = max(w, nowy);
      s = max(s, -nowy);
      if (w + s < n && a + d < m) {
        a1 = w + 1;
        a2 = a + 1;
      }
    }
    printf("%d %d\n", a1, a2);
  }
}
