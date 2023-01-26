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
    int maxx = 0, minx = 0;
    int maxy = 0, miny = 0;
    int nowx = 0, nowy = 0;
    scanf("%s", str + 1);
    int h = strlen(str + 1);
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
      maxx = max(maxx, nowx);
      minx = min(minx, nowx);
      maxy = max(maxy, nowy);
      miny = min(miny, nowy);
    }
    cout << maxx << " " << minx << " " << maxy << " " << miny << endl;
    int tt = 0;
    int ansy = 1;
    for (int i = 1; i <= n; i++) {
      int temp = min(i - 1, maxy) + min(n - i, -miny);
      if (temp > tt) {
        tt = temp;
        ansy = i;
      }
    }
    tt = 0;
    int ansx = 1;
    for (int i = 1; i <= m; i++) {
      int temp = min(i - 1, -minx) + min(m - i, maxx);
      if (temp > tt) {
        tt = temp;
        ansx = i;
      }
    }
    printf("%d %d\n", ansy, ansx);
  }
}
