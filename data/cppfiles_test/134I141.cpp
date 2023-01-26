#include <bits/stdc++.h>
using namespace std;
const int N = 100 + 10, M = 1e5 + 10;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
long long arr[N];
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
int main() {
  long long tt;
  cin >> tt;
  while (tt--) {
    long long n;
    cin >> n;
    for (long long i = 1; i <= n; i++) cin >> arr[i];
    long long num1 = arr[1], num2 = arr[2];
    for (long long i = 1; i <= n; i += 2) {
      num1 = gcd(num1, arr[i]);
    }
    for (long long i = 2; i <= n; i += 2) {
      num2 = gcd(num2, arr[i]);
    }
    if (num1 == num2)
      cout << 0 << "\n";
    else {
      bool f = 1;
      if (num1 > num2) {
        for (long long i = 2; i <= n; i += 2) {
          if (arr[i] % num1 == 0) {
            f = 0;
            break;
          }
        }
      } else {
        for (long long i = 1; i <= n; i += 2) {
          if (arr[i] % num2 == 0) {
            f = 0;
            break;
          }
        }
      }
      if (f) {
        if (num1 > num2)
          cout << num1 << "\n";
        else
          cout << num2 << "\n";
      } else
        cout << "0\n";
    }
  }
  return 0;
}
