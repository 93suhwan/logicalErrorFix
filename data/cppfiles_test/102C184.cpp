#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000010;
int T, n, m;
char s[MAXN];
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d %d", &n, &m);
    scanf("%s", s + 1);
    int len = strlen(s + 1);
    int posx = 0, posy = 0;
    int l, r, u, d;
    l = r = u = d = 0;
    int ansx = 1, ansy = 1;
    for (int i = 1; i <= len; ++i) {
      if (s[i] == 'L')
        posy--;
      else if (s[i] == 'R')
        posy++;
      else if (s[i] == 'U')
        posx--;
      else if (s[i] == 'D')
        posx++;
      l = max(l, -posy);
      r = max(r, posy);
      u = max(u, -posx);
      d = max(d, posx);
      if (u + 1 + d <= n && l + 1 + r <= m) ansx = u + 1, ansy = l + 1;
    }
    printf("%d %d\n", ansx, ansy);
  }
  return 0;
}
