#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  while (n--) {
    long long a, b, c;
    cin >> a >> b >> c;
    long long minn = 0x3f3f3f3f;
    long long h = 0;
    if (c % 2 == 1) {
      h = 3;
    }
    if (h == 3 && b != 0) {
      h = 1;
    } else if (h == 0 && b % 2 != 0) {
      h = 2;
    }
    if (h == 1 && a % 2 == 1) {
      h = 0;
    } else if (h == 0) {
      if (a % 2 == 0) {
        h = 0;
      } else if (a % 2 == 1) {
        h = 1;
      }
    }
    if (h == 3) {
      if (a < 3) {
        h = 3 - a;
      } else {
        h = (a - 3) % 2;
      }
    }
    if (h == 2) {
      if (a < 2) {
        h = 2 - a;
      } else {
        h = a % 2;
      }
    }
    cout << h << endl;
  }
  return 0;
}
