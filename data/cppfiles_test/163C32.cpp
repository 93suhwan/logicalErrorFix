#include <bits/stdc++.h>
using namespace std;
vector<int> pos[1010];
long long modinv(long long n, long long m = 1000000007 - 2) {
  if (m == 0) return 1;
  if (m % 2) return modinv(n, m - 1) * n % 1000000007;
  long long a = modinv(n, m / 2);
  return a * a % 1000000007;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long T;
  cin >> T;
  while (T--) {
    long long a, b, c, d, e, f, g;
    cin >> a >> b >> c >> d >> e >> f >> g;
    long long i;
    long long ans = 0;
    long long prob = 1;
    long long mip = modinv(g);
    long long miip = modinv(100 - g);
    long long mih = modinv(100);
    long long rrprob = 0;
    long long dx = 1;
    long long dy = 1;
    for (i = 0; i < (2 * a - 2) * (2 * b - 2); i++) {
      long long rprob = prob * g % 1000000007 * mih % 1000000007;
      if (c != e && d != f) {
        goto T;
      }
      rrprob += rprob;
      rrprob %= 1000000007;
      ans += rprob * i;
      ans %= 1000000007;
      prob *= 100 - g;
      prob %= 1000000007;
      prob *= mih;
      prob %= 1000000007;
    T:
      if (c == a) dx = -1;
      if (c == 1) dx = 1;
      if (d == b) dy = -1;
      if (d == 1) dy = 1;
      c += dx;
      d += dy;
    }
    ans *= modinv(rrprob);
    ans %= 1000000007;
    long long rans =
        ans + ((2 * a - 2) * (2 * b - 2) *
               ((1 - rrprob + 1000000007) * modinv(rrprob) % 1000000007));
    cout << rans % 1000000007 << '\n';
  }
}
