#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using db = double;
using str = string;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<db, db>;
using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<ll>;
using vd = vector<db>;
using vs = vector<str>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using vpd = vector<pd>;
ll cdiv(ll a, ll b) { return a / b + ((a ^ b) > 0 && a % b); }
ll fdiv(ll a, ll b) { return a / b - ((a ^ b) < 0 && a % b); }
template <class T>
bool ckmin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}
template <class T>
void remDup(vector<T>& v) {
  sort(begin(v), end(v));
  v.erase(unique(begin(v), end(v)), v.end());
}
const int MOD = 998244353;
const int MX = 1e5 + 10;
const ll INF = 1e18;
struct mint {
  int v;
  explicit operator int() const { return v; }
  mint() { v = 0; }
  mint(ll _v) {
    v = int((-MOD < _v && _v < MOD) ? _v : _v % MOD);
    if (v < 0) v += MOD;
  }
  friend bool operator==(const mint& a, const mint& b) { return a.v == b.v; }
  friend bool operator!=(const mint& a, const mint& b) { return !(a == b); }
  friend bool operator<(const mint& a, const mint& b) { return a.v < b.v; }
  mint& operator+=(const mint& m) {
    if ((v += m.v) >= MOD) v -= MOD;
    return *this;
  }
  mint& operator-=(const mint& m) {
    if ((v -= m.v) < 0) v += MOD;
    return *this;
  }
  mint& operator*=(const mint& m) {
    v = int((ll)v * m.v % MOD);
    return *this;
  }
  mint& operator/=(const mint& m) { return (*this) *= inv(m); }
  friend mint pow(mint a, long long p) {
    mint ans = 1;
    for (; p; p /= 2, a *= a)
      if (p & 1) ans *= a;
    return ans;
  }
  friend mint inv(const mint& a) { return pow(a, MOD - 2); }
  mint operator-() const { return mint(-v); }
  mint& operator++() { return *this += 1; }
  mint& operator--() { return *this -= 1; }
  friend mint operator+(mint a, const mint& b) { return a += b; }
  friend mint operator-(mint a, const mint& b) { return a -= b; }
  friend mint operator*(mint a, const mint& b) { return a *= b; }
  friend mint operator/(mint a, const mint& b) { return a /= b; }
};
int T, N;
vi adj[MX];
mint DP[MX];
int cnt[MX], DIV;
bool bad;
void DFS(int X, int P) {
  if (bad) return;
  for (auto& Y : adj[X])
    if (Y != P) DFS(Y, X);
  if (cnt[X] % DIV != 0) {
    if (P != 0) cnt[X]++;
    if (cnt[X] % DIV != 0) {
      bad = true;
      return;
    }
  } else
    cnt[P]++;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> T;
  while (T--) {
    cin >> N;
    for (int i = (1); i < (N + 1); i++) adj[i].clear(), DP[i] = 0;
    for (int i = (0); i < (N - 1); i++) {
      int A, B;
      cin >> A >> B;
      adj[A].push_back(B), adj[B].push_back(A);
    }
    DP[1] = pow(mint(2), N - 1);
    for (int i = (2); i < (N + 1); i++)
      if ((N - 1) % i == 0) {
        bad = false;
        DIV = i;
        for (int j = (1); j < (N + 1); j++) cnt[j] = 0;
        DFS(1, 0);
        if (!bad) DP[i] = 1;
      }
    for (int i = (N + 1) - 1; i >= (1); i--)
      for (int j = 2 * i; j <= N; j += i) DP[i] -= DP[j];
    for (int i = (1); i < (N + 1); i++) cout << int(DP[i]) << " ";
    cout << "\n";
  }
}
