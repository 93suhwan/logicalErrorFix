#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int a, b;
    if (n % 3 == 0) {
      a = b = n / 3;
      cout << a << " " << b << endl;
    } else if ((n - 1) % 3 == 0) {
      b = (n - 1) / 3;
      a = b + 1;
      cout << a << " " << b << endl;
    } else {
      if ((n - 2) % 3 == 0) {
        a = (n - 3) / 3;
        b = a + 1;
        cout << a << " " << b << endl;
      }
    }
  }
}
