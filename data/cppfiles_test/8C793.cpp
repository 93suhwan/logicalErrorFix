#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;
    int c1 = n / 3;
    int c2 = n / 3;
    if (c1 + 2 * c2 == n) {
      cout << c1 << " " << c2 << endl;
    } else if ((c1 + 1) + 2 * c2 == n) {
      cout << c1 + 1 << " " << c2 << endl;
    }
    if (c1 + 2 * (c2 + 1) == n) {
      cout << c1 << " " << c2 + 1 << endl;
    }
  }
}
