#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int a, b, c;
    cin >> a >> b >> c;
    long long int sum = a + b + c;
    if (sum % 2 == 0) {
      cout << "1" << endl;
    } else {
      cout << "0" << endl;
    }
  }
  return 0;
}
