#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vb = vector<bool>;
using vs = vector<string>;
using vc = vector<char>;
using vd = vector<double>;
using pii = pair<int, int>;
using pss = pair<string, string>;
using ll = long long;
using tup = tuple<ll, int, int>;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
template <typename Os, class V>
Os& operator<<(Os& os, V const& v) {
  for (auto const& e : v) os << e << " ";
  return os;
}
vi diff;
int N, K, ans = INF;
const int MAXN = 2001;
pii memo[2001][2001];
pii dp(int i, int th, int have, int moves) {
  if (i > N) return {0, 0};
  pii& ret = memo[i][th];
  if (ret.first != -1) return ret;
  if (diff[i] == th) {
    pii p = dp(i + 1, th, have + 1, moves);
    ret = {p.first + 1, p.second};
  } else {
    pii p1 = dp(i + 1, th + 1, have, moves + 1);
    pii p2 = dp(i + 1, th, have, moves);
    if (p1.first <= p2.first)
      ret = p2;
    else
      ret = {p1.first, p1.second + 1};
  }
  if (ret.first + have >= K) ans = min(ans, ret.second + moves);
  return ret;
}
void solve() {
  cin >> N >> K;
  diff = vi(N + 1, 0);
  int tmp;
  for (int idx = (1); idx <= (N); ++idx) {
    cin >> tmp;
    diff[idx] = idx - tmp;
  }
  const pii INIT = {-1, -1};
  fill_n(&memo[0][0], MAXN * MAXN, INIT);
  ans = INF;
  dp(1, 0, 0, 0);
  cout << (ans == INF ? -1 : ans) << "\n";
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int T;
  cin >> T;
  for (int TC = (0); TC < (T); ++TC) {
    solve();
  }
}
