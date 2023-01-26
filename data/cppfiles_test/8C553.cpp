#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, k = 0, n;
  cin >> n;
  while (n--) {
    cin >> i;
    j = i % 3;
    if (j != 0) {
      if (((i / 3) + ((i / 3) + 1) * 2) != i)
        cout << (i / 3) + 1 << " " << (i / 3) << endl;
      else
        cout << (i / 3) << " " << (i / 3) + 1 << endl;
    } else if (j == 0) {
      cout << (i / 3) << " " << (i / 3) << endl;
    }
  }
  return 0;
}
