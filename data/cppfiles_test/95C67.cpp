#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
const int MOD = 1e9 + 7;
const ll INF = 1e18;
inline void fastio() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
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
mt19937 rng(
    (unsigned int)chrono::steady_clock::now().time_since_epoch().count());
int rand(int l, int r) {
  uniform_int_distribution<int> uid(l, r);
  return uid(rng);
}
int digits(int num) {
  int d{};
  while (num > 0) {
    d++;
    num /= 10;
  }
  return d;
}
int pow(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) {
      res *= a;
    }
    a = a * a;
    b >>= 1;
  }
  return res;
}
void solve() {
  int s, n;
  cin >> s >> n;
  vector<int> out;
  while (n > 1) {
    int d = digits(s);
    for (int i = d; i >= 1; i--) {
      int get = pow(10, i - 1);
      if (s - get >= n - 1) {
        out.push_back(get);
        s -= get;
        n--;
        break;
      }
    }
  }
  out.push_back(s);
  for (int e : out) {
    cout << e << " ";
  }
  cout << '\n';
}
int main() {
  fastio();
  cout << setprecision(15) << fixed;
  int tc = 1;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}
