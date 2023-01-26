#include <bits/stdc++.h>
using namespace std;
long long int m = 1000000007;
bool isPrime(int n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (int i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int i, j, a[n], sum = 0;
    for (i = 0; i < n; i++) {
      cin >> a[i];
      sum += a[i];
    }
    int p, q, count = -1, f = 0;
    if (!(isPrime(sum))) {
      count = 0;
    } else {
      for (i = 0; i < n; i++) {
        if (!(isPrime(sum - a[i]))) {
          count = 1;
          p = i;
          break;
        }
      }
      if (count == -1) {
        for (i = 0; i < n - 1; i++) {
          for (j = i + 1; j < n; j++) {
            if (!(isPrime(sum - a[i] - a[j]))) {
              count = 2;
              p = i;
              q = j;
              f = 1;
              break;
            }
            if (f == 1) break;
          }
        }
      }
    }
    if (count == 0) {
      cout << n << endl;
      for (i = 0; i < n; i++) {
        cout << i + 1 << " ";
      }
      cout << endl;
    } else if (count == 1) {
      cout << n - 1 << endl;
      for (i = 0; i < n; i++) {
        if (i == p) continue;
        cout << i + 1 << " ";
      }
      cout << endl;
    } else {
      cout << n - 2 << endl;
      for (i = 0; i < n; i++) {
        if (i == p || i == q) continue;
        cout << i + 1 << " ";
      }
      cout << endl;
    }
  }
  return 0;
}
