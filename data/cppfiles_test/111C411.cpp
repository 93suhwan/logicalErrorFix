#include <bits/stdc++.h>
using namespace std;
void diboo() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
long long mod = 998244353;
long long power(long long base, long long exponent) {
  if (exponent < 0) exponent += mod - 1;
  long long ans = 1;
  while (exponent) {
    if (exponent & 1) ans = (ans * base) % mod;
    base = (base * base) % mod;
    exponent /= 2;
  }
  return ans;
}
long long fact(long long n);
long long nCr(long long n, long long r) {
  long long u = fact(n);
  long long x = fact(r) * fact(n - r);
  x %= mod;
  u %= mod;
  u = (u * (power(x, mod - 2) % mod)) % mod;
  return u % mod;
}
long long fact(long long n) {
  if (n == 0 || n == 1) return 1;
  return (fact(n - 1) * n) % mod;
}
int main() {
  diboo();
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s = "";
    for (int i = 0; i < n; i++) s += "()";
    cout << s << endl;
    for (int i = 1; i < 2 * n - 1; i += 2) {
      swap(s[i], s[i + 1]);
      cout << s << endl;
    }
  }
}
