#include <bits/stdc++.h>
using namespace std;
struct custHash {
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
vector<string> vec_splitter(string s) {
  s += ',';
  vector<string> res;
  while (!s.empty()) {
    res.push_back(s.substr(0, s.find(',')));
    s = s.substr(s.find(',') + 1);
  }
  return res;
}
void debug_out(vector<string> __attribute__((unused)) args,
               __attribute__((unused)) int idx,
               __attribute__((unused)) int LINE_NUM) {
  cerr << endl;
}
template <typename Head, typename... Tail>
void debug_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T) {
  if (idx > 0)
    cerr << ", ";
  else
    cerr << "Line(" << LINE_NUM << ") ";
  stringstream ss;
  ss << H;
  cerr << args[idx] << " = " << ss.str();
  debug_out(args, idx + 1, LINE_NUM, T...);
}
int n;
int a[100005];
long long dp[2][100005];
void solve() {
  cin >> n;
  for (int i = 0, _i = (n); i < _i; ++i) cin >> a[i];
  vector<int> vt[2];
  dp[(n - 1) & 1][a[n - 1]] = 1;
  vt[(n - 1) & 1] = {a[n - 1]};
  long long res = 0;
  for (int i = (n - 1) - 1; i >= 0; --i) {
    int cur = i & 1;
    int prv = 1 - cur;
    vt[cur] = {a[i]};
    dp[cur][a[i]] = 1;
    for (int x : vt[prv]) {
      long long cnt = dp[prv][x];
      long long nsplit = (a[i] - 1) / x + 1;
      long long target = a[i] / nsplit;
      res += cnt * (nsplit - 1) % 998244353 * (i + 1) % 998244353;
      res %= 998244353;
      dp[cur][target] += cnt;
      if (target != vt[cur].back()) vt[cur].push_back(target);
      dp[prv][x] = 0;
    }
    vt[prv].clear();
  }
  cout << res << '\n';
}
int ntest;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> ntest;
  for (int t = 0, _t = (ntest); t < _t; ++t) {
    solve();
  }
  return 0;
}
