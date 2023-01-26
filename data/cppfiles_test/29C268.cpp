#include <bits/stdc++.h>
using namespace std;
template <typename T, typename T1>
T abs(T a, T1 b) {
  if (b > a) return b - a;
  return a - b;
}
template <typename T, typename T1>
T amax(T &a, T1 b) {
  if (b > a) a = b;
  return a;
}
template <typename T, typename T1>
T amin(T &a, T1 b) {
  if (b < a) a = b;
  return a;
}
long long mul_mod(long long a, long long b, long long p) {
  return ((a % p) * (b % p)) % p;
}
long long add_mod(long long a, long long b, long long p) {
  return ((a % p) + (b % p)) % p;
}
long long sub_mod(long long a, long long b, long long p) {
  return ((a - b) % p) + ((a >= b) ? 0 : p);
}
void solve() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (long long i = 0; i < n; i++) cin >> a[i];
  long long cnt0 = 0, cnt1 = 0;
  for (long long i = 0; i < n; i++) {
    if (a[i] == 0) cnt0++;
    if (a[i] == 1) cnt1++;
  }
  cout << (long long)pow(2, cnt0) * cnt1 << "\n";
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
