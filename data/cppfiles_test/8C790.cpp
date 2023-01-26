#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  int n;
  while (t--) {
    cin >> n;
    int k = n / 3;
    if (n % 3 == 0) {
      cout << k << ' ' << k << '\n';
    } else if (n % 3 == 1) {
      cout << k + 1 << ' ' << k << '\n';
    } else
      cout << k << ' ' << k + 1 << '\n';
  }
}
