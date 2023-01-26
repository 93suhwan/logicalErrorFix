#include <bits/stdc++.h>
using namespace std;
int main() {
  long n;
  cin >> n;
  while (n--) {
    long k;
    cin >> k;
    long l = k, j, m = 0;
    while (k--) {
      cin >> j;
      m += j;
    }
    if (m % l == 0)
      cout << 0 << "\n";
    else
      cout << 1 << "\n";
  }
}
