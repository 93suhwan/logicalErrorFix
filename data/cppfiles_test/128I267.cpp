#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long MOD2 = 998244353;
long long power(long long a, long long b) {
  long long res = 1;
  a = a % MOD;
  while (b > 0) {
    if (b & 1) {
      res = (res * a) % MOD;
    }
    a = (a * a) % MOD;
    b >>= 1;
  }
  return res;
}
long long fermat_inv(long long y) { return power(y, MOD - 2); }
long long gcd(long long a, long long b) { return (b == 0) ? a : gcd(b, a % b); }
void solveQuestion() {
  long long n;
  cin >> n;
  if (n % 2 == 0) {
    long long a = (n - 1) / 2, b = a + 1, c = 1;
    cout << a << " " << b << " " << c << "\n";
  } else {
    if (n % 3 != 1) {
      cout << "3 " << n - 4 << " 1\n";
    } else {
      long long div = (n - 1) / 3;
      if (div % 4 == 0) {
        long long a = (n - 2) / 2, b = a + 2, c = 1;
        cout << a << " " << b << " " << c << "\n";
      } else {
        long long num1 = 3, num3 = 1, num2 = (n - num1 - num3);
        while (num2 % num1 == 0) {
          num2 -= 2;
          num1 += 2;
        }
        cout << num1 << " " << num2 << " " << num3 << "\n";
      }
    }
  }
}
int32_t main(int32_t argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long tt = 1;
  cin >> tt;
  while (tt-- > 0) {
    solveQuestion();
  }
  return 0;
}
