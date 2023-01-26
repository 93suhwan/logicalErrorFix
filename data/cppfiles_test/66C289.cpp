#include <bits/stdc++.h>
using namespace std;
inline namespace FastIO {
const long long BSZ = 1 << 15;
char ibuf[BSZ];
long long ipos, ilen;
char nc() {
  if (ipos == ilen) {
    ipos = 0;
    ilen = fread(ibuf, 1, BSZ, stdin);
    if (!ilen) return EOF;
  }
  return ibuf[ipos++];
}
template <class T>
void init(T& x) {
  char ch;
  long long sgn = 1;
  while (!isdigit(ch = nc()))
    if (ch == '-') sgn *= -1;
  x = ch - '0';
  while (isdigit(ch = nc())) x = x * 10 + (ch - '0');
  x *= sgn;
}
}  // namespace FastIO
using namespace FastIO;
signed main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long ans = 1;
    n--;
    while (n > 0) {
      if (ans % 3 == 0 || ans % 10 == 3)
        ans++;
      else {
        ans++;
        n--;
      }
    }
    if (ans % 3 == 0 || ans % 10 == 3) {
      while (true) {
        ans++;
        if (ans % 3 != 0 && ans % 10 != 3) break;
      }
    }
    cout << ans << endl;
  }
  return 'm' - 109;
}
