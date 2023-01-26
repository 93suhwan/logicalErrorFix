#include <bits/stdc++.h>
using namespace std;
long long int SOD(long long int n) {
  long long int sum = 0;
  while (n > 0) {
    sum = sum + n % 10;
    n /= 10;
  }
  return sum;
}
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int lcm(long long int a, long long int b) {
  return (a * b) / gcd(a, b);
}
long long int pow(long long int a, long long int b) {
  long long int res = 1;
  while (b > 0) {
    if (b % 2 == 1) res *= a;
    a *= a;
    b /= 2;
  }
  return res;
}
long long int powmod(long long int x, long long int y, long long int p) {
  long long int res = 1;
  x = x % p;
  if (x == 0) return 0;
  while (y > 0) {
    if (y % 2 == 1) res = (res * x) % p;
    y /= 2;
    x = (x * x) % p;
  }
  return res;
}
string dectobin(long long int x) {
  string s = "";
  while (x > 0) {
    long long int t = x % 2;
    s.push_back(t + '0');
    x /= 2;
  }
  reverse(s.begin(), s.end());
  if (s.compare("") == 0)
    return "0";
  else
    return s;
}
long long int bintodec(string s) {
  long long int ans = 0;
  long long int n = s.size();
  for (long long int i = n - 1; i >= 0; i--) {
    if (s[i] == '1') ans += pow(2, n - i - 1);
  }
  return ans;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int m = 1e9 + 7;
  long long int fact[200001] = {};
  fact[0] = 1;
  for (long long int i = 1; i <= 2e5; i++) fact[i] = (fact[i - 1] * i) % m;
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    cout << (fact[2 * n] * powmod(2, m - 2, m)) % m << "\n";
  }
}
