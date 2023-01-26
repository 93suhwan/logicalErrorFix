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
const long long MOD = 1e9 + 7;
const long long N = 1e6 + 5, inf = 1e18 + 2;
long long n, m, x, u, v, k, p, q, i, j;
string s, t;
long long ans;
long long a[N];
void solve() {
  cin >> n;
  vector<long long> a(n);
  cin >> a;
  multiset<long long> st((a).begin(), (a).end());
  x = 0;
  for (long long i = 1; i <= (n); ++i) {
    if (st.find(i) != st.end()) {
      st.erase(st.find(i));
    } else {
      long long ch = max(n + 1, i + i + 1);
      if (st.lower_bound(ch) != st.end()) {
        st.erase(st.lower_bound(ch));
        x++;
      } else {
        return wrt(-1);
      }
    }
  }
  wrt(x);
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
