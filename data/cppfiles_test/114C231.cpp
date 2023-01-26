#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
template <typename T, typename U>
long long modMul(T a, U b) {
  return ((a % 1000000007) * 1LL * (b % 1000000007)) % 1000000007;
}
template <typename T, typename U>
long long binpower(T n, U k) {
  T res = 1;
  while (k) {
    if (k & 1) {
      res = modMul(res, n);
    }
    n = modMul(n, n);
    k >>= 1;
  }
  return res % 1000000007;
}
template <typename T>
T moduloInverse(T a) {
  return binpower(a, 1000000007 - 2);
}
template <typename T, typename U>
long long modAdd(T a, U b) {
  return ((a % 1000000007) + (b % 1000000007)) % 1000000007;
}
template <typename T, typename U>
long long modSub(T a, U b) {
  return ((a % 1000000007) - (b % 1000000007) + 1000000007) % 1000000007;
}
template <typename T, typename U>
long long modDiv(T a, U b) {
  return modMul(a, moduloInverse(b));
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return (a / gcd(a, b)) * b; }
void _print(long long x) { cerr << x; }
void _print(float x) { cerr << x; }
void _print(double x) { cerr << x; }
void _print(string x) { cerr << x; }
void _print(unsigned long long x) { cerr << x; }
void _print(char x) { cerr << x; }
void _print(bool x) { cerr << x; }
template <typename T>
vector<T> inp(long long n) {
  vector<T> ain(n);
  for (long long i = 0; i < n; i++) cin >> ain[i];
  return ain;
}
template <typename T>
void print(vector<T> arr) {
  for (long long i = 0; i < arr.size(); i++) cout << arr[i] << " ";
  cout << "\n";
  return;
}
void solve() {
  long long n, k;
  cin >> n;
  vector<long long> arr = inp<long long>(n);
  sort((arr).begin(), (arr).end());
  k = arr[0];
  long long ct = n / 2, p = 1;
  while (ct--) {
    cout << arr[p] << " " << k << "\n";
    p++;
  }
  return;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) solve();
  return 0;
}
