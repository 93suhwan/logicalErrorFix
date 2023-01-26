#include <bits/stdc++.h>
using namespace std;
int n, k, d[55], w[55][55], in[55], f[55];
vector<pair<int, int> > e;
int Rand() { return 1ll * rand() * rand() % 1000000000; }
int fd(int x) {
  if (f[x] == x) {
    return x;
  }
  f[x] = fd(f[x]);
  return f[x];
}
int main() {
  srand(time(NULL));
  cin >> n >> k;
  for (int i = 1; i <= k; i++) {
    cin >> d[i];
  }
  for (int i = k + 1; i <= n; i++) {
    d[i] = 100;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      cin >> w[i][j];
    }
  }
  int vl = 0;
  for (int i = 1; i < n; i++) {
    e.push_back(make_pair(i, n));
    vl += w[i][n];
    in[i]++;
    in[n]++;
  }
  for (double t = 100000; t > 0.00001; t *= 0.999993) {
    int x = Rand() % e.size();
    in[e[x].first]--;
    in[e[x].second]--;
    for (int i = 1; i <= n; i++) {
      f[i] = i;
    }
    int nwvl = vl - w[e[x].first][e[x].second];
    for (int i = 0; i < e.size(); i++) {
      if (i == x) {
        continue;
      }
      int tx = fd(e[i].first);
      int ty = fd(e[i].second);
      f[tx] = ty;
    }
    int ex = Rand() % (n - 1) + 1, ey = ex + Rand() % (n - ex) + 1;
    while (fd(ex) == fd(ey) || in[ex] == d[ex] || in[ey] == d[ey]) {
      ex = Rand() % (n - 1) + 1, ey = ex + Rand() % (n - ex) + 1;
    }
    nwvl += w[ex][ey];
    if (exp(-(double)(nwvl - vl) / t) >= (double)(Rand()) / 1000000000) {
      vl = nwvl;
      in[ex]++;
      in[ey]++;
      e.erase(e.begin() + x);
      e.push_back(make_pair(ex, ey));
    } else {
      in[e[x].first]++;
      in[e[x].second]++;
    }
  }
  cout << vl << endl;
  return 0;
}
