#include <bits/stdc++.h>
using namespace std;
bool isPrime(int n) {
  if (n <= 1) return false;
  for (int i = 2; i * i <= n; i++)
    if (n % i == 0) return false;
  return true;
}
long long int power(long long int a, long long int b) {
  if (b == 0) return 1;
  if (b == 1) return a;
  long long int ans = power(a, b / 2);
  if (b % 2 == 0) return (ans * ans) % 1000000007;
  return ((ans * ans) % 1000000007 * a) % 1000000007;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long int n, i;
    cin >> n;
    long long int b[n], sumb = 0, mn = INT_MAX, a[n];
    for (i = 0; i < n; i++) {
      cin >> b[i];
      mn = min(b[i], mn);
      sumb += b[i];
    }
    long long int p = n * (n + 1) / 2;
    if (sumb % p != 0) {
      cout << "NO\n";
    } else {
      long long int q = sumb / p;
      if (q < n) {
        cout << "NO\n";
      } else {
        long long int f = 1;
        for (i = 0; i < n; i++) {
          long long int d = 0;
          if (i == 0) {
            d = b[0] - b[n - 1];
            long long int r = q - d;
            if (r % n != 0) {
              f = 0;
              break;
            } else {
              a[0] = r / n;
            }
          } else {
            d = b[i] - b[i - 1];
            long long int r = q - d;
            if (r % n != 0) {
              f = 0;
              break;
            } else {
              a[i] = r / n;
            }
          }
          if (a[i] < 1) {
            f = 0;
            break;
          }
        }
        if (f == 0) {
          cout << "NO\n";
        } else {
          cout << "YES\n";
          for (i = 0; i < n; i++) {
            cout << a[i] << " ";
          }
          cout << "\n";
        }
      }
    }
  }
  return 0;
}
