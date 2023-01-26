#include <bits/stdc++.h>
using namespace std;
int last_digit(int x) {
  int last_digit;
  last_digit = x % 10;
  return last_digit;
}
int main() {
  int t, x;
  cin >> t;
  while (t--) {
    cin >> x;
    if (x % 3 != 0 && last_digit(x) != 3) {
      cout << x << endl;
    }
  }
  return 0;
}
