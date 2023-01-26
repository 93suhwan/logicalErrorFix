#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
using namespace std;
long long mod = 1000000007;
template <typename T>
void rv(vector<T> &a) {
  for (int i = 0; i < a.size(); i++) {
    cin >> a[i];
  }
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
uint64_t binpow(uint64_t a, uint64_t n) {
  uint64_t res = 1;
  while (n) {
    if (n & 1) res *= a;
    a *= a;
    n >>= 1;
  }
  return res;
}
long long binpow(long long a, long long b, long long m) {
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
const int EPS = 9;
const int eMXN = 2e5;
long long MinDivisor(long long n) {
  if (n % 2 == 0) return 2;
  for (long long i = 3, isqrt = sqrt(n); i <= isqrt; i += 2)
    if (n % i == 0) return i;
  return n;
}
bool IsPrime(long long n) { return (MinDivisor(n) == n); }
void print(vector<pair<int, int>> a) {
  for (auto c : a) {
    cout << c.first << " ";
  }
  cout << "\n";
}
long long mid(vector<long long> a) {
  sort(a.begin(), a.end());
  return a[(a.size() - 1) / 2];
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int m;
    cin >> m;
    int n = m - 2;
    vector<string> a(n);
    rv(a);
    string ans = "";
    for (int i = 0; i < n - 1; i++) {
      ans += a[i][0];
    }
    ans += a.back();
    ans += 'b';
    cout << ans << "\n";
  }
  return 0;
}
