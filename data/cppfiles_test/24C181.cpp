#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    if (n < 9) {
      cout << 0;
    } else {
      if (n % 10 != 9) {
        cout << n / 10;
      } else {
        cout << (n / 10) + 1;
      }
    }
    cout << endl;
  }
  return 0;
}
