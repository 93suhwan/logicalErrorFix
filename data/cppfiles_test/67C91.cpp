#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t-- > 0) {
    long long int a, b, c;
    cin >> a >> b >> c;
    long long int dif = abs(a - b);
    long long int total = 2 * dif;
    if (total < c || total < a || total < b) {
      cout << -1 << endl;
      continue;
    }
    if (c + dif > total) {
      cout << abs(c - dif) << endl;
    } else {
      cout << c + dif << endl;
    }
  }
  return 0;
}
