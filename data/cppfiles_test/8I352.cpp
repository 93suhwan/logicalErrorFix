#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  if (!b) return a;
  return gcd(b, a % b);
}
long long int lcm(long long int a, long long int b) {
  return (a * b) / gcd(a, b);
}
string inc(string &s) {
  long long x = stoll(s);
  x++;
  return s = to_string(x);
}
template <typename T>
T pow(T a, T b, long long m) {
  T ans = 1;
  while (b > 0) {
    if (b % 2 == 1) ans = (ans * a) % m;
    b /= 2;
    a = (a * a) % m;
  }
  return ans % m;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long int tt = 1;
  cin >> tt;
  for (long long int ii = 1; ii <= tt; ii++) {
    long long int n;
    cin >> n;
    printf("%lld %lld\n", n / 3, n - (n / 3));
  }
}
