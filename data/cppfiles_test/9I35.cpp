#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,O2,O3,unroll-loops")
#pragma GCC target("avx2")
using namespace std;
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << "[" << H << "]";
  debug_out(T...);
}
clock_t startTime;
double getCurrentTime() {
  return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
const double eps = 0.000001;
const int MOD = 998244353;
const int INF = 1000000101;
const long long LLINF = 1223372000000000555;
const int N = 2e6 + 3e2;
const int M = 5222;
int n, m;
int a[M][M], cnt[M][M];
int ans[M][M];
int calc(int x, int y) {
  if (x > n) return y;
  cnt[x][y]++;
  if (cnt[x][y] >= 5) return ans[x][y];
  int t = a[x][y];
  a[x][y] = 2;
  if (t == 1) ans[x][y] = calc(x, y + 1);
  if (t == 2) ans[x][y] = calc(x + 1, y);
  if (t == 3) ans[x][y] = calc(x, y - 1);
  return ans[x][y];
}
void solve(int TC) {
  int k;
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 1; i <= k; i++) {
    int j;
    cin >> j;
    cout << calc(1, j) << ' ';
  }
}
int main() {
  startTime = clock();
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int TC = 1;
  for (int test = 1; test <= TC; test++) {
    solve(test);
  }
  cerr << endl << "Time: " << int(getCurrentTime() * 1000) << " ms" << endl;
  return 0;
}
