#include <bits/stdc++.h>
using namespace std;
const int mm = 2005;
const long long mod = 10007;
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-') {
      f = -1;
      ch = getchar();
    }
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int n, m1, m2, f[2][mm];
int getf(int id, int x) {
  return x == f[id][x] ? x : f[id][x] = getf(id, f[id][x]);
}
vector<pair<int, int>> retorno;
int main() {
  n = read(), m1 = read(), m2 = read();
  for (int i = 1; i <= n; i++) {
    f[0][i] = f[1][i] = i;
  }
  for (int i = 1; i <= m1; i++) {
    int u = read(), v = read();
    int fu = getf(0, u), fv = getf(0, v);
    f[0][fu] = fv;
  }
  for (int i = 1; i <= m2; i++) {
    int u = read(), v = read();
    int fu = getf(1, u), fv = getf(1, v);
    f[1][fu] = fv;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (getf(0, i) != getf(0, j) && getf(1, i) != getf(1, j)) {
        retorno.push_back({i, j});
        f[0][getf(0, i)] = getf(0, j);
        f[1][getf(1, i)] = getf(1, j);
      }
    }
  }
  cout << retorno.size() << endl;
  for (auto i : retorno) {
    cout << i.first << " " << i.second << endl;
  }
  return 0;
}
