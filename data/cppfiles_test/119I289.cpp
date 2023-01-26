#include <bits/stdc++.h>
using namespace std;
void _init() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
}
long long int gcd(long long int x, long long int y) {
  if (y == 0) return x;
  return gcd(y, x % y);
}
long long int lcm(long long int x, long long int y) {
  long long int e = gcd(x, y);
  return (x * y) / e;
}
bool isprime(int n) {
  if (n == 1) return false;
  for (int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) return false;
  }
  return true;
}
long long int power(long long int a, long long int b) {
  long long int res = 1;
  while (b) {
    if (b & 1) {
      res = (res * a) % 1000000007;
      b--;
    }
    a = (a * a) % 1000000007;
    b = b / 2;
  }
  return res;
}
void solve() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  int diff = 0;
  for (int i = 1; i < n; i++) {
    diff += a[i] - a[i - 1];
  }
  if (diff % 2) {
    cout << 1 << "\n";
  } else {
    cout << 0 << "\n";
  }
}
int main() {
  _init();
  int t = 1;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}
