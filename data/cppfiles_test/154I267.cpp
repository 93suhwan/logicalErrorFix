#include <bits/stdc++.h>
using namespace std;
template <class T>
using vc = vector<T>;
template <typename T1, typename T2>
pair<T1, T2>& operator+=(pair<T1, T2>& p1, const pair<T1, T2>& p2) {
  p1.first += p2.first, p1.second += p2.second;
  return p1;
}
template <typename T1, typename T2>
pair<T1, T2>& operator-=(pair<T1, T2>& p1, const pair<T1, T2>& p2) {
  p1.first -= p2.first, p1.second -= p2.second;
  return p1;
}
template <typename T1, typename T2>
pair<T1, T2> operator+(pair<T1, T2> p1, const pair<T1, T2>& p2) {
  return p1 += p2;
}
template <typename T1, typename T2>
pair<T1, T2> operator-(pair<T1, T2> p1, const pair<T1, T2>& p2) {
  return p1 -= p2;
}
template <typename T>
T operator*(const pair<T, T>& p1, const pair<T, T>& p2) {
  return p1.first * p2.first + p1.second * p2.second;
}
template <typename T>
T operator^(const pair<T, T>& p1, const pair<T, T>& p2) {
  return p1.first * p2.second - p2.first * p1.second;
}
template <typename T>
pair<T, T>& operator*=(pair<T, T>& p1, const T& p2) {
  p1.first *= p2;
  p1.second *= p2;
  return p1;
}
template <typename T>
pair<T, T> operator*(pair<T, T> p1, const T& p2) {
  return p1 *= p2;
}
template <typename T1, typename T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& p) {
  return os << p.first << ' ' << p.second;
}
template <typename T1, typename T2>
istream& operator>>(istream& is, pair<T1, T2>& p) {
  is >> p.first >> p.second;
  return is;
}
template <typename T>
ostream& operator<<(ostream& os, const vc<T>& p) {
  for (auto& v : p) os << (v) << ' ';
  return os;
}
template <typename T>
istream& operator>>(istream& is, vc<T>& p) {
  for (auto& v : p) is >> v;
  return is;
}
template <typename T>
ostream& operator<<(ostream& os, const vc<vc<T>>& p) {
  for (auto& v : p) os << v << '\n';
  return os;
}
template <typename T1, typename T2>
ostream& operator<<(ostream& os, const map<T1, T2>& p) {
  for (auto& v : p)
    os << '\n' << setw(15) << v.first << " : " << v.second << ' ';
  return os;
}
template <typename T>
vc<T>& operator+=(vc<T>& p, const vc<T>& b) {
  for (auto& v : b) p.emplace_back(v);
  return p;
}
template <typename T>
vc<T> operator+(vc<T> p, const vc<T>& b) {
  return p += b;
}
template <typename T>
vc<T>& operator+=(vc<T>& p, const T& b) {
  for (auto& v : p) v += b;
  return p;
}
long long gcd(long long p, long long b) { return b ? gcd(b, p % b) : p; }
long long lcd(long long p, long long b) { return p * b / gcd(p, b); }
long long qmi(long long a, long long b, long long p) {
  long long res = 1;
  while (b) {
    if (b & 1) {
      res = (res * a) % p;
      b >>= 1;
    }
    a = (a * a) % p;
  }
  return res;
}
void dbg_out() { cerr << "\b\b )" << '\n'; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cerr << H << ", ";
  dbg_out(T...);
}
const int P = 13331;
const double eps = 1e-10;
const int N = 2e5 + 10, M = 2 * N, MOD = 1e9 + 7, INF = 0x3f3f3f3f,
          mod = 998244353;
long long n, m, k;
void solve(int caseT) {
  int a[3];
  int b = 0, c = 0;
  for (int i = 0; i < 3; i++) {
    cin >> a[i];
    if (a[i] & 1)
      b++;
    else
      c++;
  }
  if (a[0] == a[1] == a[2]) {
    cout << "YES" << '\n';
    return;
  }
  if (b == 2 && c == 1)
    cout << "YES" << '\n';
  else if (c == 3)
    cout << "YES" << '\n';
  else
    cout << "NO" << '\n';
}
void init() {}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  init();
  int T;
  T = 1;
  cin >> T;
  for (int i = 1; i <= T; i++) solve(i);
  return 0;
}
