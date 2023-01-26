#include <bits/stdc++.h>
using namespace std;
long long power(long long, long long);
void solution() {
  long long n, m, k;
  cin >> n >> m >> k;
  if (n % 2 == 0 && m % 2 == 0) {
    if (k % 2 == 0) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
    return;
  } else {
    long long temp = n * (m / 2);
    if (k > temp) {
      cout << "NO\n";
      return;
    }
    if (n % 2 == 0) {
      if (k % 2 == 0)
        cout << "YES\n";
      else
        cout << "NO\n";
    } else {
      if (k % 2 == 1)
        cout << "YES\n";
      else {
        if (k % temp == 0) {
          long long left = n - k / temp;
          if (left % 2 == 0)
            cout << "YES\n";
          else
            cout << "NO\n";
        } else
          cout << "NO\n";
      }
    }
    return;
  }
}
int main() {
  int t = 1;
  cin >> t;
  while (t--) {
    solution();
  }
  return 0;
}
long long power(long long x, long long y) {
  long long p = 1e9 + 7;
  long long res = 1;
  x = x % p;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
