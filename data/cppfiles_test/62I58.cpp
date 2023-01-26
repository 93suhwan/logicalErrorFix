#include <bits/stdc++.h>
using namespace std;
bool mp[1005][1005];
int main() {
  bool bu, bd, bl, br;
  int i, j, n, m, q, x, y, up, dwn, lft, rgt, dpt;
  long long ans = 0;
  scanf("%d%d%d", &n, &m, &q);
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      ans += 1ll + 4ll * min(n - i, m - j);
      if (n - i != m - j) {
        ans++;
      }
    }
  }
  while (q--) {
    bu = true, bd = true, bl = true, br = true;
    scanf("%d%d", &x, &y);
    up = 1, lft = 1, dwn = 1, rgt = 1;
    if (mp[x][y - 1] || y - 1 < 1) {
      bl = false;
    } else {
      lft++;
    }
    if (mp[x][y + 1] || y + 1 > n) {
      br = false;
    } else {
      rgt++;
    }
    for (dpt = 1; (bu || bl) && dpt < min(x, y); dpt++) {
      if (mp[x - dpt][y - dpt + 1] && bu) {
        bu = false;
      } else if (bu) {
        up++;
      }
      if (mp[x - dpt][y - dpt]) {
        if (bu) {
          bu = false;
        }
        if (bl) {
          bl = false;
        }
      } else {
        if (bu) {
          up++;
        }
        if (bl) {
          lft++;
        }
      }
      if ((mp[x - dpt][y - dpt - 1] && bl) || y - dpt - 1 < 1) {
        bl = false;
      } else if (bl) {
        lft++;
      }
    }
    if ((!mp[x - dpt][y - dpt + 1]) && bu && x - dpt >= 1) {
      up++;
    }
    for (dpt = 1; (bd || br) && dpt <= min(n - x, m - y); dpt++) {
      if (mp[x + dpt][y + dpt - 1] && bu) {
        bd = false;
      } else if (bd) {
        dwn++;
      }
      if (mp[x + dpt][y + dpt]) {
        if (bd) {
          bd = false;
        }
        if (br) {
          br = false;
        }
      } else {
        if (bd) {
          dwn++;
        }
        if (rgt) {
          rgt++;
        }
      }
      if ((mp[x + dpt][y + dpt + 1] && br) || y + dpt + 1 > n) {
        br = false;
      } else if (br) {
        rgt++;
      }
    }
    if ((!mp[x + dpt][y + dpt - 1]) && bu && x + dpt <= n) {
      dwn++;
    }
    if (mp[x][y]) {
      ans += 1ll * lft * dwn + 1ll * up * rgt - 1ll;
    } else {
      ans -= 1ll * lft * dwn + 1ll * up * rgt - 1ll;
    }
    printf("%lld\n\n", ans);
    mp[x][y] = !mp[x][y];
  }
  return 0;
}
