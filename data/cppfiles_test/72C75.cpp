#include <bits/stdc++.h>
using namespace std;
void per() { cerr << endl; }
template <typename Head, typename... Tail>
void per(Head H, Tail... T) {
  cerr << H << ' ';
  per(T...);
}
template <class T>
bool uin(T& a, T b) {
  return a > b ? (a = b, true) : false;
}
template <class T>
bool uax(T& a, T b) {
  return a < b ? (a = b, true) : false;
}
template <class U, class V>
ostream& operator<<(ostream& out, const pair<U, V>& a) {
  return out << "(" << a.first << ", " << a.second << ")";
}
template <class U, class V>
istream& operator>>(istream& in, pair<U, V>& a) {
  return in >> a.first >> a.second;
}
template <typename W,
          typename T = typename enable_if<!is_same<W, string>::value,
                                          typename W::value_type>::type>
ostream& operator<<(ostream& out, const W& v) {
  out << "{ ";
  for (const auto& first : v) out << first << ", ";
  return out << '}';
}
template <class T>
void readArr(T from, T to) {
  for (auto i = from; i != to; ++i) cin >> *i;
}
mt19937 mrand(1337);
unsigned int myRand32() { return mrand() & (unsigned int)(-1); }
unsigned long long myRand64() {
  return ((unsigned long long)myRand32() << 32) ^ myRand32();
}
const int mod = 1000000007;
void add(int& a, int b) {
  a += b;
  if (a >= mod) a -= mod;
}
void dec(int& a, int b) {
  a -= b;
  if (a < 0) a += mod;
}
int mult(int a, int b) { return a * (long long)b % mod; }
int bp(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) res = mult(res, a);
    a = mult(a, a);
    b >>= 1;
  }
  return res;
}
int main() {
  int vl = 1, vr = 1000000000;
  cout << "? 1 1" << endl;
  int base1;
  cin >> base1;
  while (vl + 1 < vr) {
    int vm = (vl + vr) >> 1;
    cout << "? 1 " << vm << endl;
    int first;
    cin >> first;
    if (first == base1 - (vm - 1))
      vl = vm;
    else
      vr = vm;
  }
  int y1 = vl;
  int x1 = base1 - (y1 - 1) + 1;
  cout << "? 1000000000 1" << endl;
  int base2;
  cin >> base2;
  int x2 = 1000000000 - (base2 - (y1 - 1));
  cout << "? 1 1000000000" << endl;
  int base3;
  cin >> base3;
  int y2 = 1000000000 - (base3 - (x1 - 1));
  cout << "! " << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;
}
