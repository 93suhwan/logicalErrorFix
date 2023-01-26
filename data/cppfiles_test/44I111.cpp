#include <bits/stdc++.h>
using namespace std;
const double pi = 3.14159265358979323846;
const int MOD = 1e9 + 7;
long long mod_pow(long long a, long long n, long long mod) {
  long long res = 1;
  while (n) {
    if (n & 1) res = (res * a) % mod;
    n /= 2;
    a = (a * a) % mod;
  }
  return res;
}
int gcd(int a, int b) {
  if (!a) return b;
  return gcd(b % a, a);
}
bool primenumber(int number) {
  for (int i(2); i <= sqrt(number); ++i) {
    if (number % i == 0) return false;
  }
  return true;
}
int main() {
  long long t;
  cin >> t;
  while (t != 0) {
    int a, b;
    cin >> a >> b;
    int sum = a + b;
    if (a == b) {
      cout << "1" << endl;
    } else if (a == 0 && b == 0) {
      cout << "0" << endl;
    } else if (sum % 2 == 0) {
      cout << "2" << endl;
    } else {
      cout << "-1" << endl;
    }
    t--;
  }
  return 0;
}
