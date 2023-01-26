#include <bits/stdc++.h>
using namespace std;
long long fastpower(long a, long b, long long n = 1000000007) {
  long res = 1;
  while (b > 0) {
    if ((b & 1) != 0) {
      res = (res % n * a % n) % n;
    }
    a = (a % n * a % n) % n;
    b = b >> 1;
  }
  return res;
}
bool isPrime(long long n) {
  if (n <= 3) return n > 1;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long i = 5; i * i <= n; i += 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
long long gcd(long long a, long long b) {
  long long c = a % b;
  while (c != 0) {
    a = b;
    b = c;
    c = a % b;
  }
  return b;
}
int32_t main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  long long t = 1;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long count = 1, i = 0;
    while (count <= n) {
      i++;
      count = i * i;
      if (count == n) {
        i--;
        break;
      } else if (count > n) {
        i--;
        break;
      }
    }
    count = i * i;
    long long x = 1, y = i + 1;
    for (long long j = count + 1; j <= (i + 1) * (i + 1); j++) {
      if (j == n) {
        cout << x << " " << y << "\n";
        break;
      } else {
        if (x >= i + 1) y--;
        if (x < i + 1) x++;
      }
    }
  }
  return 0;
}
