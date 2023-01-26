#include <bits/stdc++.h>
using namespace std;
const long long maxn = 2e5 + 7;
const long long inf = 0x3f3f3f3f;
const long long mod = 100000007;
signed main() {
  ios ::sync_with_stdio(0);
  cin.tie(0);
  long long Tcodeforces, Tcodeforce;
  cin >> Tcodeforces;
  for (Tcodeforce = 1; Tcodeforce <= Tcodeforces; Tcodeforce++) {
    long long a, b;
    cin >> a >> b;
    if (a <= b / 2) {
      if (b % 2 == 0) {
        long long r = b - 1;
        cout << r % (b / 2) << endl;
      } else {
        long long md = (b + 1) / 2;
        cout << b % md << endl;
      }
    } else
      cout << b % a << endl;
  }
  return (0);
}
