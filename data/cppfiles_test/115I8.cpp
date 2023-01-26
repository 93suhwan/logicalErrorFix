#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f, mod = 998244353;
const double pi = 3.1415926535897932, eps = 1e-6;
void chmax(int &x, int y) {
  if (x < y) x = y;
}
void chmin(int &x, int y) {
  if (x > y) x = y;
}
int qpow(int x, int y) {
  int ret = 1;
  while (y) {
    if (y & 1) ret = (long long)ret * x % mod;
    x = (long long)x * x % mod;
    y >>= 1;
  }
  return ret;
}
int n, m, k;
int ok_row[1000005][2], ok_col[1000005][2];
int r[3], c[3];
map<pair<int, int>, int> s;
void rrem(int x) {
  int num = !ok_row[x][0] + !ok_row[x][1];
  r[num]--;
}
void crem(int x) {
  int num = !ok_col[x][0] + !ok_col[x][1];
  c[num]--;
}
void radd(int x) {
  int num = !ok_row[x][0] + !ok_row[x][1];
  r[num]++;
}
void cadd(int x) {
  int num = !ok_col[x][0] + !ok_col[x][1];
  c[num]++;
}
int bw[2];
int main() {
  scanf("%d%d%d", &n, &m, &k);
  r[2] = n;
  c[2] = m;
  for (int(i) = (1); (i) <= (k); (i)++) {
    int x, y, t;
    scanf("%d%d%d", &x, &y, &t);
    if (t == -1) {
      if (s.count(make_pair(x, y))) {
        int prev = s[make_pair(x, y)];
        s.erase(make_pair(x, y));
        rrem(x);
        crem(y);
        ok_row[x][prev ^ (y & 1)]--;
        ok_col[y][prev ^ (x & 1)]--;
        radd(x);
        cadd(y);
        bw[(x & 1) ^ (y & 1) ^ prev ^ 1]--;
      }
    } else {
      if (!s.count(make_pair(x, y))) {
        s[make_pair(x, y)] = t;
        rrem(x);
        crem(y);
        ok_row[x][t ^ (y & 1)]++;
        ok_col[y][t ^ (x & 1)]++;
        radd(x);
        cadd(y);
        bw[(x & 1) ^ (y & 1) ^ t ^ 1]++;
      } else {
        int prev = s[make_pair(x, y)];
        if (prev == t) continue;
        s.erase(make_pair(x, y));
        s[make_pair(x, y)] = t;
        rrem(x);
        crem(y);
        ok_row[x][prev ^ (y & 1)]--;
        ok_col[y][prev ^ (x & 1)]--;
        bw[(x & 1) ^ (y & 1) ^ prev ^ 1]--;
        ok_row[x][t ^ (y & 1)]++;
        ok_col[y][t ^ (x & 1)]++;
        bw[(x & 1) ^ (y & 1) ^ t ^ 1]++;
        radd(x);
        cadd(y);
      }
    }
    int ans = 0;
    if (!r[0]) {
      ans += qpow(2, r[2]);
    }
    if (!c[0]) {
      ans += qpow(2, c[2]);
      if (ans >= mod) ans -= mod;
    }
    if (!bw[0]) {
      ans += 998244352;
      if (ans >= mod) ans -= mod;
    }
    if (!bw[1]) {
      ans += 998244352;
      if (ans >= mod) ans -= mod;
    }
    printf("%d\n", ans);
  }
  return 0;
}
