#include <bits/stdc++.h>
using namespace std;
int main() {
  int test;
  cin >> test;
  while (test--) {
    long long n;
    cin >> n;
    if (n % 3 == 0) {
      long long k = n / 3;
      cout << k << k << endl;
    } else {
      for (long long i = 1; i <= n; i++) {
        if ((n + 2 * i) % 3 == 0 && (n - i) % 3 == 0) {
          cout << (n + 2 * i) / 3 << (n - i) / 3 << endl;
          ;
          break;
        }
        if ((n - 2 * i) % 3 == 0 && (n + i) % 3 == 0) {
          cout << (n - 2 * i) / 3 << (n + i) / 3 << endl;
          break;
        }
      }
    }
  }
}
