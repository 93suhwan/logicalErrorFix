#include <bits/stdc++.h>
using namespace std;
const long long INFF = 1e18 + 5;
const long long INF = 1e10 + 5;
const long long MX = 1e6 + 5;
const long long MXL = 105;
const long long mod = 1e9 + 7;
const double ERROR = 1e-8;
const long double pi = 3.14159265358979323846;
const long long set_inf = 0x3f3f3f3f;
long long a, b, c;
string s;
void solve() {
  cin >> s;
  a = 0, b = 0, c = 0;
  for (auto i : s) {
    if (i == 'A') a++;
    if (i == 'B') b++;
    if (i == 'C') c++;
  }
  if (b == a + c)
    cout << "YES\n";
  else
    cout << "NO\n";
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long tc;
  cin >> tc;
  while (tc--) solve();
  exit(0);
  ;
}
