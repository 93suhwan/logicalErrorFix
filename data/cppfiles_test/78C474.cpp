#include <bits/stdc++.h>
using namespace std;
int a, b;
int main() {
  int T;
  cin >> T;
  while (T--) {
    cin >> a >> b;
    if (b / 2 >= a) {
      if (b % 2 == 0)
        cout << b / 2 - 1 << endl;
      else
        cout << b / 2 << endl;
    } else
      cout << b % a << endl;
  }
  return 0;
}
