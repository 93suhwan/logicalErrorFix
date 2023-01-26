#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
long long mod_expo(long long a, long long b, long long mod) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b = b >> 1;
  }
  return res;
}
long long mod_add(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (((a + b) % m) + m) % m;
}
long long mod_mul(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (((a * b) % m) + m) % m;
}
long long mod_sub(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (((a - b) % m) + m) % m;
}
void solve() {
  long long x, n;
  cin >> x >> n;
  if ((n % 4) == 0) {
    cout << x << "\n";
  } else {
    long long val = n;
    long long m = (n % 4);
    if (x & 1) {
      if (m == 1)
        x += val;
      else if (m == 2)
        x--;
      else if (m == 3)
        x -= (1 + n);
    } else {
      if (m == 1)
        x -= val;
      else if (m == 2)
        x++;
      else if (m == 3)
        x += 1 + n;
    }
    cout << x << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t-- > 0) {
    solve();
  }
  return 0;
}
