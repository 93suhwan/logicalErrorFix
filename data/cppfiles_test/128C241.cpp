#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    n = n - 1;
    if (n % 2 == 0) {
      if (n % 4 == 0) {
        cout << n / 2 - 1 << " " << n / 2 + 1 << " " << 1 << "\n";
      } else
        cout << n / 2 - 2 << " " << n / 2 + 2 << " " << 1 << "\n";
    } else
      cout << n / 2 << " " << n / 2 + 1 << " " << 1 << "\n";
  }
  return 0;
}
