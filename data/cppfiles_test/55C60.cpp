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
const long long SZ = 131072 * 8;
pair<int, int> sum[2 * SZ], lazy[2 * SZ];
pair<int, int> combine(pair<int, int> A, pair<int, int> B) { return max(A, B); }
pair<int, int> combineUpd(pair<int, int> A, pair<int, int> B) {
  return max(A, B);
}
void push(int index, long long L, long long R) {
  sum[index] = combineUpd(sum[index], lazy[index]);
  if (L != R)
    lazy[2 * index] = combineUpd(lazy[2 * index], lazy[index]),
             lazy[2 * index + 1] = combineUpd(lazy[2 * index + 1], lazy[index]);
  lazy[index] = {0, -1};
}
void pull(int index) {
  sum[index] = combine(sum[2 * index], sum[2 * index + 1]);
}
pair<int, int> query(int lo, int hi, int index = 1, long long L = 0,
                     long long R = SZ - 1) {
  push(index, L, R);
  if (lo > R || L > hi) return {0, -1};
  if (lo <= L && R <= hi) return sum[index];
  int M = (L + R) / 2;
  return combine(query(lo, hi, 2 * index, L, M),
                 query(lo, hi, 2 * index + 1, M + 1, R));
}
void update(int lo, int hi, pair<int, int> increase, int index = 1,
            long long L = 0, long long R = SZ - 1) {
  push(index, L, R);
  if (hi < L || R < lo) return;
  if (lo <= L && R <= hi) {
    lazy[index] = increase;
    push(index, L, R);
    return;
  }
  int M = (L + R) / 2;
  update(lo, hi, increase, 2 * index, L, M);
  update(lo, hi, increase, 2 * index + 1, M + 1, R);
  pull(index);
}
void solve() {
  for (int i = 0; i < (2 * SZ); i++) {
    sum[i] = {0, -1};
    lazy[i] = {0, -1};
  }
  int N, M;
  cin >> N >> M;
  vector<vector<pair<int, int>>> A(N + 1);
  for (int i = 0; i < (M); i++) {
    int X, Y, Z;
    cin >> X >> Y >> Z;
    A[X - 1].push_back({Y, Z});
  }
  set<int> vals;
  for (int i = 0; i < (N); i++) {
    for (auto& a : A[i]) {
      vals.insert(a.first);
      vals.insert(a.second);
    }
  }
  map<int, int> comp;
  for (auto& a : vals) comp[a] = (int)(comp).size();
  for (int i = 0; i < (N); i++) {
    for (auto& a : A[i]) {
      a.second = comp[a.second];
      a.first = comp[a.first];
    }
  }
  A[N].push_back({0, (int)(comp).size() - 1});
  pair<int, int> dp[N + 1];
  for (int i = 0; i < (N + 1); i++) {
    pair<int, int> best = {0, -1};
    for (auto& a : A[i]) {
      ckmax(best, query(a.first, a.second));
    }
    best.first++;
    dp[i] = best;
    best.second = i;
    for (auto& a : A[i]) {
      update(a.first, a.second, best);
    }
  }
  cout << N + 1 - dp[N].first << nl;
  int cur = N;
  while (cur >= 0) {
    int nxt = dp[cur].second;
    for (int i = nxt + 1; i < (cur); i++) {
      cout << i + 1 << " ";
    }
    cur = nxt;
  }
  cout << nl;
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
