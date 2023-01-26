#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ii = pair<int, int>;
using vvii = vector<vector<ii>>;
using ll = long long;
vvi v;
vi bajada;
int n, m;
void recur(int x, int y) {
  if (y == n) {
    cout << x + 1;
    return;
  }
  if (bajada[x] == y) {
    cout << x + 1;
    return;
  }
  if (v[y][x] == 2) {
    recur(x, y + 1);
  } else {
    if (bajada[x] == y + 1) bajada[x]--;
    if (v[y][x] == 1) {
      v[y][x] = 2;
      recur(x + 1, y);
    } else {
      v[y][x] = 2;
      recur(x - 1, y);
    }
  }
}
int main() {
  int k;
  cin >> n >> m >> k;
  v = vvi(n, vi(m));
  for (auto& x : v)
    for (auto& y : x) cin >> y;
  bajada = vi(m, n);
  for (int i = 0; i < k; ++i) {
    if (i) cout << " ";
    int c;
    cin >> c;
    recur(c - 1, 0);
  }
  cout << '\n';
}
