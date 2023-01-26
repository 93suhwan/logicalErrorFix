#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    if (n == 0) {
      cout << "-1 1\n";
    } else {
      int m = n / 2;
      if (n & 1) {
        cout << m << " " << m + 1 << "\n";
      } else {
        cout << -(n - 1) << " " << n << "\n";
      }
    }
  }
  return 0;
}
