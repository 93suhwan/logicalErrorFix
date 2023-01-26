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
int N, K, ans = INF;
const int MAXN = 2001;
int memo[MAXN], history[MAXN];
vi nums;
void solve() {
  cin >> N >> K;
  nums = vi(N + 1, 0);
  for (int n = (1); n <= (N); ++n) cin >> nums[n];
  memset(memo, -1, sizeof memo);
  memset(history, -1, sizeof history);
  ans = INF;
  memo[0] = 0;
  for (int i = (1); i <= (N); ++i) {
    for (int j = (0); j < (i); ++j) {
      if (memo[j] == -1) continue;
      if (nums[j] < nums[i] && (nums[i] - nums[j] - 1 <= i - j - 1) &&
          memo[i] < memo[j] + 1) {
        memo[i] = memo[j] + 1;
        history[i] = j;
      }
    }
  }
  int ans = INF;
  vi deletion(N + 1, 0);
  for (int i = (1); i <= (N); ++i) {
    if (history[i] == -1) continue;
    int j = history[i];
    deletion[i] = deletion[j] + (i - j - 1) - (nums[i] - nums[j] - 1);
    if (memo[i] >= K) ans = min(ans, deletion[i]);
  }
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
