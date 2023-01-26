#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10, M = 1e5 + 10;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
long long arr[N];
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    long long num1 = 1, num2 = 1;
    for (int i = 1; i <= n; i += 2) {
      if (i == 1)
        num1 = arr[i];
      else
        num1 = gcd(num1, arr[i]);
    }
    for (int i = 2; i <= n; i += 2) {
      if (i == 2)
        num2 = arr[i];
      else
        num2 = gcd(num2, arr[i]);
    }
    if (num1 == num2)
      cout << 0 << "\n";
    else {
      int f = 1;
      if (num1 > num2) {
        for (int i = 2; i <= n; i += 2) {
          if (arr[i] % num1 == 0) {
            f = 0;
            break;
          }
        }
      } else {
        for (int i = 1; i <= n; i += 2) {
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
