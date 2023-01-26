#include <bits/stdc++.h>
using namespace std;
int main() {
  int test, n, dx, yx;
  cin >> test;
  for (int i = 0; i < test; i++) {
    cin >> n;
    if (n % 3 == 1) {
      dx = n / 3;
      cout << dx + 1 << " " << dx << endl;
    }
    if (n % 3 == 2) {
      dx = n / 3;
      cout << dx << " " << dx + 1 << endl;
    }
    if (n % 3 == 0) {
      dx = n / 3;
      cout << dx << " " << dx << endl;
    }
  }
}
