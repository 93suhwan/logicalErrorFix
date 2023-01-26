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
const int MX = 2001;
const int CAP = 1e9 + 10;
int N, M;
vector<vector<int>> og;
int A[MX], B[MX];
bool proc[MX];
vector<vector<int>> graph;
int basePow;
int pa[MX];
int numZ[MX];
bool dfs(int v, int p, int curPow) {
  if (curPow <= A[v]) return false;
  if (pa[v] != -1 || numZ[v] >= 2) {
    int cur = v;
    while (cur > 0) {
      if (!proc[cur]) {
        proc[cur] = true;
        basePow += B[cur];
        ckmin(basePow, CAP);
        for (auto& a : graph[cur]) {
          if (a != 0 && numZ[a] == 0) {
            graph[0].push_back(a);
            graph[a].push_back(0);
          }
          if (a != 0) numZ[a]++;
        }
      }
      cur = pa[cur];
    }
    return true;
  }
  pa[v] = p;
  curPow += B[v];
  ckmin(curPow, CAP);
  for (auto& a : graph[v]) {
    if (a == p || (a > 0 && proc[a])) continue;
    if (dfs(a, v, curPow)) {
      if (!proc[v]) {
        proc[v] = true;
        basePow += B[v];
        ckmin(basePow, CAP);
        for (auto& b : graph[v]) {
          if (b != 0 && numZ[b] == 0) {
            graph[0].push_back(b);
            graph[b].push_back(0);
          }
          if (b != 0) numZ[b]++;
        }
      }
      return true;
    }
  }
  return false;
}
bool ok(int p) {
  basePow = p;
  for (int i = 0; i < (N); i++) proc[i] = false;
  proc[0] = true;
  graph = og;
  for (int i = 0; i < (N); i++) numZ[i] = 0;
  for (auto& a : graph[0]) numZ[a]++;
  while (true) {
    for (int i = 0; i < (N); i++) pa[i] = -1;
    if (!dfs(0, 0, basePow)) {
      return false;
    }
    bool done = true;
    for (int i = 0; i < (N); i++)
      if (!proc[i]) done = false;
    if (done) return true;
  }
}
void solve() {
  cin >> N >> M;
  og = vector<vector<int>>(N);
  for (int i = 0; i < (N - 1); i++) {
    cin >> A[i + 1];
  }
  for (int i = 0; i < (N - 1); i++) cin >> B[i + 1];
  for (int i = 0; i < (M); i++) {
    int X, Y;
    cin >> X >> Y;
    X--;
    Y--;
    og[X].push_back(Y);
    og[Y].push_back(X);
  }
  int lo = 0, hi = CAP;
  while (lo < hi) {
    int mid = (lo + hi) / 2;
    if (ok(mid)) {
      hi = mid;
    } else
      lo = mid + 1;
  }
  cout << lo << nl;
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
