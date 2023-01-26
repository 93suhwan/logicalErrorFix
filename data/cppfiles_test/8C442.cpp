#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int n1, n2;
    n1 = n / 3;
    n2 = 2 * n1;
    if (n1 + n2 == n) {
      cout << n1 << " " << n2 / 2 << endl;
    } else if (n1 + n2 == n - 1) {
      cout << n1 + 1 << " " << n2 / 2 << endl;
    } else {
      cout << n1 << " " << n2 / 2 + 1 << endl;
    }
  }
}
