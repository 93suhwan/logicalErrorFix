#include <bits/stdc++.h>
using namespace std;
template <typename T1>
void dbg_pr(vector<T1> V, int add = 0, int start = -1, int end = -1) {
  cout << "{";
  if (start < 0) start = 0;
  if (end < 0) end = V.size() - 1;
  for (int i = start; i <= end; i++) {
    cout << V[i] + add << ((i == end) ? "}" : " ");
  }
}
void dbg_pr(string V) { cout << "\"" << V << "\""; }
template <typename T1>
void dbg_pr(T1 V) {
  cout << V;
}
template <typename T1, typename T2>
void dbg_pr(map<T1, T2> M) {
  cout << "{";
  for (const auto m : M) {
    dbg_pr(m.first);
    cout << ":";
    dbg_pr(m.second);
    cout << ",";
  }
  cout << "}";
}
void debug_out() { cout << "\033[0m\n"; }
template <typename T1, typename... T2>
void debug_out(T1 A, T2... B) {
  cout << " ";
  dbg_pr(A);
  debug_out(B...);
}
int test = 1;
void setupFastCin() {
  ios::sync_with_stdio(false);
  cin.tie(0);
}
template <typename T1>
T1 chmin(T1 &x, const T1 v) {
  return x = min(x, v);
}
template <typename T1>
T1 chmax(T1 &x, const T1 v) {
  return x = max(x, v);
}
template <typename T1>
void pr(vector<T1> V, int add = 0, int start = -1, int end = -1) {
  if (start < 0) start = 0;
  if (end < 0) end = V.size() - 1;
  for (int i = start; i <= end; i++) {
    cout << V[i] + add << ((i == end) ? "\n" : " ");
  }
}
template <typename T1>
T1 gcd(const T1 &a, const T1 &b) {
  if (a == 0 || b == 0) return a + b;
  return gcd(b, a % b);
}
int K;
string S;
long long DP[11][2000][2];
long long dp(int i, int mask, int k, int comp, long long p) {
  if (k > K) return LLONG_MAX;
  if (i == S.size()) {
    return 0;
  }
  if (DP[i][mask][comp] != -1) return DP[i][mask][comp];
  int md = S[i] - '0';
  long long sol = LLONG_MAX;
  for (int d = 0; d < 10; d++) {
    if (comp == 0 && d < md) continue;
    int newMask = mask;
    int newK = k;
    if ((mask & (1 << d)) == 0) {
      newMask += (1 << d);
      newK++;
    }
    if (newK > K) continue;
    int newC = comp;
    if (comp == 0) newC = d > md ? 1 : 0;
    long long s = dp(i + 1, newMask, newK, newC, p / 10);
    if (s == LLONG_MAX) continue;
    chmin(sol, d * p + s);
    break;
  }
  return DP[i][mask][comp] = sol;
}
void solve() {
  for (int i = 0; i < 11; i++)
    for (int j = 0; j < 1025; j++) DP[i][j][0] = DP[i][j][1] = -1;
  cin >> S >> K;
  long long p = pow(10ll, S.size() - 1);
  {
    cout << dp(0, 0, 0, 0, p) << "\n";
    return;
  };
}
int main() {
  setupFastCin();
  int T = 1;
  cin >> T;
  for (int t = 0; t < T; t++) {
    solve();
  }
  return 0;
}
