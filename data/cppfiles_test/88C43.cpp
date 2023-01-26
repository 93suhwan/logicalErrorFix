#include <bits/stdc++.h>
using namespace std;
const long long nmax = 1e6 + 5;
const unsigned long long oo = 1e18;
const long long mod = 1e9 + 7;
const long long ox[4] = {-1, 1, 0, 0};
const long long oy[4] = {0, 0, -1, 1};
const long long dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
const long long dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
long long a[nmax];
int main() {
  {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
  };
  long long t, n, res;
  cin >> t;
  while (t--) {
    cin >> n;
    bool kt = false;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n - 1; i++)
      if (a[i] >= a[i + 1]) {
        kt = 1;
        break;
      }
    if (kt || !(n % 2)) {
      cout << "YES"
           << "\n";
    } else
      cout << "NO"
           << "\n";
  }
  return 0;
}
