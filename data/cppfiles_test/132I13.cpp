#include <bits/stdc++.h>
using namespace std;
long long mod(long long x, long long MOD) {
  if (x > MOD) x -= MOD;
  return x;
}
long long _ceil(long long x, long long y) { return x / y + (x % y != 0); }
void wrt() {
  cout << "\n";
  return;
}
template <typename T1, typename... T2>
void wrt(T1 x, T2... args) {
  ((cout << x << ' '), wrt(args...));
}
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  for (auto& i : v) os << i << " ";
  return os;
}
template <typename T>
istream& operator>>(istream& in, vector<T>& v) {
  for (auto& e : v) in >> e;
  return in;
}
const long long MOD = 998244353;
const long long N = 1e6 + 5, inf = 1e18 + 2;
long long n, m, x, u, v, k, p, q, i, j;
string s, t;
long long ans;
long long a[N];
vector<long long> arr(7, 0);
bool f(long long i, long long j, long long k) {
  long long x;
  vector<long long> res;
  res.push_back(arr[i]);
  res.push_back(arr[j]);
  res.push_back(arr[k]);
  res.push_back(arr[i] + arr[j]);
  res.push_back(arr[j] + arr[k]);
  res.push_back(arr[i] + arr[k]);
  res.push_back(arr[i] + arr[j] + arr[k]);
  sort((res).begin(), (res).end());
  for (long long i = 0; i < (((long long)(res).size())); ++i) {
    if (res[i] != arr[i]) return false;
  }
  return true;
}
void solve() {
  arr.clear();
  cin >> arr;
  sort((arr).begin(), (arr).end());
  for (long long i = 0; i < (7); ++i) {
    for (long long j = (i + 1); j < (7); ++j) {
      for (long long k = (j + 1); k < (7); ++k) {
        if (f(i, j, k)) {
          wrt(arr[i], arr[j], arr[k]);
        }
      }
    }
  }
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
