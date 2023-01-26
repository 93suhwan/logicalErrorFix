#include <bits/stdc++.h>
int t;
using namespace std;
int main() {
  cin >> t;
  while (t--) {
    int a, b, i, j, k;
    cin >> a >> b;
    int s[200002];
    if (a == b) {
      cout << (a + b) / 2 + 1 << endl;
      for (i = 0; i <= a + b; i += 2) cout << i << "  ";
      cout << endl;
      continue;
    } else if (a % 2 != 0 && b % 2 == 0 || b % 2 != 0 && a % 2 == 0) {
      k = 2 + min(a, b) * 2;
      cout << k << endl;
      for (j = abs(a - b) / 2, i = 1; i <= k; i++, j++) cout << j << "  ";
      cout << endl;
      continue;
    } else if (a % 2 == 0 && b % 2 == 0) {
      k = 1 + min(a, b);
      cout << k << endl;
      for (i = 1, j = abs(a - b) / 2; i <= k; i++, j += 2) cout << j << "  ";
      cout << endl;
      continue;
    } else {
      k = 1 + min(a, b);
      cout << k << endl;
      for (i = 1, j = abs(a - b) / 2; i <= k; i++, j += 2) cout << j << "  ";
      cout << endl;
      continue;
    }
  }
}
