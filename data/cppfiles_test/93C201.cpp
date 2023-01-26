#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;
template <typename D>
istream &operator>>(istream &in, vector<D> &arr) {
  long long n = arr.size();
  for (long long(i) = (0); (i) < (n); ++(i)) {
    in >> arr[i];
  }
  return in;
}
template <typename D>
ostream &operator<<(ostream &in, vector<D> &arr) {
  for (auto &x : arr) in << x << " ";
  return in;
}
template <typename D, typename B>
ostream &operator<<(ostream &in, pair<D, B> &p) {
  in << p.first << " " << p.second << " ";
  return in;
}
template <typename D, typename B>
istream &operator>>(istream &in, pair<D, B> &p) {
  in >> p.first >> p.second;
  return in;
}
long long i, j, k, l, x, y, z, m, n, a, b, c, r, d, t = 1, ans;
string second;
template <typename A, typename B>
A max(A a, B b) {
  return (a > b) ? a : b;
}
template <typename A, typename B>
A min(A a, B b) {
  return (a < b) ? a : b;
}
int modpow(long long a, long long b, int m = 1000000007) {
  long long res = 1;
  a %= m;
  if (a == 0) return a;
  while (b > 0) {
    if (b & 1) res = (res * a) % m;
    a *= a;
    a %= m;
    b >>= 1;
  }
  return res;
}
void solve(int tc) {
  cin >> n >> k;
  ans = 0;
  long long curr = 1;
  while (curr < n && curr <= k) {
    ans++;
    curr <<= 1;
  }
  n -= curr;
  if (n <= 0) return void(cout << (ans) << "\n");
  ans += (n + k - 1) / k;
  cout << (ans) << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int k = 1;
  cin >> t;
  while (t--) solve(k++);
  return 0;
}
