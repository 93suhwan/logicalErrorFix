#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    if (n < 6) {
      cout << 15 << endl;
    } else if (6 < n <= 8) {
      cout << 20 << endl;
    } else if (8 < n <= 10) {
      cout << 25 << endl;
    } else {
      long long sum = 0;
      sum = (n + 1) / 2 * 5;
      cout << sum << endl;
    }
  }
}
