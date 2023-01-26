#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target( \
    "fma,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) {
  return os << '(' << p.first << ", " << p.second << ')';
}
template <typename T_container, typename T = typename enable_if<
                                    !is_same<T_container, string>::value,
                                    typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v) {
  os << '{';
  string sep;
  for (const T &x : v) os << sep << x, sep = ", ";
  return os << '}';
}
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cerr << ' ' << H;
  dbg_out(T...);
}
const int MAX_N = 1e5 + 5;
const long long MOD = 1e9 + 7;
const long long INF = 1e9;
const long double EPS = 1e-9;
string to_binary(long long n) {
  string s;
  for (int i = 63; i >= 0; i--) {
    long long t = (1 << i) & n;
    if (t > 0)
      s = s + "1";
    else
      s = s + "0";
  }
  return s;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  a %= b;
  return gcd(b, a);
}
void solve() {
  long long n;
  cin >> n;
  vector<long long> a(n, 0);
  for (long long i = 0; i < n; i++) cin >> a[i];
  vector<long long> bits(64, 0);
  for (int i = 0; i < n; i++) {
    string s = to_binary(a[i]);
    for (int j = 0; j < 64; j++) {
      if (s[j] == '1') bits[j]++;
    }
  }
  long long ans = 0;
  for (int i = 0; i < 64; i++) ans = gcd(ans, bits[i]);
  for (int k = 1; k <= n; k++) {
    if (ans % k == 0) cout << k << " ";
  }
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc = 1;
  cin >> tc;
  for (int t = 1; t <= tc; t++) {
    solve();
  }
  return 0;
}
