#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
long long mod = 998244353;
long long add(long long a, long long b) { return (a + b) % mod; }
long long mul(long long a, long long b) { return (a * b) % mod; }
long long bin_pow(long long n, long long k) {
  if (k == 0) return 1;
  if (k == 1) return n;
  if (k & 1) return mul(n, bin_pow(n, k - 1));
  long long t = bin_pow(n, k / 2);
  return mul(t, t);
}
void solve() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (long long i = 0; i < n; i++) cin >> a[i];
}
vector<vector<char>> a;
vector<vector<char>> ans;
vector<vector<bool>> used;
vector<vector<bool>> good;
vector<long long> dx = {-1, 1, 0, 0};
vector<long long> dy = {0, 0, 1, -1};
bool check(long long x, long long y, long long n, long long m) {
  return (x >= 0 && y >= 0 && x < n && y < m);
}
void solveE() {
  long long n, m;
  cin >> n >> m;
  a.resize(n, vector<char>(m, 0));
  ans.resize(n, vector<char>(m, 0));
  used.resize(n, vector<bool>(m, false));
  good.resize(n, vector<bool>(m, false));
  long long sx = -1, sy = -1;
  for (long long i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (long long j = 0; j < m; j++) {
      if (s[j] == '.') {
        a[i][j] = 0;
        ans[i][j] = 0;
      } else if (s[j] == '#') {
        a[i][j] = 1;
        ans[i][j] = 1;
      } else {
        sx = i;
        sy = j;
        a[i][j] = 2;
        ans[i][j] = 2;
      }
    }
  }
  queue<pair<long long, long long>> q;
  q.push({sx, sy});
  good[sx][sy] = true;
  while (!q.empty()) {
    auto [x, y] = q.front();
    used[x][y] = true;
    q.pop();
    long long cnt = 0, g = 0;
    for (long long i = 0; i < 4; i++) {
      long long nx = x + dx[i];
      long long ny = y + dy[i];
      if (check(nx, ny, n, m) && a[nx][ny] == 0) {
        cnt++;
      }
      if (check(nx, ny, n, m) && good[nx][ny]) {
        g++;
      }
    }
    if (cnt - g <= 1 && g > 0) {
      if (!(x == sx && y == sy)) {
        ans[x][y] = 3;
        good[x][y] = true;
      }
      for (long long i = 0; i < 4; i++) {
        long long nx = x + dx[i];
        long long ny = y + dy[i];
        if (check(nx, ny, n, m) && a[nx][ny] == 0 && !used[nx][ny]) {
          q.push({nx, ny});
        }
      }
    }
  }
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      if (ans[i][j] == 0) {
        cout << ".";
      }
      if (ans[i][j] == 1) {
        cout << "#";
      }
      if (ans[i][j] == 2) {
        cout << "L";
      }
      if (ans[i][j] == 3) {
        cout << "+";
      }
    }
    cout << "\n";
  }
  a.clear();
  used.clear();
  ans.clear();
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << fixed << setprecision(10);
  long long t = 1;
  cin >> t;
  while (t--) solveE();
  return 0;
}
