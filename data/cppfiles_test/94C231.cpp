#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B, typename C>
struct triple {
  A X;
  B Y;
  C Z;
  triple(A a = 0, B b = 0, C c = 0) : X(a), Y(b), Z(c) {}
};
template <typename A, typename B, typename C>
triple<A, B, C> make_triple(A a = 0, B b = 0, C c = 0) {
  return triple<A, B, C>(a, b, c);
}
template <typename A, typename B, typename C>
bool operator<(const triple<A, B, C>& a, const triple<A, B, C>& b) {
  if (a.X != b.X) return a.X < b.X;
  if (a.Y != b.Y) return a.Y < b.Y;
  return a.Z < b.Z;
}
template <typename T, typename SS>
ostream& operator<<(ostream& ofs, const pair<T, SS>& p) {
  ofs << "( " << p.first << " , " << p.second << " )";
  return ofs;
}
template <typename T>
void print(T a) {
  for (auto i : a) cout << i << ' ';
  cout << '\n';
}
template <typename T>
T max(T a, T b, T c) {
  return max(a, max(b, c));
}
template <typename T>
T min(T a, T b, T c) {
  return min(a, min(b, c));
}
template <typename T, typename D>
D min(T a) {
  return *min_element(a.begin(), a.end());
}
template <typename T, typename D>
D max(T a) {
  return *max_element(a.begin(), a.end());
}
struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
void solve() {
  string s;
  cin >> s;
  if ((long long)(s.size()) & 1) s = "0" + s;
  long long n = (long long)(s.size());
  for (long long i = 0; i < (n); i++) s[i] -= '0';
  reverse(s.begin(), s.end());
  vector<vector<long long> > dp(n / 2 + 1, vector<long long>(4));
  dp[0][0] = 1;
  for (long long i = 0; i < (n / 2); i++)
    for (long long j = 0; j < (4); j++) {
      long long x = 2 * i, y = x + 1;
      long long dx = j & 1, dy = j >> 1;
      for (long long d11 = 0; d11 < (10); d11++)
        for (long long d12 = 0; d12 < (10); d12++) {
          long long sx = d11 + d12 + dx;
          if (sx % 10 != s[x]) continue;
          long long nmask = (sx >= 10);
          for (long long d21 = 0; d21 < (10); d21++)
            for (long long d22 = 0; d22 < (10); d22++) {
              long long sy = d21 + d22 + dy;
              if (sy % 10 != s[y]) continue;
              if (sy >= 10) nmask |= 2;
              dp[i + 1][nmask] += dp[i][j];
            }
        }
    }
  cout << dp[n / 2][0] - 2 << '\n';
};
signed main() {
  if (0) {
    freopen(
        "a"
        ".in",
        "r", stdin);
    freopen(
        "a"
        ".out",
        "w", stdout);
  }
  srand(time(NULL));
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);
  long long t = 1;
  cin >> t;
  for (long long _ = 0; _ < (t); _++) solve();
}
