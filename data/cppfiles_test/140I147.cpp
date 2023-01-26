#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    int a, b;
    a = sqrt(n);
    b = cbrt(n);
    int x, c;
    if (b > 4) {
      c = sqrt(b);
      x = c - 1;
    } else if (b == 4) {
      x = 1;
    }
    cout << a + b - x - 1 << endl;
  }
}
