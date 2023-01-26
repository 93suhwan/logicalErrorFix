#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
template <typename T>
void ckmn(T& a, T b) {
  a = min(a, b);
}
template <typename T>
void ckmx(T& a, T b) {
  a = max(a, b);
}
void rd(int& x) { scanf("%i", &x); }
void rd(long long& x) { scanf("%lld", &x); }
void rd(char* x) { scanf("%s", x); }
void rd(double& x) { scanf("%lf", &x); }
void rd(string& x) { scanf("%s", &x); }
template <typename T1, typename T2>
void rd(pair<T1, T2>& x) {
  rd(x.first);
  rd(x.second);
}
template <typename T>
void rd(vector<T>& x) {
  for (T& i : x) rd(i);
}
template <typename T, typename... A>
void rd(T& x, A&... args) {
  rd(x);
  rd(args...);
}
template <typename T>
void rd() {
  T x;
  rd(x);
  return x;
}
int ri() {
  int x;
  rd(x);
  return x;
}
template <typename T>
vector<T> rv(int n) {
  vector<T> x(n);
  rd(x);
  return x;
}
template <typename T>
void ra(T a[], int n, int st = 1) {
  for (int i = 0; i < n; ++i) rd(a[st + i]);
}
template <typename T1, typename T2>
void ra(T1 a[], T2 b[], int n, int st = 1) {
  for (int i = 0; i < n; ++i) rd(a[st + i]), rd(b[st + i]);
}
template <typename T1, typename T2, typename T3>
void ra(T1 a[], T2 b[], T3 c[], int n, int st = 1) {
  for (int i = 0; i < n; ++i) rd(a[st + i]), rd(b[st + i]), rd(c[st + i]);
}
void re(vector<int> E[], int m, bool dir = 0) {
  for (int i = 0, u, v; i < m; ++i) {
    rd(u, v);
    E[u].push_back(v);
    if (!dir) E[v].push_back(u);
  }
}
template <typename T>
void re(vector<pair<int, T>> E[], int m, bool dir = 0) {
  for (int i = 0, u, v; i < m; ++i) {
    T w;
    rd(u, v, w);
    E[u].push_back({v, w});
    if (!dir) E[v].push_back({u, w});
  }
}
int main() {
  for (int t = ri(); t--;) {
    int n = ri();
    vector<int> a(n + 1, 0);
    vector<vector<int>> ids(n + 1, vector<int>());
    for (int i = 1; i <= n; i++) {
      rd(a[i]);
      ids[a[i]].push_back(i);
    }
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    vector<vector<bool>> was(n + 1, vector<bool>(n + 1, false));
    function<int(int, int)> Solve = [&](int l, int r) {
      if (l > r) return 0;
      if (was[l][r]) return dp[l][r];
      was[l][r] = 1;
      if (l == r) return dp[l][r] = 1;
      dp[l][r] = Solve(l + 1, r) + 1;
      for (int i : ids[a[l]])
        if (i > l && i <= r) {
          ckmn(dp[l][r], Solve(l + 1, i - 1) + Solve(i, r));
        }
      return dp[l][r];
    };
    printf("%i\n", Solve(1, n) - 1);
  }
  return 0;
}
