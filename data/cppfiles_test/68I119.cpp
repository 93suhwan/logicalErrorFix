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
    long long n, x = 0, y = 0, z = 0, ans = INT_MAX, a, b, c;
    cin >> a >> b >> c;
    if (a > b) {
      swap(a, b);
    }
    x = b - a;
    if ((a >= x && b > x) || (a < x && b <= x)) {
      cout << -1 << "\n";
    } else if (c <= x) {
      cout << c + x << "\n";
    } else if (c > x && c <= x + x) {
      cout << c - x << "\n";
    } else {
      cout << -1 << "\n";
    }
  }
}
