#include <bits/stdc++.h>
using namespace std;
const long long mod = int(1e9) + 7;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  for (long long i = 1; i <= t; i++) {
    long long a, b;
    cin >> a >> b;
    if (b - a < 1) {
      cout << 0 << "\n";
    } else if (b - a == 1) {
      cout << 1 << "\n";
    } else {
      long long checkmax = b;
      long long checkmin = a;
      if (checkmax % 2 == 0) {
        cout << checkmax / 2 - 1 << "\n";
      } else {
        cout << checkmax / 2 << "\n";
      }
    }
  }
}
