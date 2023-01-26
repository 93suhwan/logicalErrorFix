#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long c1 = (n + 2) / 3;
    long long c2 = n / 3;
    if (n % 3 != 0) {
      if ((c1 * 2 + c2) == n) {
        cout << n / 3 << " " << (n + 2) / 3;
      } else {
        cout << (n + 2) / 3 << " " << n / 3;
      }
    } else {
      cout << n / 3 << " " << n / 3;
    }
    cout << endl;
  }
  return 0;
}
