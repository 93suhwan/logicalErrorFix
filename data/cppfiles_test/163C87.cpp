#include <bits/stdc++.h>
const double pi = acos(-1);
long long binpow(long long a, long long b, long long md) {
  long long res = 1;
  a %= 1000000007;
  while (b != 0) {
    if (b & 1) res *= a, res %= md;
    a *= a, a %= md;
    b >>= 1;
  }
  return res % md;
}
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int z = 1;
  cin >> z;
  for (int i = 1; i < z + 1; i++) {
    long long n, m, rb, cb, rd, cd, p;
    cin >> n >> m >> rb >> cb >> rd >> cd >> p;
    long long ans = 0, dr = 1, dc = 1, steps = 0, r = rb, c = cb, num = 100 - p,
              den = 100, prod = 1;
    num *= binpow(den, 1000000007 - 2, 1000000007), num %= 1000000007;
    long long np = p, dp = binpow(100LL, 1000000007 - 2, 1000000007), ndr, ndc;
    map<int, map<int, map<int, map<int, bool>>>> vis;
    np *= dp, np %= 1000000007;
    if (rb == rd || cb == cd) prod = num;
    do {
      vis[rb][cb][dr][dc] = 1;
      if (rb + dr > n || rb + dr < 1) dr *= (-1);
      if (cb + dc > m || cb + dc < 1) dc *= (-1);
      if (r == 1 && c == m) ndr = -1, ndc = 1;
      if (r == rb && c == cb && dr == 1 && dc == 1 && steps > 0) break;
      rb += dr, cb += dc, steps++;
      if (r == rb && c == cb && vis[rb][cb][dr][dc] && steps > 0) break;
      if (rb + dr > n || rb + dr < 1) dr *= (-1);
      if (cb + dc > m || cb + dc < 1) dc *= (-1);
      if (r == rb && c == cb && vis[rb][cb][dr][dc] && steps > 0) break;
      if (rb == rd || cb == cd)
        ans += (((steps * prod) % 1000000007 * np) % 1000000007),
            ans %= 1000000007, prod *= num, prod %= 1000000007;
    } while (1);
    long long tempd = (1 - prod + 1000000007) % 1000000007, tot = 0;
    tempd = binpow(tempd, 1000000007 - 2, 1000000007);
    long long fnum = (ans + ((steps * prod) % 1000000007)) % 1000000007;
    fnum *= tempd, fnum %= 1000000007;
    cout << fnum << "\n";
  }
}
