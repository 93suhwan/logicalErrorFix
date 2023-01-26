#include <bits/stdc++.h>
using namespace std;
inline long long MOD(long long i, long long b = 1000000007) { return i % b; }
long long MPOW(long long a, long long b, long long n = 1000000007) {
  long long x = 1, y = a;
  while (b) {
    if (b % 2) x = MOD(x * y, n);
    y = MOD(y * y, n);
    b >>= 1;
  }
  return x;
}
inline long long MINV(long long a, long long n = 1000000007) {
  return MPOW(a, n - 2, n);
}
template <typename M, typename N>
istream& operator>>(istream& i, pair<M, N>& p) {
  i >> p.first >> p.second;
  return i;
}
template <typename M, typename N>
ostream& operator<<(ostream& o, const pair<M, N>& p) {
  o << '(' << p.first << ',' << p.second << ')';
  return o;
}
template <typename M>
ostream& operator<<(ostream& o, const vector<M>& v) {
  o << '[';
  for (auto& e : v) o << e << ',';
  o << ']';
  return o;
}
void _print() {}
template <typename T>
void _print(const T& t) {
  cout << t;
}
template <typename T, typename... Ts>
void _print(const T& t, const Ts&... ts) {
  cout << t << ' ';
  _print(ts...);
}
template <typename I, typename T>
void _read(I& i, T& t) {
  i >> t;
}
template <typename I, typename T, typename... Ts>
void _read(I& i, T& t, Ts&... ts) {
  i >> t;
  _read(i, ts...);
}
void solve();
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin.exceptions(ifstream::failbit);
  long long t = 1;
  cin >> t;
  for (long long i = 0; i < (t); i++) {
    ;
    solve();
  }
  return 0;
}
void solve() {
  int n, m;
  _read(cin, n, m);
  string cmd;
  _read(cin, cmd);
  int m1, m2, mc;
  int n1, n2, nc;
  m1 = m2 = mc = 0;
  n1 = n2 = nc = 0;
  bool done = 0;
  for (auto& c : cmd) {
    switch (c) {
      case 'U':
        nc--;
        if (n1 > (nc)) n1 = (nc);
        if (n2 - n1 + 1 > n) {
          done = 1;
          n1++;
        }
        break;
      case 'D':
        nc++;
        if (n2 < (nc)) n2 = (nc);
        if (n2 - n1 + 1 > n) {
          done = 1;
          n2--;
        }
        break;
      case 'R':
        mc++;
        if (m2 < (mc)) m2 = (mc);
        if (m2 - m1 + 1 > m) {
          done = 1;
          m2--;
        }
        break;
      case 'L':
        mc--;
        if (m1 > (mc)) m1 = (mc);
        if (m2 - m1 + 1 > m) {
          done = 1;
          m1++;
        }
        break;
    }
    if (done) {
      break;
    }
  }
  _print(-1 * n1 + 1, -1 * m1 + 1), cout << '\n';
}
