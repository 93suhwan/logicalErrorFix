#include <bits/stdc++.h>
using namespace std;
const int mod = 1E9 + 7;
int fpow(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}
int main() {
  long long n;
  cin >> n;
  long long qaq = 3ll * fpow(2, ((1ll << n) - 1) * 2 - 1) % mod;
  cout << qaq << endl;
  return 0;
}
