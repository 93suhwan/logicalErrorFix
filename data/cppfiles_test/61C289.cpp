#include <bits/stdc++.h>
using namespace std;
const long long int ZERO = 0LL;
const long long int ONE = 1LL;
const int N = 2e5 + 1;
const int K = 20;
const long long int OO = 1e18;
const double PI = acos(-1);
const long long int MD = 1e9 + 7;
long long int add(long long int a, long long int b) {
  return (((a % MD) + (b % MD)) % MD + MD) % MD;
}
long long int mult(long long int a, long long int b) {
  return ((a % MD) * (b % MD)) % MD;
}
long long int fp(long long int x, long long int y, long long int m) {
  if (y == 0) return 1;
  long long int p = fp(x, y / 2, m) % m;
  p = (p * p) % m;
  return (y % 2 == 0) ? p : (x * p) % m;
}
int t = 1;
int n, m, k, need;
char grid[500][500];
bool vis[500][500];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
bool valid(int i, int j) {
  return i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == '.';
}
void bfs(int i, int j) {
  queue<pair<int, int> > q;
  q.push(make_pair(i, j));
  vis[i][j] = 1;
  need--;
  while (q.size()) {
    int sz = q.size();
    while (sz--) {
      int fi = q.front().first, fj = q.front().second;
      q.pop();
      bool find = false;
      for (int d = 0; d < 4; d++) {
        int ni = fi + dx[d];
        int nj = fj + dy[d];
        if (valid(ni, nj) && !vis[ni][nj] && need) {
          find = true;
          vis[ni][nj] = 1;
          need--;
          q.push(make_pair(ni, nj));
        }
      }
      if (!need) break;
    }
    if (!need) break;
  }
}
void dfs(int i, int j) {
  vis[i][j] = 1;
  for (int d = 0; d < 4; d++) {
    int ni = i + dx[d];
    int nj = j + dy[d];
    if (valid(ni, nj) && !vis[ni][nj]) dfs(ni, nj);
  }
  if (k) grid[i][j] = 'X', k--;
}
int main() {
  scanf("%d", &t);
  while (t--) {
    int n;
    string s;
    cin >> n >> s;
    string a = s;
    if (s[0] == '?') {
      s[0] = 'R';
      a[0] = 'B';
    }
    int a1 = 0, a2 = 0;
    for (int i = 1; i < n; i++) {
      if (s[i] == '?') {
        if (s[i - 1] == 'R')
          s[i] = 'B';
        else
          s[i] = 'R';
        if (a[i - 1] == 'R')
          a[i] = 'B';
        else
          a[i] = 'R';
      }
      a1 += s[i] == s[i - 1];
      a2 += a[i] == a[i - 1];
    }
    cout << (a1 < a2 ? s : a) << endl;
  }
  return 0;
}
