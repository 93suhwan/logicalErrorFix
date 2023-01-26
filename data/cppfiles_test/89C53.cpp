#include <bits/stdc++.h>
using namespace std;
long long gcd(long long x, long long y) {
  if (!y) return x;
  return gcd(y, x % y);
}
long long power(long long a, long long b, long long p) {
  if (a == 0) return 0;
  long long res = 1;
  a %= p;
  while (b > 0) {
    if (b % 2) res = (res * a) % p;
    a = (a * a) % p;
    b = b / 2;
  }
  return res;
}
const int maxn = 2 * 1e5 + 5;
long long n;
map<long long, long long> dp;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long test = 1;
  cin >> test;
  while (test--) {
    long long n;
    cin >> n;
    long long a[n];
    bool flag = false;
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (long long i = 0; i < n; i++) {
      flag = false;
      for (long long j = 2; j <= i + 2; j++) {
        if (a[i] % j) {
          flag = true;
          break;
        }
      }
      if (!flag) break;
    }
    if (flag)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
