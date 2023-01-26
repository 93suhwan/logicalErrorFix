#include <bits/stdc++.h>
using namespace std;
int main() {
  long t;
  cin >> t;
  while (t--) {
    long a, b, c;
    cin >> a >> b >> c;
    long sum = a + 2 * b + 3 * c;
    if (sum % 2 == 0)
      cout << 0 << endl;
    else
      cout << 1 << endl;
  }
}
