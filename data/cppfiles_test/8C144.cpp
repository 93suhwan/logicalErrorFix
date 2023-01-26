#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  while (n--) {
    int money, b1 = 0, b2 = 0;
    cin >> money;
    b1 = b2 = money / 3;
    b1 += (money % 3 == 1) ? 1 : 0;
    b2 += (money % 3 == 2) ? 1 : 0;
    cout << b1 << ' ' << b2 << endl;
  }
  return 0;
}
