#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
int main() {
  long long n, i, k, prod = 4, suma = 6;
  cin >> n;
  for (i = 2; i <= n; i++) {
    prod = (prod * prod) % mod;
    suma = (suma * prod) % mod;
  }
  cout << suma % mod;
  return 0;
}
