#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int a, b, c;
    cin >> a >> b >> c;
    long long int sum = a + 2 * b + 3 * c;
    if (sum % 2 == 0)
      cout << 0 << endl;
    else
      cout << 1 << endl;
  }
}
