#include <bits/stdc++.h>
using namespace std;
int t, a, b;
int main() {
  cin >> t;
  while (t--) {
    cin >> a >> b;
    if (a <= b / 2)
      cout << b - b / 2 - 1 << endl;
    else
      cout << b % a << endl;
  }
  return 0;
}
