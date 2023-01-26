#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
using namespace std;
const int maxn = 2000100;
const long long MOD = 1e9 + 7;
const int mod = 998244353;
const double eps = 1e-10;
const double pi = acos(-1.0);
int t;
template <typename T>
T gcd(T a, T b) {
  while (b ^= a ^= b ^= a %= b)
    ;
  return a;
}
template <typename T>
T lcm(T a, T b) {
  return a / gcd(a, b) * b;
}
template <typename T>
T ksm(T a, T b, T c) {
  T res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % c;
    a = a * a % c;
    b >>= 1;
  }
  return res % c;
}
template <typename T>
T Cnm(T n, T m) {
  T s = 1;
  if (n < m)
    s = 0;
  else if (n == m || m == 0)
    s = 1;
  else
    for (T i = 1; i <= m; i++) s = s * (n - i + 1) / i;
  return s;
}
template <typename t>
inline void read(t& x) {
  x = 0;
  char c = getchar();
  bool flag = false;
  while (!isdigit(c)) {
    if (c == '-') flag = true;
    c = getchar();
  }
  while (isdigit(c)) {
    x = (x << 1) + (x << 3) + (c ^ 48);
    c = getchar();
  }
  if (flag) x = -x;
}
template <class T>
void to_string(string& result, const T& t) {
  ostringstream oss;
  oss << t;
  result = oss.str();
}
template <class out_type, class in_value>
out_type convert(const in_value& t) {
  stringstream stream;
  stream << t;
  out_type result;
  stream >> result;
  return result;
}
template <typename T>
void sort(T a[], int n) {
  T temp;
  int i, j;
  for (i = 0; i < n - 1; i++) {
    for (j = 0; j < n - 1 - i; j++) {
      if (a[j] > a[j + 1]) {
        temp = a[j];
        a[j] = a[j + 1];
        a[j + 1] = temp;
      }
    }
  }
}
struct BigInteger {
  static const int BASE = 100000000;
  static const int WIDTH = 8;
  vector<int> s;
  BigInteger(long long num = 0) { *this = num; }
  BigInteger operator=(long long num) {
    s.clear();
    do {
      s.push_back(num % BASE);
      num /= BASE;
    } while (num > 0);
    return *this;
  }
  BigInteger operator=(const string& str) {
    s.clear();
    int x, len = (str.length() - 1) / WIDTH + 1;
    for (int i = 0; i < len; i++) {
      int end = str.length() - i * WIDTH;
      int start = max(0, end - WIDTH);
      sscanf(str.substr(start, end - start).c_str(), "%d", &x);
      s.push_back(x);
    }
    return *this;
  }
  BigInteger operator+(const BigInteger& b) const {
    BigInteger c;
    c.s.clear();
    for (int i = 0, g = 0;; i++) {
      if (g == 0 && i >= s.size() && i >= b.s.size()) break;
      int x = g;
      if (i < s.size()) x += s[i];
      if (i < b.s.size()) x += b.s[i];
      c.s.push_back(x % BASE);
      g = x / BASE;
    }
    return c;
  }
  BigInteger operator+=(const BigInteger& b) {
    *this = *this + b;
    return *this;
  }
  bool operator<(const BigInteger& b) const {
    if (s.size() != b.s.size()) return s.size() < b.s.size();
    for (int i = s.size() - 1; i >= 0; i--)
      if (s[i] != b.s[i]) return s[i] < b.s[i];
    return false;
  }
  bool operator>(const BigInteger& b) const { return b < *this; }
  bool operator>=(const BigInteger& b) const { return !(*this < b); }
  bool operator<=(const BigInteger& b) const { return !(b < *this); }
  bool operator!=(const BigInteger& b) const { return b < *this || *this < b; }
  bool operator==(const BigInteger& b) const {
    return !(b < *this) && !(*this < b);
  }
};
ostream& operator<<(ostream& out, const BigInteger& x) {
  out << x.s.back();
  for (int i = x.s.size() - 2; i >= 0; i--) {
    char buf[20];
    sprintf(buf, "%08d", x.s[i]);
    for (int j = 0; j < strlen(buf); j++) cout << buf[j];
  }
  return out;
}
istream& operator>>(istream& in, BigInteger& x) {
  string s;
  if (!(in >> s)) return in;
  x = s;
  return in;
}
long long fac[100500], num;
void fj(long long n) {
  long long cpy = n;
  for (long long i = 2; i * i <= n; ++i) {
    if (cpy % i == 0) {
      fac[++num] = i;
      while (cpy % i == 0) cpy /= i;
    }
  }
  if (cpy > 1) fac[++num] = cpy;
}
string u[17] = {"1",  "4",  "6",  "8",  "9",  "22", "25", "27", "32",
                "33", "35", "52", "55", "57", "72", "75", "77"};
void solve() {
  int n;
  string s;
  cin >> n >> s;
  for (int i = 0; i < 17; i++) {
    int l = 0;
    for (int j = 0; j < n; j++) {
      if (s[j] == u[i][l]) l++;
    }
    if (l == u[i].size()) {
      cout << l << '\n' << u[i] << '\n';
      return;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> t;
  while (t--) solve();
  return 0;
}
