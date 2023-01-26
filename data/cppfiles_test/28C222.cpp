#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int a, b, c;
    cin >> a >> b >> c;
    long long int sum = (a * 1) + (b * 2) + (c * 3);
    long long int stored = sum;
    if (a == b) {
      if (b == c) {
        cout << 0 << endl;
        continue;
      }
    }
    sum /= 2;
    cout << abs((stored - sum) - sum) << endl;
  }
  return 0;
}
