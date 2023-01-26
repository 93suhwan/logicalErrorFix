#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5, mod = 998244353;
int n, m, q;
int s1, s2, s3, s4, a[MAXN][2], b[MAXN][2], c[2];
map<int, int> mp[MAXN];
long long Fstpw(long long a, int b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = res * a % mod;
    b >>= 1;
    a = a * a % mod;
  }
  return res;
}
int main() {
  scanf("%d%d%d", &n, &m, &q);
  while (q--) {
    int op, x, y;
    scanf("%d%d%d", &x, &y, &op);
    if (a[x][0] + a[x][1]) {
      s1--;
      if (min(a[x][0], a[x][1]) == 0) s2--;
    }
    if (b[y][0] + b[y][1]) {
      s3--;
      if (min(b[y][0], b[y][1]) == 0) s4--;
    }
    if (mp[x].find(y) != mp[x].end()) {
      int t = mp[x][y];
      a[x][(y ^ t) & 1]--;
      b[y][(x ^ t) & 1]--;
      c[(x ^ y ^ t) & 1]--;
      mp[x].erase(y);
    }
    if (op >= 0) {
      int t = mp[x][y] = op;
      a[x][(y ^ t) & 1]++;
      b[y][(x ^ t) & 1]++;
      c[(x ^ y ^ t) & 1]++;
    }
    if (a[x][0] + a[x][1]) {
      s1++;
      if (min(a[x][0], a[x][1]) == 0) s2++;
    }
    if (b[y][0] + b[y][1]) {
      s3++;
      if (min(b[y][0], b[y][1]) == 0) s4++;
    }
    int ans = 0;
    if (s1 == s2) ans = Fstpw(2, n - s1);
    if (s3 == s4) ans = (ans + Fstpw(2, m - s3)) % mod;
    if (s1 == s2 && s3 == s4 && min(c[0], c[1]) == 0) {
      if (s1)
        ans--;
      else
        ans -= 2;
      ans = (ans + mod) % mod;
    }
    printf("%d\n", ans);
  }
  return 0;
}
