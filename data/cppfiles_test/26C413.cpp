#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1000000007;
long long int power(long long int a, long long int n, long long int p) {
  long long int res = 1;
  while (n) {
    if (n % 2 == 1)
      res = (res * a) % p, n--;
    else
      a = (a * a) % p, n /= 2;
  }
  return res;
}
int main() {
  long long int ar[200001];
  ar[0] = 1;
  for (long long int i = 1; i <= 200000; i++)
    ar[i] = ((ar[i - 1] % mod) * (i % mod)) % mod;
  long long int tc;
  cin >> tc;
  while (tc--) {
    long long int n;
    cin >> n;
    n *= 2;
    long long int x = ar[n];
    long long int p = power(2, mod - 2, mod);
    p = ((p % mod) * (x % mod)) % mod;
    cout << p << endl;
  }
}
