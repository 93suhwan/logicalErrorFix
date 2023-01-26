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
const int N = 14;
int dp[1 << N];
int pp[N][N];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> v(n);
  for (auto& first : v) cin >> first;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      pp[i][j] = mult(v[i], bp(v[i] + v[j], mod - 2));
    }
  }
  int ans = 0;
  for (int mask = 1; mask < (1 << n); ++mask) {
    int p = 1;
    vector<int> a, b;
    for (int i = 0; i < n; ++i) {
      if ((1 << i) & mask)
        a.push_back(i);
      else
        b.push_back(i);
    }
    for (auto first : a)
      for (auto second : b) p = mult(p, pp[first][second]);
    for (int s = mask; s; s = (s - 1) & mask) {
      if (s == mask) continue;
      int t = dp[mask ^ s];
      vector<int> c;
      for (int i = 0; i < n; ++i) {
        if ((1 << i) & s) c.push_back(i);
      }
      for (auto first : c)
        for (auto second : b) t = mult(t, pp[first][second]);
      dec(p, t);
    }
    dp[mask] = p;
    add(ans, mult(p, __builtin_popcount(mask)));
  }
  cout << ans;
}
