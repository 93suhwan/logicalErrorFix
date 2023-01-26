#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
using namespace std;
const long long MAX = 1000004;
const long long INF = 1e18L + 5;
template <class T, class U>
void chmin(T &t, const U &u) {
  if (t > u) t = u;
}
template <class T, class U>
void chmax(T &t, const U &u) {
  if (t < u) t = u;
}
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << H;
  debug_out(T...);
}
template <typename Arg1>
void pn(Arg1 &&arg1) {
  cout << arg1 << "\n";
}
template <typename Arg1, typename... Args>
void pn(Arg1 &&arg1, Args &&...args) {
  cout << arg1 << "\n";
  pn(args...);
}
template <typename Arg1>
void ps(Arg1 &&arg1) {
  cout << arg1 << " ";
}
template <typename Arg1, typename... Args>
void ps(Arg1 &&arg1, Args &&...args) {
  cout << arg1 << " ";
  ps(args...);
}
template <typename Arg1>
void read(Arg1 &&arg1) {
  cin >> arg1;
}
template <typename Arg1, typename... Args>
void read(Arg1 &&arg1, Args &&...args) {
  cin >> arg1;
  read(args...);
}
long long dx[] = {-1, 0, 1, 0};
long long dy[] = {0, 1, 0, -1};
void dfs(vector<vector<long long>> &mat, long long i, long long j, long long n,
         long long m, vector<vector<bool>> &vis, long long &sz) {
  vis[i][j] = true;
  sz++;
  for (long long k = 0; k < 4; ++k) {
    long long tx = i + dx[k];
    long long ty = j + dy[k];
    if (tx >= 0 && ty >= 0 && tx < n && ty < m)
      if (vis[tx][ty] == false) {
        long long c = mat[i][j] & (1 << (3 - k));
        long long p;
        if (k == 0) p = mat[tx][ty] & (1 << 1);
        if (k == 1) p = mat[tx][ty] & (1 << 0);
        if (k == 2) p = mat[tx][ty] & (1 << 3);
        if (k == 3) p = mat[tx][ty] & (1 << 2);
        if (c == 0 && p == 0) dfs(mat, tx, ty, n, m, vis, sz);
      }
  }
}
void solve() {
  long long n, m;
  read(n, m);
  vector<long long> ans;
  vector<vector<long long>> mat(n, vector<long long>(m));
  vector<vector<bool>> vis(n, vector<bool>(m, false));
  for (long long i = 0; i < n; ++i)
    for (long long j = 0; j < m; ++j) read(mat[i][j]);
  for (long long i = 0; i < n; ++i)
    for (long long j = 0; j < m; ++j)
      if (!vis[i][j]) {
        long long sz = 0;
        dfs(mat, i, j, n, m, vis, sz);
        ans.push_back(sz);
      }
  sort(ans.begin(), ans.end(), greater<long long>());
  for (auto i : ans) ps(i);
}
int main() {
  auto start = std::chrono::high_resolution_clock::now();
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long tc = 1;
  for (long long i = 0; i < tc; ++i) {
    solve();
  }
  auto end = std::chrono::high_resolution_clock::now();
  auto duration =
      std::chrono::duration_cast<chrono::nanoseconds>(end - start).count();
  cerr << duration * 1e-9 << setprecision(9);
  cerr << " sec"
       << "\n";
}
