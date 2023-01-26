#include <bits/stdc++.h>
using namespace std;
string en = "\n";
string sp = " ";
string t = "hello";
string Y = "YES\n";
string N = "NO\n";
int dx[] = {-1, 0, 0, 1, -1, -1, 1, 1}, Row, Col;
int dy[] = {0, -1, 1, 0, -1, 1, -1, 1};
int kx[] = {-2, -2, 2, 2, -1, -1, 1, 1};
int ky[] = {-1, 1, -1, 1, -2, 2, -2, 2};
using LL = long long;
using LD = long double;
using ULL = unsigned long long;
bool isprm(LL a) {
  for (LL i = 2; i * i <= a; i++) {
    if (a % i == 0) return false;
  }
  return true;
}
bool palin(string a) {
  for (int i = 0; i < a.size(); i++) {
    if (a.at(i) != a.at(a.size() - i - 1)) return 0;
  }
  return 1;
}
LL binpow(LL a, LL b) {
  LL r = 1;
  while (b > 0) {
    if (b & 1) r = r * a;
    a = a * a;
    b >>= 1;
  }
  return r;
}
LL binpow(LL a, LL b, LL m) {
  a %= m;
  LL r = 1;
  while (b > 0) {
    if (b & 1) r = r * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return r;
}
template <typename T>
inline T gcd(T a, T b) {
  if (a < 0) return gcd(-a, b);
  if (b < 0) return gcd(a, -b);
  return (b == 0) ? a : gcd(b, a % b);
}
template <typename T>
inline T lcm(T a, T b) {
  if (a < 0) return lcm(-a, b);
  if (b < 0) return lcm(a, -b);
  return a * (b / gcd(a, b));
}
int main() {
  LL i, j, k, n, m, l, s = 0, x, y, tc = 1, p, q, a, b, c = 0, d;
  bool f = 0, ff = 0;
  string st, sa, sb, sc;
  char ch;
  cin >> tc;
  while (tc--) {
    cin >> n;
    cin >> sa >> sb;
    c = 0;
    for (i = 0; i < n; i++) {
      if (sb[i] == '1') {
        if (sa[i] == '0')
          c++, sa[i] = '*';
        else if (i > 0 && i < n - 1) {
          if (sa[i - 1] == '1')
            c++, sa[i - 1] = '*';
          else if (sa[i + 1] == '1')
            c++, sa[i + 1] = '*';
        } else if (i > 0) {
          if (sa[i - 1] == '1') c++, sa[i - 1] = '*';
        } else if (i < n - 1) {
          if (sa[i + 1] == '1') c++, sa[i + 1] = '*';
        }
      }
    }
    cout << c << en;
  }
}
