#include <bits/stdc++.h>
const long long mod = 1e9 + 7;
const long long maxn = 5e5 + 7;
const double pi = acos(-1);
using namespace std;
int _, n, m;
long long ling, yi;
long long ans;
int main() {
  for (cin >> _; _; _--) {
    ling = yi = 0;
    ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> m;
      if (m == 0) {
        ling++;
      } else if (m == 1) {
        yi++;
      }
    }
    ans = yi;
    for (int i = 1; i <= ling; i++) {
      ans *= 2;
    }
    cout << ans << endl;
  }
  return 0;
}
