#include <bits/stdc++.h>
using namespace std;
template <typename T>
T Sqr(T x) {
  T n = x * x;
  return n;
}
template <typename T>
T Pow(T B, T P) {
  if (P == 0) return 1;
  if (P & 1)
    return B * Pow(B, P - 1);
  else
    return Sqr(Pow(B, P / 2));
}
template <typename T>
T Abs(T a) {
  if (a < 0)
    return -a;
  else
    return a;
}
template <typename T>
T Gcd(T a, T b) {
  if (a < 0) return Gcd(-a, b);
  if (b < 0) return Gcd(a, -b);
  return (b == 0) ? a : Gcd(b, a % b);
}
template <typename T>
T Lcm(T a, T b) {
  if (a < 0) return Lcm(-a, b);
  if (b < 0) return Lcm(a, -b);
  return a * (b / Gcd(a, b));
}
template <typename T>
T power(T n, T p) {
  T res = 1;
  while (p > 0) {
    if (p & 1) res *= n;
    n *= n;
    p >>= 1;
  }
  return res;
}
template <typename T>
T BigMod(T b, T p, T m) {
  if (p == 0) return 1;
  if (p % 2 == 0) {
    T s = BigMod(b, p / 2, m);
    return ((s % m) * (s % m)) % m;
  }
  return ((b % m) * (BigMod(b, p - 1, m) % m)) % m;
}
template <typename T>
inline string ToBinary(T n) {
  string r;
  while (n != 0) {
    r = (n % 2 == 0 ? "0" : "1") + r;
    n >>= 1;
  }
  return r;
}
long long BinaryToDecimal(string s) {
  int len = s.size();
  long long n = 0, p = 1;
  for (int i = len - 1; i >= 0; i--, p *= 2) n += p * (s[i] - '0');
  return n;
}
int Strtoint(string str) {
  stringstream second(str);
  int x = 0;
  second >> x;
  return x;
}
string Intostr(int x) {
  stringstream second;
  second << x;
  string str = second.str();
  return str;
}
int ROW[] = {+1, -1, +0, +0};
int COL[] = {+0, +0, +1, -1};
int X[] = {+0, +0, +1, -1, -1, +1, -1, +1};
int Y[] = {-1, +1, +0, +0, +1, +1, -1, -1};
int KX[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int KY[] = {-1, 1, -2, 2, -2, 2, -1, 1};
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long x, y;
    cin >> x >> y;
    if (x < y)
      cout << (x + y) / 2 << endl;
    else if (x == y)
      cout << x << endl;
    else {
      cout << x + y / 2 << endl;
    }
  }
  return 0;
}
