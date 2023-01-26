#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
template <typename A, typename B>
ostream& operator<<(ostream& cout, pair<A, B> const& p) {
  return cout << "(" << p.first << ", " << p.second << ")";
}
template <typename A>
ostream& operator<<(ostream& cout, vector<A> const& v) {
  cout << "[";
  for (int i = 0; i < v.size(); i++) {
    if (i) cout << ", ";
    cout << v[i];
  }
  return cout << "]";
}
template <typename A, typename B>
istream& operator>>(istream& cin, pair<A, B>& p) {
  cin >> p.first;
  return cin >> p.second;
}
template <typename A>
istream& operator>>(istream& cin, vector<A>& x) {
  for (int i = 0; i < x.size() - 1; i++) cin >> x[i];
  return cin >> x[x.size() - 1];
}
const long long mod = 1e9 + 7, inf = 2e18;
const int N = 2e5 + 1;
long long ebx(long long a, long long b = mod - 2, const long long p = mod) {
  long long z = 1;
  while (b) {
    if (b & 1) z *= a, z %= p;
    a *= a, a %= p, b >>= 1;
  }
  return z;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  long long n, m, k, r, c;
  cin >> n >> m >> k >> r >> c;
  long long ax, ay, bx, by;
  cin >> ax >> ay >> bx >> by;
  long long z = n * m;
  if (ax == bx and ay == by)
    ;
  else {
    z -= r * c;
  }
  z = ebx(k, z);
  cout << z;
}
