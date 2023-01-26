#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
using namespace std;
template <typename T>
void etch(T V) {
  for (auto x : V) cout << x << ' ';
  cout << '\n';
}
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
               __attribute__((unused)) long long int idx,
               __attribute__((unused)) long long int LINE_NUM) {
  cerr << endl;
}
template <typename Head, typename... Tail>
void debug_out(vector<string> args, long long int idx, long long int LINE_NUM,
               Head H, Tail... T) {
  if (idx > 0)
    cerr << ", ";
  else
    cerr << "Line(" << LINE_NUM << ") ";
  stringstream ss;
  ss << H;
  cerr << args[idx] << " = " << ss.str();
  debug_out(args, idx + 1, LINE_NUM, T...);
}
const long long int MOD = 1e9 + 7;
const long long int MOD1 = 998244353;
const long long int N = 2e5 + 5;
const long long int INF = 1000111000111000111LL;
const long double EPS = 1e-12;
const long double PI = 3.141592653589793116;
void solve() {
  long long int n;
  cin >> n;
  vector<long long int> g[n];
  vector<long long int> ind(n, 0), dp(n, 0), vis(n, 0);
  for (long long int i = (0); i < (n); i++) {
    long long int k;
    cin >> k;
    ind[i] = 0;
    for (long long int j = (0); j < (k); j++) {
      long long int x;
      cin >> x;
      x--;
      g[x].push_back(i);
      ind[i]++;
    }
  }
  queue<long long int> Q;
  for (long long int i = (0); i < (n); i++) {
    if (ind[i] == 0) {
      Q.push(i);
      vis[i] = 1;
    }
  }
  while (not Q.empty()) {
    long long int node = Q.front();
    Q.pop();
    for (auto it : g[node]) {
      ind[it]--;
      if (node < it) {
        dp[it] = max(dp[it], dp[node]);
      } else {
        dp[it] = max(dp[it], dp[node] + 1);
      }
      if (ind[it] == 0) {
        Q.push(it);
        vis[it] = 1;
      }
    }
  }
  if (*min_element((vis).begin(), (vis).end()) != 1) {
    cout << "-1\n";
    return;
  }
  cout << *max_element((dp).begin(), (dp).end()) + 1 << '\n';
}
int32_t main() {
  std::ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
