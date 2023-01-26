#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, k = 0, n;
  cin >> n;
  while (n--) {
    cin >> i;
    if (i % 3 != 0) {
      cout << (i / 3) + 1 << " " << (i / 3) << endl;
    } else if (i % 3 == 0) {
      cout << (i / 3) << " " << (i / 3) << endl;
    }
  }
  return 0;
}
