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
const int MX = 401;
int pre[MX][MX];
int get(int x, int y, int a, int b) {
  return pre[a + 1][b + 1] - pre[a + 1][y] - pre[x][b + 1] + pre[x][y];
}
void solve() {
  int N, M;
  cin >> N >> M;
  int A[N][M];
  for (int i = 0; i < (N); i++) {
    for (int j = 0; j < (M); j++) {
      char C;
      cin >> C;
      A[i][j] = C - '0';
    }
  }
  for (int i = 0; i < (N + 1); i++) {
    for (int j = 0; j < (M + 1); j++) {
      pre[i][j] = 0;
      if (i > 0 && j > 0) pre[i][j] = A[i - 1][j - 1];
      if (i > 0) {
        pre[i][j] += pre[i - 1][j];
        if (j > 0) {
          pre[i][j] -= pre[i - 1][j - 1];
        }
      }
      if (j > 0) pre[i][j] += pre[i][j - 1];
    }
  }
  int ans = 16;
  for (int x = 0; x < (N); x++) {
    for (int y = x + 4; y < (N); y++) {
      int best = 1000;
      for (int i = 3; i < (M); i++) {
        best += get(x + 1, i - 1, y - 1, i - 1);
        best += 1 - A[x][i - 1];
        best += 1 - A[y][i - 1];
        ckmin(best, (y - x - 1) - get(x + 1, i - 3, y - 1, i - 3) + 4 -
                        A[x][i - 1] - A[x][i - 2] - A[y][i - 1] - A[y][i - 2] +
                        get(x + 1, i - 2, y - 1, i - 1));
        ckmin(ans, best + (y - x - 1) - get(x + 1, i, y - 1, i));
      }
    }
  }
  cout << ans << nl;
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
