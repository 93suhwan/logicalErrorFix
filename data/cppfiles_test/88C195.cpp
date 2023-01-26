#include <bits/stdc++.h>
#pragma GCC optimize("Ofast", "unroll-loops")
using namespace std;
template <typename... T>
void read(T&... args);
template <typename... T>
void write(T&&... args);
void __testCase(long long t);
long long mpow(long long base, long long exp);
long long gcd(long long a, long long b);
const long long mod = 1000000007;
const bool isTestCase = true;
void solve() {
  long long n;
  cin >> n;
  vector<long long> arr(n);
  for (auto& i : arr) cin >> i;
  if (n % 2) {
    for (long long i = 0; i + 1 < n; i++) {
      if (arr[i] >= arr[i + 1]) {
        cout << "YES\n";
        return;
      }
    }
    cout << "NO\n";
  } else {
    cout << "YES\n";
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  if (isTestCase) cin >> t;
  __testCase(t);
  return 0;
}
long long mpow(long long base, long long exp) {
  base %= mod;
  long long result = 1;
  while (exp > 0) {
    if (exp & 1) result = ((long long)result * base) % mod;
    base = ((long long)base * base) % mod;
    exp >>= 1;
  }
  return result;
}
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
template <typename... T>
void read(T&... args) {
  ((cin >> args), ...);
}
template <typename... T>
void write(T&&... args) {
  ((cout << args << " "), ...);
  cout << "\n";
}
void __clock() {
  cout << "__________________________" << endl;
  cout << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
}
void __testCase(long long t) {
  while (t--) solve();
}
