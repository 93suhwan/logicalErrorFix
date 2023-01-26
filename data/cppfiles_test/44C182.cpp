#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
using namespace std;
bool per_square(long double a) {
  if (a < 0) return false;
  long long sr = sqrt(a);
  return (sr * sr == a);
}
bool is_prime(long long x) {
  for (long long i = 2; i < sqrt(x) + 1; i++)
    if (x % i == 0) return false;
  return true;
}
bool sort_by_sec(const pair<long long, long long> &a,
                 const pair<long long, long long> &b) {
  return (a.second < b.second);
}
template <typename T>
bool is_pali(T A) {
  long long n = (long long)((A).size());
  for (long long i = 0; i < n / 2; i++) {
    if (A[i] != A[n - i - 1]) return 0;
  }
  return 1;
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
void solve() {
  long long a, b;
  cin >> a >> b;
  if (a == b && a == 0)
    cout << 0 << '\n';
  else if (a == b and a != 0)
    cout << 1 << '\n';
  else if ((a + b) % 2 == 0)
    cout << 2 << '\n';
  else
    cout << -1 << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long tests = 1;
  cin >> tests;
  for (long long test = 1; test <= tests; test++) {
    solve();
  }
  return 0;
}
