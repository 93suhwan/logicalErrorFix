#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("sse4.2")
void err(istringstream &ss) { cout << "\n"; }
template <typename T, typename... Args>
void err(istringstream &ss, const T &a, const Args &...args) {
  string token;
  getline(ss, token, ',');
  cout << token << " = " << a << "; ";
  err(ss, args...);
}
int log(int x) { return 32 - __builtin_clz(x) - 1; }
void read() {}
template <typename T, typename... Args>
void read(T &t, Args &...args) {
  cin >> t;
  read(args...);
}
struct Complex {
  double x, y;
  Complex(double x = 0, double y = 0) : x(x), y(y) {}
  Complex operator+(const Complex &a) { return Complex(x + a.x, y + a.y); }
  Complex operator-(const Complex &a) { return Complex(x - a.x, y - a.y); }
  Complex operator*(const Complex &a) {
    return Complex(x * a.x - y * a.y, x * a.y + y * a.x);
  }
};
bool check_palindrome(string s, int i, int n) {
  if (i >= n) return true;
  return (s[i] == s[n] && check_palindrome(s, i + 1, n - 1));
}
long long binpow(long long a, long long b, long long m) {
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
void solve() {
  string s;
  cin >> s;
  int cnt1 = 0, cnt = 0, n = s.size();
  for (int i = 1; i < n; i++)
    if (s[i] == '1' && s[i - 1] == '0') cnt1++;
  if (cnt1 > 0 && s[n - 1] == '0') cnt1++;
  if (n == 0) {
    cout << 0 << "\n";
    return;
  }
  if (cnt1 >= 2)
    cout << 2 << "\n";
  else if (cnt1 == 0)
    cout << (s[0] == '0' ? 1 : 0) << "\n";
  else
    cout << 1 << "\n";
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  int t = 1;
  cin >> t;
  for (int c = 1; c <= t; c++) {
    solve();
  }
  return 0;
}
