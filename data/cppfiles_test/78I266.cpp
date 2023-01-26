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
    if (b - a == 0) {
      cout << 0 << "\n";
    } else if (b - a == 1) {
      cout << 1 << "\n";
    } else {
      if (b % 2 == 0) {
        if ((long long)(b / 2) >= a) {
          cout << b / 2 - 1 << "\n";
        } else {
          cout << b - a << "\n";
        }
      } else {
        if ((long long)(b / 2) >= a) {
          cout << b / 2 << "\n";
        } else {
          cout << b - a << "\n";
        }
      }
    }
  }
}
