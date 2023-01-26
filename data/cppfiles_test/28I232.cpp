#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int a, b, c;
    cin >> a >> b >> c;
    long long int sum = (a * 1) + (b * 2);
    if (sum % 2 != 0) {
      sum = sum - (c * 3);
      if (sum < 0) {
        cout << 1 << endl;
      } else {
        cout << sum << endl;
      }
    } else {
      sum += 3;
      sum = sum - ((c - 1) * 3);
      if (sum < 0) {
        cout << 1 << endl;
      } else {
        cout << sum << endl;
      }
    }
  }
  return 0;
}
