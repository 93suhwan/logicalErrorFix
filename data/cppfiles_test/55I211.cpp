#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
long long stepen(long long orig, long pok) {
  if (pok == 0) {
    return 1;
  }
  long long res = stepen(orig, pok / 2);
  if (pok % 2 == 0) {
    return res * res % mod;
  } else {
    return orig * res * res % mod;
  }
}
int main() {
  int k;
  cin >> k;
  if (k == 1) {
    cout << 6 << endl;
  } else if (k == 2) {
    cout << 6 * 4 * 4 << endl;
  } else {
    long long sixs = 6;
    long long fours = stepen(4, ((stepen(2, k) - 2) % mod)) % mod;
    cout << (sixs * fours) % mod << endl;
  }
  return 0;
}
