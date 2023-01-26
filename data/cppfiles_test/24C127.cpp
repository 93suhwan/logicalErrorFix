#include <bits/stdc++.h>
using namespace std;
void print_ans(bool f) {
  if (f) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
long long int modular_pow(long long int base, long long int exponent,
                          long long int modulus) {
  long long int result = 1;
  while (exponent > 0) {
    if (exponent % 2 == 1) result = (result * base) % modulus;
    exponent = exponent >> 1;
    base = (base * base) % modulus;
  }
  return result;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    if (n % (10) == 9) {
      cout << n / 10 + 1 << endl;
    } else {
      cout << n / 10 << endl;
    }
  }
}
