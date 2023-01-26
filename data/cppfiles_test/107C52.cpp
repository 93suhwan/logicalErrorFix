#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, a, b, n, i;
  cin >> t;
  while (t--) {
    cin >> n >> a >> b;
    if (a - b > 1 || a - b < -1 || n - 2 < a + b) {
      cout << "-1" << endl;
      continue;
    }
    if (a == 0 && b == 0) {
      cout << "1";
      for (int j = 2; j <= n; j++) cout << " " << j;
      cout << endl;
      continue;
    }
    if (a == b) {
      i = 0;
      cout << a + 1;
      while (i < a) {
        i++;
        cout << " " << i;
        if (i == 1)
          for (int j = a + b + 2; j <= n; j++) cout << " " << j;
        else
          cout << " " << a + b - i + 3;
      }
      cout << " " << a + 2 << endl;
    } else if (a > b) {
      i = 0;
      cout << a + 1;
      while (i < a) {
        i++;
        if (i == 1)
          for (int j = a + b + 2; j <= n; j++) cout << " " << j;
        else
          cout << " " << a + b - i + 3;
        cout << " " << i;
      }
      cout << endl;
    } else {
      i = 0;
      cout << b + 1;
      while (i < b) {
        i++;
        cout << " " << i;
        if (i == 1)
          for (int j = a + b + 2; j <= n; j++) cout << " " << j;
        else
          cout << " " << a + b - i + 3;
      }
      cout << endl;
    }
  }
}
