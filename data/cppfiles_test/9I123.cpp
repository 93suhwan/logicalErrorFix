#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    if (n % 3 == 2) {
      cout << n / 3 << ' ' << (n / 3) + 1 << '\n';
      continue;
    }
    int x = n / 3;
    int z = x * 2;
    cout << (n - z) << ' ' << x << '\n';
  }
  return 0;
}
