#include <bits/stdc++.h>
using namespace std;
int main() {
  int testno;
  cin >> testno;
  for (int i = 1; i <= testno; i++) {
    long a;
    cin >> a;
    if (a % 3 == 0) {
      cout << a / 3 << " " << a / 3;
      cout << "\n";
    } else if (a % 3 == 1) {
      cout << a / 3 + 1 << " " << a / 3;
      cout << "\n";
    } else {
      cout << a / 3 << " " << a / 3 + 1;
      cout << "\n";
    }
  }
}
