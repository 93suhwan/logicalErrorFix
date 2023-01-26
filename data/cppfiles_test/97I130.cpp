#include <bits/stdc++.h>
using namespace std;
template <class T>
bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
int H, W;
string S[505];
template <int um>
class UF {
 public:
  vector<int> par, rank, cnt;
  UF() {
    par = rank = vector<int>(um, 0);
    cnt = vector<int>(um, 1);
    for (int i = 0; i < um; i++) par[i] = i;
  }
  void reinit(int num = um) {
    int i;
    for (i = 0; i < (num); i++) rank[i] = 0, cnt[i] = 1, par[i] = i;
  }
  int operator[](int x) {
    return (par[x] == x) ? (x) : (par[x] = operator[](par[x]));
  }
  int count(int x) { return cnt[operator[](x)]; }
  int operator()(int x, int y) {
    if ((x = operator[](x)) == (y = operator[](y))) return x;
    cnt[y] = cnt[x] = cnt[x] + cnt[y];
    if (rank[x] > rank[y]) return par[x] = y;
    rank[x] += rank[x] == rank[y];
    return par[y] = x;
  }
};
UF<505 * 505> uf;
int ret[505][505];
void dfs(int y, int x, int v) {
  if (ret[y][x]) {
    return;
  }
  ret[y][x] = v;
  if (y && S[y - 1][x] == '.') dfs(y - 1, x, v);
  if (y + 1 < H && S[y + 1][x] == '.') dfs(y + 1, x, v);
  if (x && S[y][x - 1] == '.') dfs(y, x - 1, 5 - v);
  if (x + 1 < W && S[y][x + 1] == '.') dfs(y, x + 1, 5 - v);
  int dy[8] = {2, 1, 1, 0, 0, -1, -1, -2};
  int dx[8] = {0, 1, -1, 2, -2, 1, -1, 0};
  int i;
  for (i = 0; i < (8); i++) {
    int ty = y + dy[i];
    int tx = x + dx[i];
    if (ty < 0 || ty >= H || tx < 0 || tx >= W) continue;
    if (S[ty][tx] == 'X') continue;
    if (uf[y * W + x] == uf[ty * W + tx]) continue;
    dfs(ty, tx, 5 - v);
  }
}
void solve() {
  int i, j, k, l, r, x, y;
  string s;
  cin >> H >> W;
  for (y = 0; y < (H); y++) cin >> S[y];
  for (y = 0; y < (H); y++)
    for (x = 0; x < (W); x++)
      if (S[y][x] == 'X') {
        int num = 0;
        if (S[y - 1][x] == '.') num++;
        if (S[y + 1][x] == '.') num++;
        if (S[y][x - 1] == '.') num++;
        if (S[y][x + 1] == '.') num++;
        if (num % 2) {
          cout << "NO" << endl;
          return;
        }
        ret[y][x] = 5 * num / 2;
      }
  for (y = 0; y < (H); y++)
    for (x = 0; x < (W); x++)
      if (S[y][x] == '.') {
        if (y && S[y - 1][x] == '.') uf(y * W + x, (y - 1) * W + x);
        if (x && S[y][x - 1] == '.') uf(y * W + x, y * W + x - 1);
      }
  for (y = 0; y < (H); y++)
    for (x = 0; x < (W); x++)
      if (S[y][x] == '.' && ret[y][x] == 0) dfs(y, x, (x % 2 == 0) ? 1 : 4);
  cout << "YES" << endl;
  for (y = 0; y < (H); y++) {
    for (x = 0; x < (W); x++) cout << ret[y][x] << " ";
    cout << endl;
  }
}
int main(int argc, char **argv) {
  string s;
  int i;
  if (argc == 1) ios::sync_with_stdio(false), cin.tie(0);
  for (i = 0; i < (argc - 1); i++) s += argv[i + 1], s += '\n';
  for (i = 0; i < (s.size()); i++) ungetc(s[s.size() - 1 - i], stdin);
  cout.tie(0);
  solve();
  return 0;
}
