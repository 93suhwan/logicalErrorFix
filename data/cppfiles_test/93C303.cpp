#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e17;
const long long NINF = (-1) * INF;
vector<string> s1;
long long power(long long x, long long y, long long m) {
  long long res = 1;
  x %= m;
  while (y > 0) {
    if (y & 1) res = (res * x) % m;
    y >>= 1;
    x = (x * x) % m;
  }
  return res % m;
}
bool isPowerOfTwo(long long n) {
  if (n == 0) return false;
  return (ceil(log2(n)) == floor(log2(n)));
}
bool isvalid(long long ar, long long n) {
  if (ar > n - 1) return false;
  return true;
}
long long sumOfDigit(long long n, long long b) {
  long long unitDigit, sum = 0;
  while (n > 0) {
    unitDigit = n % b;
    sum += unitDigit;
    n = n / b;
  }
  return sum;
}
long long computeXOR(long long n) {
  if (n % 4 == 0) return n;
  if (n % 4 == 1) return 1;
  if (n % 4 == 2) return n + 1;
  return 0;
}
class sol {
 public:
  void solve() {
    long long a, b;
    cin >> a >> b;
    long long n = a;
    if (a > 1)
      a = computeXOR(a - 1);
    else
      a = 0;
    if (a == b) {
      cout << n << endl;
    } else {
      a ^= b;
      if (a == n)
        cout << n + 2 << endl;
      else
        cout << n + 1 << endl;
    }
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  sol s;
  while (t--) s.solve();
  return 0;
}
