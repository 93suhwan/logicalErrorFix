#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    if (n % 3 == 0) {
      cout << n / 3 << " " << n / 3 << endl;
    } else if ((n - 2) % 3 == 0) {
      int c1 = (n - 2) / 3;
      int c2 = c1 + 1;
      cout << c1 << " " << c2 << endl;
    } else if ((n - 1) % 3 == 0) {
      int c1 = (n + 2) / 3;
      int c2 = (n - 1) / 3;
      cout << c1 << " " << c2 << endl;
    }
  }
}
