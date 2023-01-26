#include <bits/stdc++.h>
using namespace std;
template <typename T>
istream &operator>>(istream &in, vector<T> &v) {
  for (auto &i : v) in >> i;
  return in;
}
template <typename A, typename B>
istream &operator>>(istream &in, pair<A, B> &a) {
  in >> a.first >> a.second;
  return in;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long rand(long long l, long long r) {
  uniform_int_distribution<long long> uid(l, r);
  return uid(rng);
}
const string no = "No";
const string yes = "Yes";
void solve() {
  long long n, m, k;
  cin >> n >> m >> k;
  vector<string> mat(n);
  cin >> mat;
  vector<vector<long long>> dpl(n, vector<long long>(m)),
      dpr(n, vector<long long>(m));
  for (long long i = 1; i < n; i++) {
    for (long long j = 1; j < m - 1; j++) {
      dpl[i][j] = (mat[i - 1][j - 1] == '.' ? 0 : 1 + dpl[i - 1][j - 1]);
    }
    for (long long j = m - 2; j > 0; j--) {
      dpr[i][j] = (mat[i - 1][j + 1] == '.' ? 0 : 1 + dpr[i - 1][j + 1]);
    }
  }
  vector<vector<bool>> visited(n, vector<bool>(m));
  for (long long i = 1; i < n; i++) {
    for (long long j = 1; j < m - 1; j++) {
      if (mat[i][j] == '.') continue;
      long long left = dpl[i][j], right = dpr[i][j];
      if (min(left, right) < k) continue;
      long long mn = min(left, right);
      visited[i][j] = true;
      for (long long ii = i - 1; ii >= i - mn; ii--) {
        for (long long jj = j - 1; jj >= j - mn; jj--) {
          visited[ii][jj] = true;
        }
      }
      for (long long ii = i - 1; ii >= i - mn; ii--) {
        for (long long jj = j + 1; jj <= j + mn; jj++) {
          visited[ii][jj] = true;
        }
      }
    }
  }
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      if (mat[i][j] == '*' && !visited[i][j]) {
        cout << no << '\n';
        return;
      }
    }
  }
  cout << yes << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  for (long long tc = 1; tc <= t; tc++) {
    ;
    solve();
  }
  return 0;
}
