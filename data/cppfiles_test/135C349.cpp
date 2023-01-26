#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  if (b == 0) {
    return a;
  } else {
    return gcd(b, a % b);
  }
}
long long int binpow(long long int a, long long int b) {
  if (b == 0) {
    return 1;
  }
  long long int res = 1;
  long long int c = 1000000007;
  while (b != 1) {
    if (b % 2 == 0) {
      a *= a;
      b /= 2;
    } else {
      res *= a;
      b--;
    }
  }
  return res * a;
}
bool isPrime(long long int n) {
  if (n < 2) {
    return false;
  }
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}
bool myf(pair<long long int, long long int> A,
         pair<long long int, long long int> B) {
  return (A.first > B.first);
}
void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  int x = n - 1, sum = 0;
  sort(v.begin(), v.end());
  while (x >= n - k) {
    sum += v[x - k] / v[x];
    x--;
  }
  x -= k;
  while (x >= 0) {
    sum += v[x];
    x--;
  }
  cout << sum << endl;
  return;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
