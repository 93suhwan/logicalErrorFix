#include <bits/stdc++.h>
#pragma GCC optimize("O1")
#pragma GCC optimize("O2")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;
void input() { return; }
template <typename T1, typename... T2>
void input(T1 &x, T2 &...args) {
  ((cin >> x), input(args...));
}
void wrt() {
  cout << "\n";
  return;
}
template <typename T1, typename... T2>
void wrt(T1 x, T2... args) {
  ((cout << x << ' '), wrt(args...));
}
template <typename T>
void inputlst(T &lst, int x, int y) {
  for (int i = x; i < y; i++) cin >> lst[i];
}
template <typename T>
void printlst(T &lst, int x, int y) {
  for (int i = x; i < y; i++) cout << lst[i] << ' ';
  wrt();
}
const long long inf = INT64_MAX, MOD = 1e9 + 7, N = 10;
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ;
  int test;
  cin >> test;
  while (test--) {
    int n, k, ans;
    input(n, k);
    vector<int> lst(n + 1);
    inputlst(lst, 1, n + 1);
    vector<vector<int> > dp(n + 1, vector<int>(n + 1, 0));
    ans = n;
    for (long long move = 0; move < n + 1; ++move) {
      for (long long i = 1; i < n + 1; ++i) {
        dp[i][move] =
            max(dp[i][move], dp[i - 1][move] + (lst[i] == (i - move)));
        dp[i][move + 1] = max(dp[i - 1][move], dp[i][move + 1]);
        if (i == n) {
          if (dp[i][move] >= k) ans = min(ans, (int)move);
          if (dp[i][move + 1] >= k) ans = min(ans, (int)move + 1);
        }
      }
    }
    wrt(ans == n ? -1 : ans);
  }
  return 0;
}
