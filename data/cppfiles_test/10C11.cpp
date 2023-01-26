#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
long long n, m, k, r, c, ax, ay, bx, by;
long long mul(long long a, long long b) {
  a %= MOD, b %= MOD;
  return (a * b) % MOD;
}
long long expo(long long a, long long b) {
  if (b == 0) return 1;
  long long tmp = expo(a, b / 2);
  tmp = mul(tmp, tmp);
  return (b & 1 ? mul(tmp, a) : tmp);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> k >> r >> c;
  cin >> ax >> ay >> bx >> by;
  long long px = max(ax, bx), qx = min(ax + r - 1, bx + r - 1);
  long long py = max(ay, by), qy = min(ay + c - 1, by + c - 1);
  long long ir = max(0ll, qx - px + 1);
  long long ic = max(0ll, qy - py + 1);
  long long out = n * m - 2 * r * c + ir * ic;
  long long ins = r * c - ir * ic;
  if (ins == 0) ins = ir * ic;
  cout << expo(k, out + ins) << '\n';
  return 0;
}
