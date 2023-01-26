#include <bits/stdc++.h>
using namespace std;
long long power(long long a, long long b) {
  long long m = 1e9 + 7;
  long long x = 1;
  while (b != 0) {
    if (b % 2 == 1) {
      x = (x % m * a % m) % m;
    }
    a = (a % m * a % m) % m;
    b /= 2;
  }
  return x;
}
void sol() {
  long long n, k;
  cin >> n >> k;
  long long ans = 0;
  long long m = 1e9 + 7;
  long long x = 1, a = n;
  int ct = 0;
  while (k != 0) {
    if (k % 2 == 1) {
      ans = ans % m + power(n, ct) % m;
      x = (x % m * a % m) % m;
      ans = ans % m;
    }
    ct++;
    a = (a % m * a % m) % m;
    k /= 2;
  }
  cout << ans << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    sol();
  }
}
