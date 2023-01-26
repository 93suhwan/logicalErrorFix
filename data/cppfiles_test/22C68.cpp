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
int n, m;
pair<long long, long long> a[200007];
const int MAG = 450;
int f[200007];
int start[200007];
int chill(int ti, int k) {
  ti -= start[k];
  ti %= a[k].first + a[k].second;
  return ti >= a[k].first;
}
int suk[MAG][MAG];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  readArr(a, a + n);
  int bal = 0;
  for (int i = 0; i < m; ++i) {
    int op, k;
    cin >> op >> k;
    --k;
    bal += f[i];
    for (int j = 1; j < MAG; ++j) bal += suk[j][i % j];
    if (op == 1) start[k] = i;
    if (op == 2) {
      bal -= chill(i, k);
    }
    int heh = 1;
    if (op == 2) heh = -1;
    if (a[k].first + a[k].second < MAG) {
      int sh = a[k].first + a[k].second;
      int ost1 = (start[k] + a[k].first) % sh;
      int ost2 = (start[k]) % sh;
      suk[sh][ost1] += heh;
      suk[sh][ost2] -= heh;
    } else {
      long long v = start[k] + a[k].first;
      while (v < m) {
        f[v] += heh;
        if (v + a[k].second >= m) break;
        f[v + a[k].second] -= heh;
        v += a[k].first + a[k].second;
      }
    }
    cout << bal << "\n";
  }
}
