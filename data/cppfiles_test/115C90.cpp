#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
const int mod = 998244353;
int n, m, Q;
int a[maxn];
int cnt_col[maxn][2];
int cnt_row[maxn][2];
map<pair<int, int>, int> board;
int bad_col = 0, only_col = 0;
int pw2[maxn];
int bad_row = 0, only_row = 0;
int f[2];
void read_input() { cin >> n >> m >> Q; }
void del(int x, int y) {
  int t = board[pair<int, int>(x, y)];
  board.erase(pair<int, int>(x, y));
  int msk = x & 1;
  msk ^= 1;
  --cnt_col[y][t ^ msk];
  if (cnt_col[y][t ^ msk] == 0) {
    --f[t ^ msk ^ !(y & 1)];
    if (cnt_col[y][t ^ msk ^ 1])
      --bad_col;
    else
      --only_col;
  }
  msk = y & 1;
  msk ^= 1;
  --cnt_row[x][t ^ msk];
  if (cnt_row[x][t ^ msk] == 0) {
    if (cnt_row[x][t ^ msk ^ 1])
      --bad_row;
    else
      --only_row;
  }
}
void add(int x, int y, int t) {
  int msk = x & 1;
  msk ^= 1;
  ++cnt_col[y][t ^ msk];
  if (cnt_col[y][t ^ msk] == 1) {
    ++f[t ^ msk ^ !(y & 1)];
    if (cnt_col[y][t ^ msk ^ 1])
      ++bad_col;
    else
      ++only_col;
  }
  msk = y & 1;
  msk ^= 1;
  ++cnt_row[x][t ^ msk];
  if (cnt_row[x][t ^ msk] == 1) {
    if (cnt_row[x][t ^ msk ^ 1])
      ++bad_row;
    else
      ++only_row;
  }
  board[pair<int, int>(x, y)] = t;
}
void solve() {
  pw2[0] = 1;
  for (int i = 1; i < maxn; ++i) {
    pw2[i] = pw2[i - 1] * 2LL % mod;
  }
  for (; Q > 0; --Q) {
    int x, y, t;
    cin >> x >> y >> t;
    if (t == -1) {
      if (board.count(pair<int, int>(x, y))) {
        del(x, y);
      }
    } else {
      if (board.count(pair<int, int>(x, y))) {
        del(x, y);
      }
      add(x, y, t);
    }
    int ans = (bad_col > 0 ? 0 : pw2[m - only_col]);
    ans = (ans + (bad_row > 0 ? 0 : pw2[n - only_row])) % mod;
    if (bad_col == 0 && bad_row == 0) {
      if (only_col == 0) {
        ans = (ans - 2 + mod) % mod;
      } else {
        if (f[0] == 0 || f[1] == 0) {
          ans = (ans - 1 + mod) % mod;
        }
      }
    }
    cout << ans << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  read_input();
  solve();
}
