#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int powerLL(int x, int n) {
  int result = 1;
  while (n) {
    if (n & 1) result = result * x % MOD;
    n = n / 2;
    x = x * x % MOD;
  }
  return result;
}
bool isPrime(int n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (int i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
int main() {
  int t = 1;
  cin >> t;
  while (t--) {
    int i, j, k, s = 0, flag = 1;
    int n;
    cin >> n;
    int a[n + 1];
    for (i = 1; i <= n; i++) {
      cin >> a[i];
      s = s + a[i];
    }
    if (!isPrime(s)) {
      cout << n << endl;
      for (i = 1; i <= n; i++) {
        cout << i << " ";
      }
      cout << endl;
      continue;
    } else {
      for (i = 1; i <= n; i++) {
        if (!(isPrime(s - a[i]))) {
          cout << n - 1 << endl;
          for (j = 1; j <= n; j++) {
            if (j != i) cout << j << " ";
          }
          cout << endl;
          break;
        }
      }
    }
  }
}
