#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    if ((a + b * 2 - c * 3) % 2 == 0) {
      cout << 0 << endl;
    } else {
      cout << 1 << endl;
    }
  }
}
