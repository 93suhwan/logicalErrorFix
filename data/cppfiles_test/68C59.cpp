#include <bits/stdc++.h>
using namespace std;
const long long N = 1e7 + 7;
string alp = "abcdefghijklmnopqrstuvwxyz";
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long test = 1;
  cin >> test;
  while (test--) {
    long long n, x = 0, y = 0, z = 0;
    cin >> n;
    while (x <= n) {
      x = z * z + 1;
      z++;
    }
    z -= 2;
    y = z * z + 1;
    if (n <= y + z) {
      cout << n - y + 1 << " " << z + 1 << "\n";
    } else {
      y += z;
      cout << z + 1 << " " << z - (n - y) + 1 << "\n";
    }
  }
}
