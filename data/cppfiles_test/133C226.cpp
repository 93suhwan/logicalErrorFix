#include <bits/stdc++.h>
using namespace std;
inline char nc() {
  static char buf[1000000], *p1 = buf, *p2 = buf;
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
inline void read(long long& sum) {
  char ch = nc();
  sum = 0;
  while (!(ch >= '0' && ch <= '9')) ch = nc();
  while (ch >= '0' && ch <= '9')
    sum = (sum << 3) + (sum << 1) + (ch - 48), ch = nc();
}
const long long maxn = 1e5 + 5;
const long long inf = 0x3f3f3f3f;
const long long INF = 1e18;
const double PI = acos(double(-1));
const long long mod = 1e9 + 7;
char s[105];
char temp[3];
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    for (long long i = 0; i < n; ++i) s[i] = 'a';
    s[n] = 0;
    cin >> temp;
    s[0] = temp[0], s[1] = temp[1];
    long long now = 1;
    for (long long i = 1; i <= n - 3; ++i) {
      cin >> temp;
      if (temp[0] == s[now]) {
        s[++now] = temp[1];
      } else {
        s[++now] = temp[0];
        s[++now] = temp[1];
      }
    }
    cout << s << endl;
  }
}
