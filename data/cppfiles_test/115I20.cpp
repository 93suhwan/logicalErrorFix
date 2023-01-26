#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long s = 0, w = 1, ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    s = (s << 3) + (s << 1) + ch - 48;
    ch = getchar();
  }
  return s * w;
}
const long long maxn = 1e6 + 50, inv2 = 499122177, mod = 998244353;
long long n, m, Q;
long long ans1, ans2, z1, z2, z3, z4;
map<pair<long long, long long>, long long> mp;
long long c1[maxn][2], c2[maxn][2];
inline long long ksm(long long a, long long p) {
  long long res = 1;
  while (p) {
    if (p & 1) res = res * a % mod;
    p >>= 1;
    a = a * a % mod;
  }
  return res;
}
void modify(long long x, long long y, long long op) {
  long long tx, ty;
  tx = x, ty = y;
  if (x % 2 == op)
    c1[ty][1]++;
  else
    c1[ty][0]++;
  if (c1[ty][0] && c1[ty][1] && (c1[ty][(x % 2) ^ op ^ 1] == 1)) z1++, ans1--;
  if (c1[ty][0] + c1[ty][1] == 1) ans1++;
  tx = x, ty = y;
  if (y % 2 == op)
    c2[tx][1]++;
  else
    c2[tx][0]++;
  if (c2[tx][0] && c2[tx][1] && (c2[tx][(y % 2) ^ op ^ 1] == 1)) z2++, ans2--;
  if (c2[tx][0] + c2[tx][1] == 1) ans2++;
  if ((x + y) % 2 != op)
    z3++;
  else
    z4++;
}
void erase(long long x, long long y) {
  long long tx, ty, op = mp[make_pair(x, y)];
  tx = x, ty = y;
  if (x % 2 == op)
    c1[ty][1]--;
  else
    c1[ty][0]--;
  if (c1[ty][0] + c1[ty][1] == 0)
    ans1--;
  else if ((c1[ty][0] == 0 || c1[ty][1] == 0) &&
           (c1[ty][(x % 2) ^ op ^ 1] == 0))
    z1--, ans1++;
  tx = x, ty = y;
  if (y % 2 == op)
    c2[tx][1]--;
  else
    c2[tx][0]--;
  if (c2[tx][0] + c2[tx][1] == 0)
    ans2--;
  else if ((c2[tx][0] == 0 || c2[tx][1] == 0) &&
           (c2[tx][(y % 2) ^ op ^ 1] == 0))
    z2--, ans2++;
  if ((x + y) % 2 != op)
    z3--;
  else
    z4--;
}
signed main() {
  n = read();
  m = read();
  Q = read();
  while (Q--) {
    long long x = read(), y = read(), op = read(), tx, ty;
    if (op != -1) {
      if (mp.find(make_pair(x, y)) != mp.end()) erase(x, y);
      modify(x, y, op);
      mp[make_pair(x, y)] = op;
    } else {
      if (mp.find(make_pair(x, y)) != mp.end())
        erase(x, y), mp.erase(make_pair(x, y));
    }
    long long ans = 0;
    if (z1 == 0) ans += ksm(2, m - ans1);
    if (z2 == 0) ans += ksm(2, n - ans2);
    if (z1 == 0 && z2 == 0) {
      if (z3 == 0) ans--;
      if (z4 == 0) ans--;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
