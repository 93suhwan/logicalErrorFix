#include <bits/stdc++.h>
using namespace std;
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
               __attribute__((unused)) long long idx,
               __attribute__((unused)) long long LINE_NUM) {
  cerr << '\n';
}
template <typename Head, typename... Tail>
void debug_out(vector<string> args, long long idx, long long LINE_NUM, Head H,
               Tail... T) {
  if (idx > 0)
    cerr << ", ";
  else
    cerr << "Line(" << LINE_NUM << ") ";
  stringstream ss;
  ss << H;
  cerr << args[idx] << " = " << ss.str();
  debug_out(args, idx + 1, LINE_NUM, T...);
}
void run() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
}
const long long N = 2e5 + 5, MOD = 1e9 + 7, mod2 = 998244353, MAXN = 1e6 + 29;
void files() {}
void solve() {
  long long n;
  cin >> n;
  for (long long i = 0; i < n; ++i) {
    cout << i + 2 << ' ';
  }
  cout << '\n';
}
signed main() {
  files();
  run();
  solve();
  return 0;
}
