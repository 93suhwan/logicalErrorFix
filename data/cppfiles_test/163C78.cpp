#include <bits/stdc++.h>
using namespace std;
template <typename T>
istream &operator>>(istream &cin, pair<T, T> &v) {
  cin >> v.first >> v.second;
  return cin;
}
template <typename T>
istream &operator>>(istream &cin, vector<T> &v) {
  for (T &e : v) cin >> e;
  return cin;
}
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V> &x) {
  cerr << '{';
  __print(x.first);
  cerr << ',';
  __print(x.second);
  cerr << '}';
}
template <typename T>
void __print(const T &x) {
  int first = 0;
  cerr << '{';
  for (auto &i : x) cerr << (first++ ? "," : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
void JUDGE() {}
long long inline mo(long long a) { return a % (long long)(1000000000 + 7); }
long long po(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y >>= 1;
    x = (x * x) % p;
  }
  return res % p;
}
void test_case();
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int test_cases = 1;
  cin >> test_cases;
  while (test_cases--) test_case();
  return 0;
}
void test_case() {
  long long n, m, r_x, r_y, d_x, d_y, p;
  cin >> n >> m >> r_x >> r_y >> d_x >> d_y >> p;
  r_x--;
  r_y--;
  d_x--;
  d_y--;
  p = mo(p *
         po(100, (long long)(1000000000 + 7) - 2, (long long)(1000000000 + 7)));
  long long inv_p =
      (1 - p + (long long)(1000000000 + 7)) % (long long)(1000000000 + 7);
  long long x = r_x, y = r_y, cur_time = 0;
  long long product = 1, sum = 0;
  long long di_x = 1, di_y = 1;
  long long ac_x = 1, ac_y = 1;
  if (x - 1 < 0) ac_x = -1;
  if (y - 1 < 0) ac_y = -1;
  while (1) {
    if (x == d_x || y == d_y) {
      sum = mo(sum + mo(cur_time * mo(product)));
      sum %= (long long)(1000000000 + 7);
      product *= inv_p;
      product %= (long long)(1000000000 + 7);
    }
    if (di_x == 1 && x == n - 1)
      di_x = -1;
    else if (di_x == -1 && !x)
      di_x = 1;
    if (di_y == 1 && y == m - 1)
      di_y = -1;
    else if (di_y == -1 && !y)
      di_y = 1;
    x += di_x;
    y += di_y;
    cur_time++;
    cur_time %= (long long)(1000000000 + 7);
    if (x == r_x && y == r_y && di_x == ac_x && di_y == ac_y) break;
  }
  long long inv_val =
      po(mo(1 - product + (long long)(1000000000 + 7)),
         (long long)(1000000000 + 7) - 2, (long long)(1000000000 + 7));
  sum = mo(mo(sum * p) + mo(product * mo(cur_time)));
  sum %= (long long)(1000000000 + 7);
  long long ans = mo(sum * inv_val);
  cout << ans << "\n";
}
