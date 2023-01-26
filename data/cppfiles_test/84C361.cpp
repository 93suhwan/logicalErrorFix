#include <bits/stdc++.h>
using namespace std;
long long int binpow(long long int a, long long int b, long long int mod) {
  long long int res = 1;
  while (b != 0) {
    if (b % 2) {
      res = (res * a) % mod;
    }
    a = (a * a) % mod;
    b = b / 2;
  }
  return res;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int n, s;
    cin >> n >> s;
    if (n == 1)
      cout << s << endl;
    else {
      long long int va = n / 2;
      if (n % 2 == 0) va -= 1;
      long long int k = (s) / (n - (va));
      cout << k << endl;
    }
  }
}
