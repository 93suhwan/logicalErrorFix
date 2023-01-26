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
const int mod = 998244353;
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
const int N = 507;
int dp[N][N];
int C[N][N];
void init() {
  C[0][0] = 1;
  for (int i = 1; i < N; ++i) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; ++j) {
      C[i][j] = C[i - 1][j - 1];
      add(C[i][j], C[i - 1][j]);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  init();
  int n, first;
  cin >> n >> first;
  for (int i = 2; i <= n; ++i) {
    for (int j = 1; j <= first; ++j) {
      int damage = (i - 1);
      add(dp[i][j], bp(min(j, damage), i));
      int now = damage;
      if (j > damage) {
        add(dp[i][j], dp[i][j - damage]);
        for (int killed = 1; killed < i - 1; ++killed) {
          add(dp[i][j],
              mult(dp[i - killed][j - damage], mult(C[i][killed], now)));
          now = mult(now, damage);
        }
      }
    }
  }
  cout << dp[n][first] << "\n";
}
