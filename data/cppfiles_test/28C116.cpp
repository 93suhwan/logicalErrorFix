#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t, n, i;
  cin >> t;
  while (t--) {
    long long a, b, c;
    cin >> a >> b >> c;
    if ((a * 1 + b * 2 + c * 3) % 2 == 0) {
      cout << 0 << endl;
    } else {
      cout << 1 << endl;
    }
  }
}
