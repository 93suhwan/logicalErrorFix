#include <bits/stdc++.h>
#pragma GCC optimize "O3"
using namespace std;
const int INF = 1e9 + 7;
const int N = 1e6 + 7;
const int T = 1 << 20;
int n, m, ver, hor;
int inc_y = 0;
void nast(int& a, int& b) {
  b += 2;
  if (b >= m) {
    a += 2;
    b = inc_y;
  }
}
int X[] = {0, 0, 1, -1};
int Y[] = {1, -1, 0, 0};
bool good(pair<int, int> poz) {
  return poz.first >= 0 and poz.second >= 0 and poz.first < n and
         poz.second < m;
}
vector<pair<int, int> > sas(pair<int, int> poz) {
  vector<pair<int, int> > ret;
  for (int i = 0; i < 4; i++) {
    pair<int, int> nowa = {poz.first + X[i], poz.second + Y[i]};
    if (good(nowa)) ret.push_back(nowa);
  }
  return ret;
}
void literka(vector<vector<int> >& tab, pair<int, int> a, pair<int, int> b) {
  for (int i = 1; i < 26; i++) {
    tab[a.first][a.second] = i;
    tab[b.first][b.second] = i;
    int col = 0;
    for (auto& u : sas(a)) col += tab[u.first][u.second] == i;
    for (auto& u : sas(b)) col += tab[u.first][u.second] == i;
    if (col == 2) return;
  }
  while (1)
    ;
}
void solve() {
  cin >> n >> m >> hor;
  ver = n * m / 2 - hor;
  int mini_hor = ((n & 1) ? m / 2 : 0);
  int mini_ver = ((m & 1) ? n / 2 : 0);
  ver -= mini_ver;
  hor -= mini_hor;
  bool ok = !(ver < 0 or hor < 0 or ver & 1 or hor & 1);
  cout << (ok ? "YES" : "NO") << '\n';
  if (ok) {
    vector<vector<int> > tab(n, vector<int>(m));
    int x = 0, y = 0;
    if (n & 1) {
      x++;
      for (int i = 0; i < m; i += 2) literka(tab, {0, i}, {0, i + 1});
    }
    if (m & 1) {
      y++;
      inc_y++;
      for (int i = 0; i < n; i += 2) literka(tab, {i, 0}, {i + 1, 0});
    }
    while (x < n and m != 1) {
      if (hor) {
        literka(tab, {x, y}, {x, y + 1});
        literka(tab, {x + 1, y}, {x + 1, y + 1});
        hor -= 2;
      } else {
        literka(tab, {x, y}, {x + 1, y});
        literka(tab, {x, y + 1}, {x + 1, y + 1});
        ver -= 2;
      }
      nast(x, y);
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) cout << (char)(tab[i][j] + 'a');
      cout << '\n';
    }
  }
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int test = 1;
  cin >> test;
  for (int i = 0; i < test; i++) solve();
}
