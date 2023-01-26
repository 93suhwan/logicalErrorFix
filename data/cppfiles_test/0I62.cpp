#include <bits/stdc++.h>
using namespace std;
bool sortinrev(long long x, long long y) { return x > y; }
void swap(long long* a, long long* b) {
  long long temp = *a;
  *a = *b;
  *b = temp;
}
long long div_ceil(long long a, long long b) { return (a + b - 1) / b; }
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
const int MOD = 1000 * 1000 * 1000 + 7;
const long long INF = 1e18L + 5;
const int nax = 2005;
const int N = int(1e6);
bool isPrime(long long x) {
  for (long long i = 2; i * i <= x; i++) {
    if (x % i == 0) return false;
  }
  return true;
}
void solve() {
  long long n;
  cin >> n;
  vector<long long> arr(n);
  for (long long i = 0; i < n; ++i) cin >> arr[i];
  set<long long> s;
  for (long long i = 0; i < n; ++i) {
    for (long long j = i + 1; j < n; j++) {
      s.insert(abs(arr[i] - arr[j]));
    }
  }
  if (s.size() == 1 && *s.begin() == 0) {
    cout << -1 << "\n";
    return;
  }
  long long res = *s.begin();
  for (auto x : s) {
    res = gcd(res, x);
  }
  cout << res << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
}
