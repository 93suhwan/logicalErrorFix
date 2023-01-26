#include <bits/stdc++.h>
using namespace std;
int r, c;
vector<vector<int>> m;
vector<vector<pair<int, int>>> pref, suf;
void build() {
  cin >> r >> c;
  m.resize(r);
  pref.resize(r), suf.resize(r);
  for (int i = 0; i < r; i++) {
    m[i].resize(c), pref[i].resize(c), suf[i].resize(c);
    int minimo = 1000000007, maximo = 0;
    for (int j = 0; j < c; j++) {
      cin >> m[i][j];
      minimo = min(minimo, m[i][j]);
      maximo = max(maximo, m[i][j]);
      pref[i][j] = {minimo, maximo};
    }
    minimo = 1000000007, maximo = 0;
    for (int j = c - 1; j >= 0; j--) {
      minimo = min(minimo, m[i][j]);
      maximo = max(maximo, m[i][j]);
      suf[i][j] = {minimo, maximo};
    }
  }
}
vector<int> blue;
bool tenta(int col) {
  blue.clear();
  set<pair<int, int>> esq;
  set<pair<int, int>> dir;
  int menor_da_direita = 1000000007;
  vector<array<int, 3>> fila;
  for (int i = 0; i < r; i++) {
    esq.insert({-pref[i][col].first, i});
    fila.push_back({pref[i][col].second, pref[i][col].first, i});
  }
  for (int i = 0; i < r; i++) {
    dir.insert({suf[i][col + 1].second, i});
  }
  sort(begin(fila), end(fila));
  for (auto x : fila) {
    int low = x[1], high = x[0], ind = x[2];
    esq.erase({-low, ind});
    dir.erase({suf[ind][col + 1].second, ind});
    menor_da_direita = min(menor_da_direita, suf[ind][col + 1].first);
    blue.push_back(ind);
    auto it = esq.lower_bound({-high, -1});
    if (it != esq.end()) {
      continue;
    }
    it = dir.lower_bound({menor_da_direita, -1});
    if (it != dir.end()) {
      continue;
    }
    if (blue.size() == r) return false;
    return true;
  }
  return false;
}
vector<int> color;
int main() {
  int t;
  cin >> t;
  while (t--) {
    build();
    int ans = -1;
    for (int i = 0; i < c - 1; i++) {
      if (tenta(i)) {
        ans = i + 1;
        break;
      }
    }
    if (ans == -1)
      cout << "NO" << endl;
    else {
      cout << "YES" << endl;
      color.resize(r);
      for (int i = 0; i < r; i++) color[i] = 0;
      for (auto x : blue) color[x] = 1;
      for (int i = 0; i < r; i++) {
        if (color[i])
          cout << 'B';
        else
          cout << "R";
      }
      cout << " " << ans << endl;
    }
  }
}
