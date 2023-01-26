#include <bits/stdc++.h>
using namespace std;
template <typename A>
ostream &operator<<(ostream &cout, vector<A> const &v);
template <typename A, typename B>
ostream &operator<<(ostream &cout, pair<A, B> const &p) {
  return cout << "(" << p.first << ", " << p.second << ")";
}
template <typename A>
ostream &operator<<(ostream &cout, vector<A> const &v) {
  cout << "[";
  for (int i = 0; i < v.size(); i++) {
    if (i) cout << ", ";
    cout << v[i];
  }
  return cout << "]";
}
template <typename A, typename B>
istream &operator>>(istream &cin, pair<A, B> &p) {
  cin >> p.first;
  return cin >> p.second;
}
mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
void usaco(string filename) {
  freopen((filename + ".in").c_str(), "r", stdin);
  freopen((filename + ".out").c_str(), "w", stdout);
}
const long double pi = 3.14159265358979323846;
const long long mod = 998244353;
long long n, m, q, k, l, r, x, y, z;
const long long template_array_size = 1e6 + 17646;
long long a[template_array_size];
long long b[template_array_size];
long long c[template_array_size];
string second, t;
long long fact[200005];
long long cnt(long long x) {
  long long r = 0;
  for (long long i = 0; i < n; i++) {
    if (a[i] == x) {
      ++r;
    }
  }
  return r;
}
void solve(int tc = 0) {
  cin >> n;
  for (long long i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  long long y = cnt(a[n - 1]);
  long long z = cnt(a[n - 1] - 1);
  if (y >= 2) {
    cout << fact[n] << '\n';
    return;
  }
  long long r = 1;
  for (long long i = n; i > (y + z); i--) r = (r * i) % mod;
  r = (r * (fact[y + z] - fact[y + z - 1] + mod)) % mod;
  cout << r << '\n';
}
int main() {
  { ios_base::sync_with_stdio(false); }
  { cin.tie(NULL); }
  cout << setprecision(15) << fixed;
  fact[0] = fact[1] = 1;
  for (long long i = 2; i <= 200003; i++) {
    fact[i] = (i * fact[i - 1]) % mod;
  }
  int tc = 1;
  cin >> tc;
  for (int t = 0; t < tc; t++) {
    solve(t);
  }
}
