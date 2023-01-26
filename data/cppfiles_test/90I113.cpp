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
const int MX = 100001;
void solve() {
  int N, M;
  cin >> N >> M;
  vector<long long> A(N);
  for (int i = 0; i < (N); i++) cin >> A[i];
  sort(A.begin(), A.end());
  vector<pair<long long, long long>> segs[N + 1];
  for (int i = 0; i < (M); i++) {
    long long L, R;
    cin >> L >> R;
    int p = upper_bound(A.begin(), A.end(), L) - A.begin();
    if (p == N || R < A[p]) {
      segs[p].push_back({L, R});
    }
  }
  long long dp[N][2];
  for (int i = 0; i < (N); i++)
    for (int j = 0; j < (2); j++) dp[i][j] = 1e18;
  long long loF = 2e9;
  for (auto& a : segs[0]) ckmin(loF, a.second);
  long long dF = max(0ll, A[0] - loF);
  dp[0][0] = dF;
  dp[0][1] = dF * 2;
  for (int i = 1; i < (N); i++) {
    if ((int)(segs[i]).size() == 0) {
      dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]);
      dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]);
      continue;
    }
    sort(segs[i].begin(), segs[i].end());
    long long lo = 2e9;
    for (int x = ((int)(segs[i]).size()) - 1; x >= 0; x--) {
      ckmin(lo, segs[i][x].second);
      long long d1 = 0;
      if (x > 0) d1 = segs[i][x - 1].first - A[i - 1];
      long long d2 = A[i] - lo;
      for (int j = 0; j < (2); j++) {
        for (int k = 0; k < (2); k++) {
          ckmin(dp[i][j], dp[i - 1][k] + d1 * (2 - k) + d2 * (j + 1));
        }
      }
    }
  }
  long long hiF = -2e9;
  for (auto& a : segs[N]) ckmax(hiF, a.first);
  long long dE = max(0ll, hiF - A[N - 1]);
  for (int i = 0; i < (2); i++) {
    dp[N - 1][i] += dE * (2 - i);
  }
  cout << min(dp[N - 1][0], dp[N - 1][1]) << nl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
