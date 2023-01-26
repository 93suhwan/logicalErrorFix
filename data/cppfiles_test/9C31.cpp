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
int a[M][M];
int nxt[M][M];
void solve(int TC) {
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 1; i <= k; i++) {
    int x = 1, y;
    cin >> y;
    while (x <= n) {
      if (a[x][y] == 2) {
        x++;
        continue;
      }
      if (a[x][y] == 1) {
        int j = y;
        while (a[x][j] == 1) {
          a[x][j] = 2;
          j++;
        }
        if (a[x][j] == 3)
          y = j - 1;
        else
          y = j;
        a[x][j] = 2;
        x++;
        continue;
      }
      if (a[x][y] == 3) {
        int j = y;
        while (a[x][j] == 3) {
          a[x][j] = 2;
          j--;
        }
        if (a[x][j] == 1)
          y = j + 1;
        else
          y = j;
        a[x][j] = 2;
        x++;
      }
    }
    cout << y << ' ';
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
