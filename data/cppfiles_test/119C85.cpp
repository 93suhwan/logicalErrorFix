#include <bits/stdc++.h>
using namespace std;
int d = 1000000007;
long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
bool issqrt(int n) {
  float x = sqrt(n);
  int y = sqrt(n);
  return (y == x);
}
bool isprime(int x) {
  if (x == 1) {
    return false;
  }
  int n = sqrt(x);
  for (int i = 2; i <= n; i++) {
    if (x % i == 0) {
      return false;
    }
  }
  return true;
}
void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  int sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    sum += v[i];
  }
  if (sum % n == 0) {
    cout << 0 << endl;
    return;
  }
  cout << 1 << endl;
  return;
}
int main() {
  int t;
  cin >> t;
  while (t > 0) {
    solve();
    t--;
  }
  return 0;
}
