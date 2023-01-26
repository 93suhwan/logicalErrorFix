#include <bits/stdc++.h>
using namespace std;
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
  int f = 0;
  cerr << '{';
  for (auto &i : x) cerr << (f++ ? "," : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
const long long MOD = 1000000007;
long long power(long long x, long long y) {
  if (y == 0)
    return 1;
  else if (y % 2 == 0)
    return (((long long)power(x, y / 2) % MOD) *
            ((long long)power(x, y / 2) % MOD)) %
           MOD;
  else
    return (long long)(((long long)(x * (long long)(power(x, y / 2) % MOD)) %
                        MOD) *
                       (long long)((long long)power(x, y / 2) % MOD)) %
           MOD;
}
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
int main(void) {
  int tt = 1;
  cin >> tt;
  while (tt--) {
    long long a, b, c;
    cin >> a >> b >> c;
    if ((a + 2 * b + 3 * c) % 2 == 0)
      cout << 0 << endl;
    else
      cout << 1 << endl;
  }
  return 0;
}
