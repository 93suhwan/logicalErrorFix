#include <bits/stdc++.h>
using namespace std;
void io() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
signed main() {
  io();
  long long t = 1;
  cin >> t;
  while (t--) {
    long long a, b, c;
    cin >> a >> b >> c;
    long long n;
    n = 2 * (abs(a - b) - 1) + 2;
    if (n < max(a, b) || n < c) {
      cout << -1 << endl;
    } else {
      long long temp1 = c + abs(a - b);
      long long temp2 = c - abs(a - b);
      if (temp1 <= n) {
        cout << temp1 << endl;
      } else if (temp2 > 0) {
        cout << temp2 << endl;
      }
    }
  }
  return 0;
}
