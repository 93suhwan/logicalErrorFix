#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, i;
  cin >> t;
  for (i = 0; i < t; i++) {
    long long a, b, c;
    cin >> a >> b >> c;
    long long sum = (a) + (2 * b) + (3 * c);
    if (sum % 2 == 0) {
      cout << "0" << endl;
    } else {
      cout << "1" << endl;
    }
  }
  return 0;
}
