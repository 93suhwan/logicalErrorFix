#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long x = sqrt(1 + 8 * n);
    if (x * x == (1 + 8 * n)) {
      cout << "1"
           << " " << (x - 1) / 2 << endl;
    } else {
      long long y = n;
      y--;
      string s = to_string(y);
      cout << "-" + s << " " << n << endl;
    }
  }
}
