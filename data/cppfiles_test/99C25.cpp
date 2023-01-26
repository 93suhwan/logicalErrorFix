#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long x, j;
    cin >> x >> j;
    long long mod = j % 4;
    long long mult = j / 4;
    j -= (mult)*4;
    if (j == 0)
      cout << x << endl;
    else {
      for (long long i = (mult * 4) + 1; i <= (mult * 4) + mod; i++) {
        if (x % 2 == 0)
          x -= i;
        else
          x += i;
      }
      cout << x << endl;
    }
  }
  return 0;
}
