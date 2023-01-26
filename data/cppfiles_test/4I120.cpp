#include <bits/stdc++.h>
using namespace std;
long long max(long long a, long long b) {
  if (a >= b) {
    return a;
  }
  return b;
}
long long min(long long a, long long b) {
  if (a <= b) {
    return a;
  }
  return b;
}
long long modpower(long long a, long long n, long long d = 1000000007) {
  long long res = 1;
  while (n) {
    if (n % 2) {
      res = ((res % d) * (a % d)) % d;
      n--;
    } else {
      a = ((a % d) * (a % d)) % d;
      n /= 2;
    }
  }
  return res;
}
long long modadd(long long a, long long b, long long d = 1000000007) {
  return ((a % d) + (b % d)) % d;
}
long long modsubtract(long long a, long long b, long long d = 1000000007) {
  return ((a % d) - (b % d)) % d;
}
long long modproduct(long long a, long long b, long long d = 1000000007) {
  return ((a % d) * (b % d)) % d;
}
void solve() {
  long long n;
  cin >> n;
  long long x = 4;
  cout << 2 << " ";
  while (x < n) {
    if (n % x == 1) {
      cout << x << "\n";
      return;
    }
    x *= 2;
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t > 0) {
    t--;
    solve();
  }
}
