#include <bits/stdc++.h>
using namespace std;
const long long N = 200000 + 7;
const long long mod = 1e9 + 7;
const long double pi = 3.14159265359;
int dx[] = {0, -1, 0, 1, -1, 1, -1, 1};
int dy[] = {-1, 0, 1, 0, 1, -1, -1, 1};
long long n, k, t, x, y, z, m, p, l, r;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  t = 1;
  cin >> t;
  while (t--) {
    long long c, d;
    cin >> c >> d;
    if (!c && !d) {
      cout << 0 << endl;
    } else if (c == d) {
      cout << 1 << endl;
    } else if (abs(c - d) % 2) {
      cout << -1 << endl;
    } else {
      cout << 2 << endl;
    }
  }
}
