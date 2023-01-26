#include <bits/stdc++.h>
using namespace std;
bool isPrime(long long int n) {
  if (n == 2 || n == 3) return true;
  if (n <= 1 || n % 2 == 0 || n % 3 == 0) return false;
  for (long long int i = 5; i * 1LL * i <= n; i += 6) {
    if (n % i == 0 || n % (i + 2) == 0) return false;
  }
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int tt, n;
  tt = 1;
  cin >> tt;
  while (tt--) {
    cin >> n;
    long long int a[n], s = 0;
    for (int i = 0; i < n; i++) cin >> a[i], s += a[i];
    if (isPrime(s)) {
      long long int p;
      for (int i = 0; i < n; i++) {
        if (a[i] % 2) {
          p = i;
          break;
        }
      }
      cout << n - 1 << ("\n");
      for (int i = 0; i < n; i++) {
        if (i != p) cout << i + 1 << " ";
      }
      cout << ("\n");
    } else {
      cout << n << ("\n");
      for (int i = 0; i < n; i++) cout << i + 1 << " ";
      cout << ("\n");
    }
  }
  return 0;
}
