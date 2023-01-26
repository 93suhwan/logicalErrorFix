#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const int INF = 1e9;
const long long mod = 1e9 + 7;
long long n, m, k, r, c, a, a2, b, b2;
long long mul(long long x, long long y) {
  return ((x % mod) * (y % mod)) % mod;
}
long long pang(long long x, long long y) {
  if (y == 0) return 1;
  long long cnt = pang(x, y / 2);
  cnt = mul(cnt, cnt);
  if (y & 1) cnt = mul(cnt, x);
  return cnt;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m >> k >> r >> c;
  cin >> a >> a2 >> b >> b2;
  if (a > b) {
    swap(a, b);
  }
  if (a2 > b2) {
    swap(a2, b2);
  }
  long long gabung = 0;
  if (b <= a + r - 1 && b2 <= a2 + c - 1) {
    long long x = a + r - 1 - b + 1;
    long long y = a2 + c - 1 - b2 + 1;
    gabung = x * y;
  }
  long long tot = 2 * (r * c) - gabung;
  long long z = r * c - gabung;
  if (z == 0) z = r * c;
  long long ans = pang(k, z);
  ans = mul(ans, pang(k, n * m - tot));
  assert(ans >= 0);
  cout << ans << endl;
}
