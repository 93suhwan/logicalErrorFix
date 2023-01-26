#include <bits/stdc++.h>
using namespace std;
const long double pi = 3.14159265359;
inline long long add(long long a, long long b, long long m) {
  if ((a + b) >= m) return (a + b) % m;
  return a + b;
}
inline long long mul(long long a, long long b, long long m) {
  if ((a * b) < m) return a * b;
  return (a * b) % m;
}
long long power(long long x, long long y, long long m) {
  long long res = 1;
  x = x % m;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % m;
    y = y >> 1;
    x = (x * x) % m;
  }
  return res;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1, n;
  cin >> t;
  vector<int> xo(300005);
  for (int i = 1; i < xo.size(); i++) {
    xo[i] = i ^ xo[i - 1];
  }
  while (t--) {
    int a, b;
    cin >> a >> b;
    int x = xo[a - 1];
    int y = x ^ b;
    if (x == b) {
      cout << a << endl;
    } else if (y != a) {
      cout << a + 1 << endl;
    } else {
      cout << a + 2 << endl;
    }
  }
  return 0;
}
