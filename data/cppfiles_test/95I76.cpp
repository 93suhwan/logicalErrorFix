#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
template <class T>
istream &operator>>(istream &cin, vector<T> &v) {
  for (auto &i : v) cin >> i;
  return cin;
}
template <class T>
ostream &operator<<(ostream &cout, vector<T> &v) {
  for (auto &i : v) cout << i << " ";
  return cout;
}
template <class T>
bool ckmin(T &a, const T &b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T &a, const T &b) {
  return a < b ? a = b, 1 : 0;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <class T, class V>
void __print(const pair<T, V> &x) {
  cerr << '{';
  __print(x.first);
  cerr << ", ";
  __print(x.second);
  cerr << '}';
}
template <class T>
void __print(const T &x) {
  long long f = 0;
  cerr << '{';
  for (auto &i : x) cerr << (f++ ? ", " : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <class T, class... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
const long long MOD = 1e9 + 7;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long T = 1;
  cin >> T;
  while (T--) {
    long long N, M;
    cin >> M >> N;
    vector<vector<long long>> a(M, vector<long long>(N));
    for (long long i = 0; i < M; i++)
      for (long long j = 0; j < N; j++) cin >> a[i][j];
    vector<long long> ord(M);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(),
         [&a](long long x, long long y) { return a[x][0] > a[y][0]; });
    vector<vector<long long>> mxl(M, vector<long long>(N, -MOD));
    vector<vector<long long>> mnr(M, vector<long long>(N, MOD));
    for (__typeof(0) i = (M) - ((M) > (0)); i != (0) - ((M) > (0));
         i += 1 - 2 * ((M) > (0)))
      for (__typeof(N) j = (0) - ((0) > (N)); j != (N) - ((0) > (N));
           j += 1 - 2 * ((0) > (N))) {
        mxl[i][j] = a[ord[i]][j];
        if (i < M - 1) mxl[i][j] = max(mxl[i][j], mxl[i + 1][j]);
        if (j > 0) mxl[i][j] = max(mxl[i][j], mxl[i][j - 1]);
      }
    for (__typeof(0) i = (M) - ((M) > (0)); i != (0) - ((M) > (0));
         i += 1 - 2 * ((M) > (0)))
      for (__typeof(0) j = (N) - ((N) > (0)); j != (0) - ((N) > (0));
           j += 1 - 2 * ((N) > (0))) {
        mnr[i][j] = a[ord[i]][j];
        if (i < M - 1) mnr[i][j] = max(mnr[i][j], mnr[i + 1][j]);
        if (j < N - 1) mnr[i][j] = max(mnr[i][j], mnr[i][j + 1]);
      }
    vector<long long> mnl(N, MOD), mxr(N, -MOD);
    pair<long long, long long> ans(-1, -1);
    for (__typeof(M - 1) i = (0) - ((0) > (M - 1));
         i != (M - 1) - ((0) > (M - 1)); i += 1 - 2 * ((0) > (M - 1))) {
      for (__typeof(N) j = (0) - ((0) > (N)); j != (N) - ((0) > (N));
           j += 1 - 2 * ((0) > (N))) {
        mnl[j] = min(mnl[j], a[ord[i]][j]);
        if (j > 0) mnl[j] = min(mnl[j], mnl[j - 1]);
      }
      for (__typeof(0) j = (N) - ((N) > (0)); j != (0) - ((N) > (0));
           j += 1 - 2 * ((N) > (0))) {
        mxr[j] = max(mxr[j], a[ord[i]][j]);
        if (j < N - 1) mxr[j] = max(mxr[j], mxr[j + 1]);
      }
      for (__typeof(N - 1) j = (0) - ((0) > (N - 1));
           j != (N - 1) - ((0) > (N - 1)); j += 1 - 2 * ((0) > (N - 1))) {
        if (mnl[j] > mxl[i + 1][j] and mxr[j + 1] < mnr[i + 1][j + 1])
          ans = {i, j};
      }
    }
    if (ans.first == -1) {
      cout << "NO" << '\n';
      continue;
    }
    cout << "YES" << '\n';
    string res(M, '.');
    for (__typeof(M) i = (0) - ((0) > (M)); i != (M) - ((0) > (M));
         i += 1 - 2 * ((0) > (M)))
      res[ord[i]] = i <= ans.first ? 'R' : 'B';
    cout << res << " " << ans.second + 1 << '\n';
  }
}
