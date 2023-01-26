#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n, k = 3, c1, c2, d;
    cin >> n;
    if (n % 3 == 0) {
      c1 = n / 3;
      c2 = n / 3;
    } else if (n % 3 == 1) {
      c2 = (n - 1) / 3;
      c1 = c2 + 1;
    } else {
      c1 = (n - 2) / 3;
      c2 = c1 + 1;
    }
    cout << c1 << " " << c2 << endl;
  }
  return 0;
}
