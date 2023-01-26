#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    n -= 1;
    int a;
    int b;
    int c = 1;
    if (n % 2 == 0) {
      a = n / 2;
      b = n / 2;
      if (a % 2 == 0) {
        a--;
        b++;
      } else {
        a -= 2;
        b += 2;
      }
    } else {
      a = n / 2;
      b = n / 2 + 1;
    }
    cout << a << " " << b << " " << 1 << endl;
  }
  return 0;
}
