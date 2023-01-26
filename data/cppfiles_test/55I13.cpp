#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
long long stepen(long long orig, long pok) {
  long long res = 1;
  for (int i = 0; i < pok; i++) {
    res = (res * orig) % mod;
  }
  return res;
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
    long long fours = stepen(4, ((stepen(2, k) - 2) % 125000007)) % mod;
    cout << (sixs * fours) % mod << endl;
  }
  return 0;
}
