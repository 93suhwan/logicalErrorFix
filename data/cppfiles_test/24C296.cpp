#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  long long int a, d, c, b;
  for (int i = 0; i < n; i++) {
    cin >> a;
    c = a % 10;
    if (c == 9 || a == 9) {
      b = (a / 10) + 1;
      cout << b << endl;
    } else {
      d = a / 10;
      cout << d << endl;
    }
  }
  return 0;
}
