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
void solve() {
  int n, a, b;
  cin >> n >> a >> b;
  if (a + b > n - 2 || abs(a - b) > 1) {
    cout << "-1\n";
    return;
  }
  int l = 0, r = n - 1;
  bool now = (b > a);
  vector<int> res;
  while (a || b) {
    if (now) {
      res.push_back(r--);
      if (res.size() >= 2) {
        --a;
      }
    } else {
      res.push_back(l++);
      if (res.size() >= 2) {
        --b;
      }
    }
    now ^= 1;
  }
  assert(l <= r);
  if (!res.size() || res.back() == l - 1) {
    for (int first = l; first <= r; ++first) {
      res.push_back(first);
    }
  } else {
    for (int first = r; first >= l; --first) {
      res.push_back(first);
    }
  }
  for (int first : res) {
    cout << first + 1 << " ";
  }
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    solve();
  }
}
