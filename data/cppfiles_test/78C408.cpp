#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b, i, j, n, t;
  cin >> t;
  while (t--) {
    cin >> a >> b;
    n = b / 2;
    if (n >= a) {
      cout << b % (n + 1) << endl;
    } else {
      cout << b % a << endl;
    }
  }
}
