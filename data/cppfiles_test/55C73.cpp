#include <bits/stdc++.h>
using namespace std;
const long long MODULO = 1000000007ll;
int main() {
  int k;
  cin >> k;
  long long pow2 = 1ll;
  for (int i = 1; i <= k; i++) pow2 = pow2 * 2ll;
  pow2 -= 2ll;
  long long pow4 = 1ll;
  long long baza = 4ll;
  while (pow2 > 0) {
    if (pow2 % 2 == 1) {
      pow4 = (pow4 * baza) % MODULO;
    }
    baza = (baza * baza) % MODULO;
    pow2 /= 2;
  }
  cout << (6ll * pow4) % MODULO << '\n';
  return 0;
}
