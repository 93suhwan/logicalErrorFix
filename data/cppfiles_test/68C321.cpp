#include <bits/stdc++.h>
using namespace std;
long long MOD = 1e9 + 7;
template <typename T>
istream &operator>>(istream &is, vector<T> &arr) {
  typename vector<T>::iterator a;
  for (a = arr.begin(); a != arr.end(); a++) {
    is >> *a;
  }
  return is;
}
template <typename T>
ostream &operator<<(ostream &os, vector<T> &arr) {
  typename vector<T>::iterator a;
  for (a = arr.begin(); a != arr.end(); a++) {
    os << *a << " ";
  }
  return os;
}
template <typename T, typename U>
ostream &operator<<(ostream &os, pair<T, U> &p) {
  os << p.first << " " << p.second << '\n';
  return os;
}
long long mul(long long a, long long b, long long md = MOD) {
  return (a % md * b % md) % md;
}
long long add(long long a, long long b, long long md = MOD) {
  long long ans = a + b;
  if (ans >= md) ans -= md;
  return ans;
}
bool valid(int i, int j, int n, int m) {
  return i >= 0 && i < n && j >= 0 && j < m;
}
vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
long long binPow(long long x, long long y) {
  long long ans = 1;
  while (y > 0) {
    if (y % 2 == 1) ans = mul(ans, x);
    x = mul(x, x);
    y /= 2;
  }
  return ans;
}
long long modInverse(long long x) { return binPow(x, MOD - 2); }
void solve(string s, int k) { int n = s.length(); }
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < int(t); i++) {
    long long k;
    cin >> k;
    long long rt = 0;
    while (k > (rt + 1) * (rt + 1)) rt++;
    long long moved = (rt + 1) * (rt + 1) - k;
    long long x = min(moved + 1, rt + 1);
    long long y = min(2 * rt + 1 - moved, rt + 1);
    cout << y << " " << x << endl;
  }
}
