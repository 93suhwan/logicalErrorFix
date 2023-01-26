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
const int MX = 200001;
int N, K;
string S;
string nxt;
int L[MX], R[MX];
bool dup[MX];
int P[MX];
string ans;
vector<int> ord;
void ordDfs(int v) {
  if (v == 0) return;
  ordDfs(L[v]);
  ord.push_back(v);
  ordDfs(R[v]);
}
void dfs(int v, int lstDup) {
  if (v == 0) return;
  P[L[v]] = v;
  P[R[v]] = v;
  dfs(L[v], lstDup + 1);
  if (!dup[v] && nxt[v] > S[v] && lstDup <= K) {
    int cv = v;
    K -= lstDup;
    while (lstDup) {
      dup[cv] = true;
      cv = P[cv];
      lstDup--;
    }
  }
  if (dup[v]) {
    lstDup = 0;
    dfs(R[v], lstDup + 1);
  }
}
void buildAns(int v) {
  if (v == 0) return;
  buildAns(L[v]);
  ans += S[v];
  if (dup[v]) ans += S[v];
  buildAns(R[v]);
}
void solve() {
  cin >> N >> K;
  cin >> S;
  S = " " + S;
  for (int i = 1; i < (N + 1); i++) cin >> L[i] >> R[i];
  for (int i = 0; i < (N + 1); i++) nxt += ' ';
  ordDfs(1);
  nxt[ord[N - 1]] = 'a' - 1;
  for (int i = (N - 1) - 1; i >= 0; i--) {
    if (S[ord[i]] == S[ord[i + 1]]) {
      nxt[ord[i]] = nxt[ord[i + 1]];
    } else
      nxt[ord[i]] = S[ord[i + 1]];
  }
  P[1] = -1;
  dfs(1, 1);
  buildAns(1);
  cout << ans << nl;
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int T = 1;
  while (T--) {
    solve();
  }
  return 0;
}
