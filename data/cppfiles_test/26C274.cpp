#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
lli mod = 1000000007.0;
int main(void) {
  long long t;
  cin >> t;
  lli x;
  lli n;
  while (t--) {
    cin >> n;
    x = 1;
    for (lli i = 2 * n; i >= 3; i--) {
      x *= i;
      x = x % mod;
    }
    cout << x << endl;
  }
  return 0;
}
