#include <bits/stdc++.h>
using namespace std;
long long int powermodm(long long int x, long long int n, long long int M) {
  long long int result = 1;
  while (n > 0) {
    if (n % 2 == 1) result = (result * x) % M;
    x = (x * x) % M;
    n = n / 2;
  }
  return result;
}
long long int power(long long int _a, long long int _b) {
  long long int _r = 1;
  while (_b) {
    if (_b % 2 == 1) _r = (_r * _a);
    _b /= 2;
    _a = (_a * _a);
  }
  return _r;
}
long long int gcd(long long int a, long long int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
long long int lcm(long long int a, long long int b) {
  return (max(a, b) / gcd(a, b)) * min(a, b);
}
void write(long long int a[], long long int n) {
  for (long long int i = 0; i < n; i++) cout << a[i] << " ";
  cout << "\n";
}
void fun() {
  long long int n;
  cin >> n;
  cout << "2 " << n - 1;
  cout << "\n";
  return;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t = 1;
  cin >> t;
  while (t--) fun();
  return 0;
}
