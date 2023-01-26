#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
using namespace std;
template <class T>
using pq = priority_queue<T>;
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;
template <class T>
bool ckmin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char* x) { cerr << '\"' << x << '\"'; }
void __print(const string& x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V>& x) {
  cerr << '{';
  __print(x.first);
  cerr << ", ";
  __print(x.second);
  cerr << '}';
}
template <typename T>
void __print(const T& x) {
  int first = 0;
  cerr << '{';
  for (auto& i : x) cerr << (first++ ? ", " : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
const int MOD = 1000000007;
const char nl = '\n';
const int MX = 200011;
const int K = 580;
int par[MX];
int nc[MX];
int dp[MX][K];
int cdp[MX];
int dep[MX];
vector<vector<int>> graph(MX);
vector<int> atNC[MX];
void dfs(int v, int p) {
  par[v] = p;
  if (p < 0) {
    dep[v] = 0;
  } else
    dep[v] = dep[p] + 1;
  for (auto& a : graph[v]) {
    if (a == p) continue;
    dfs(a, v);
    for (int i = 1; i < (K); i++) {
      dp[v][i] += max(1, dp[a][i] - i + 1);
    }
    nc[v]++;
  }
}
void solve() {
  int N;
  cin >> N;
  for (int i = 0; i < (N - 1); i++) {
    int X, Y;
    cin >> X >> Y;
    X--;
    Y--;
    graph[X].push_back(Y);
    graph[Y].push_back(X);
  }
  dfs(0, -1);
  for (int i = 0; i < (N); i++) atNC[nc[i]].push_back(i);
  int Q;
  cin >> Q;
  int ans[Q];
  vector<vector<pair<int, int>>> atK(MX);
  for (int i = 0; i < (Q); i++) {
    int X, Y;
    cin >> X >> Y;
    X--;
    Y++;
    atK[Y].push_back(make_pair(X, i));
  }
  for (int i = 1; i < (K); i++) {
    for (auto& a : atK[i]) {
      ans[a.second] = dp[a.first][i];
    }
  }
  set<int> incVerts;
  for (int i = (MX)-1; i >= K; i--) {
    for (auto& a : atNC[i]) {
      incVerts.insert({dep[a], a});
    }
    if ((int)(atK[i]).size() == 0) {
      continue;
    }
    pq<pair<int, int>> q;
    for (auto& a : incVerts) q.push({dep[a], a});
    vector<int> used;
    while (!q.empty()) {
      int cur = q.top().second;
      q.pop();
      if (cur == 0) continue;
      if (cdp[cur] == 0) cdp[cur] = nc[cur];
      if (cdp[par[cur]] == 0) cdp[par[cur]] = nc[par[cur]];
      used.push_back(cur);
      used.push_back(par[cur]);
      cdp[par[cur]] += max(0, cdp[cur] - i);
      if (cdp[cur] - i - 1 > 0) {
        q.push({dep[par[cur]], par[cur]});
      }
    }
    for (auto& a : atK[i]) {
      ans[a.second] = nc[a.first];
      for (auto& b : used) {
        if (b == a.first) {
          ans[a.second] = cdp[a.first];
        }
      }
    }
    for (auto& a : used) cdp[a] = 0;
  }
  for (int i = 0; i < (Q); i++) {
    cout << ans[i] << nl;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int T = 1;
  while (T--) {
    solve();
  }
  return 0;
}
