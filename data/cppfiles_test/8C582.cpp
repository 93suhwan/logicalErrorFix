#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long c2 = 0, c1 = 0;
    if (n == 1) {
      cout << 1 << " " << 0 << endl;
      continue;
    }
    c1 = n / 3;
    c2 = n % 3;
    if (c2 == 0) {
      cout << c1 << " " << c1 << endl;
    } else if (c2 == 1) {
      cout << c1 + 1 << " " << c1 << endl;
    } else {
      cout << c1 << " " << c1 + 1 << endl;
    }
  }
}
