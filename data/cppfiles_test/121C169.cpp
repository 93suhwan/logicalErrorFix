#include <bits/stdc++.h>
using namespace std;
const long long N = 5e5 + 5, M = 998244353, OO = 0x3f3f3f3f, HS = 31, HS2 = 47,
                M2 = 1e9 + 9;
const double PI = acos(-1);
long long tc, n;
string s, r;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ;
  tc = 1;
  cin >> tc;
  while (tc--) {
    cin >> n >> s >> r;
    long long a, b, c, d;
    a = b = c = d = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '1') {
        if (s[i] == r[i])
          a++;
        else
          b++;
      } else {
        if (s[i] == r[i])
          c++;
        else
          d++;
      }
    }
    long long op1 = OO, op2 = OO;
    if (b == d) op1 = b + d;
    if (a == c + 1) op2 = a + c;
    long long ans = min(op1, op2);
    if (ans == OO)
      cout << "-1\n";
    else
      cout << ans << "\n";
  }
  return 0;
}
