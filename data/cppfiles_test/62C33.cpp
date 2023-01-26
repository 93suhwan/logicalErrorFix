#include <bits/stdc++.h>
using namespace std;
template <class T>
istream &operator>>(istream &in, pair<T, T> &p) {
  in >> p.first >> p.second;
  return in;
}
template <class T>
ostream &operator<<(ostream &out, pair<T, T> &p) {
  out << p.first << ' ' << p.second;
  return out;
}
template <class Tuple, std::size_t N>
struct TuplePrinter {
  static void print(ostream &out, const Tuple &t) {
    TuplePrinter<Tuple, N - 1>::print(out, t);
    out << ' ' << get<N - 1>(t);
  }
};
template <class Tuple>
struct TuplePrinter<Tuple, 1> {
  static void print(ostream &out, const Tuple &t) { out << get<0>(t); }
};
template <class... Args>
ostream &operator<<(ostream &out, const tuple<Args...> &p) {
  TuplePrinter<decltype(p), sizeof...(Args)>::print(out, p);
  return out;
}
long long N, M, K;
long long active[1005][1005];
long long dp[1005][1005][5];
long long ans = 0;
void setVal(long long r, long long c, long long last, long long val) {
  ans -= dp[r][c][last];
  dp[r][c][last] = val;
  ans += dp[r][c][last];
}
void prepare() {
  for (long long i = 1; i <= N; i++) {
    for (long long j = 1; j <= M; j++) {
      active[i][j] = 1;
      setVal(i, j, 0, dp[i][j - 1][1] + 1);
      setVal(i, j, 1, dp[i - 1][j][0] + 1);
    }
  }
  ans -= N * M;
}
void disable(long long r, long long c, long long last) {
  setVal(r, c, last, 0);
  active[r][c] = 0;
  while (r <= N && c <= M) {
    if (last == 0)
      r++;
    else
      c++;
    last ^= 1;
    if (active[r][c]) {
      if (last == 0)
        setVal(r, c, last, dp[r][c - 1][!last] + 1);
      else
        setVal(r, c, last, dp[r - 1][c][!last] + 1);
    } else
      break;
  }
}
void enable(long long r, long long c, long long last) {
  setVal(r, c, 0, dp[r][c - 1][1] + 1);
  setVal(r, c, 1, dp[r - 1][c][0] + 1);
  active[r][c] = 1;
  while (r <= N && c <= M) {
    if (last == 0)
      r++;
    else
      c++;
    last ^= 1;
    if (active[r][c])
      if (last == 0)
        setVal(r, c, last, dp[r][c - 1][!last] + 1);
      else
        setVal(r, c, last, dp[r - 1][c][!last] + 1);
    else
      break;
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin >> N >> M >> K;
  prepare();
  long long r, c;
  while (K--) {
    cin >> r >> c;
    if (active[r][c]) {
      disable(r, c, 1);
      disable(r, c, 0);
      ans++;
      cout << ans << "\n";
    } else {
      enable(r, c, 1);
      enable(r, c, 0);
      ans--;
      cout << ans << "\n";
    }
  }
}
