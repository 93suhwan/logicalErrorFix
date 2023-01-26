#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    if (n % 10 == 0) {
      cout << (n / 10) * 25 << endl;
    } else if (n % 8 == 0) {
      cout << (n / 8) * 20 << endl;
    } else if (n % 6 == 0) {
      cout << (n / 6) * 15 << endl;
    } else if (n % 10 > 8) {
      cout << (n / 10) * 25 + 25 << endl;
    } else if (n % 10 > 6) {
      cout << (n / 10) * 25 + 20 << endl;
    } else {
      cout << (n / 10) * 25 + 15 << endl;
    }
  }
  return 0;
}
