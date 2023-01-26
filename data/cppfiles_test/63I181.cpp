#include <bits/stdc++.h>
using namespace std;
vector<int> pare_m;
vector<int> pare_d;
int pre_m(int i) {
  if (pare_m[i] == -1) return i;
  return pare_m[i] = pre_m(pare_m[i]);
}
int pre_d(int i) {
  if (pare_d[i] == -1) return i;
  return pare_d[i] = pre_d(pare_d[i]);
}
int main() {
  int n, m1, m2;
  cin >> n >> m1 >> m2;
  pare_m = vector<int>(n, -1);
  pare_d = vector<int>(n, -1);
  for (int i = 0; i < m1; ++i) {
    int u, v;
    cin >> u >> v;
    --u;
    --v;
    pare_m[u] = pre_m(v);
  }
  for (int i = 0; i < m2; ++i) {
    int u, v;
    cin >> u >> v;
    --u;
    --v;
    pare_d[u] = pre_d(v);
  }
  int count = 0;
  vector<pair<int, int> > afegim(0);
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (pre_d(i) != pre_d(j) and pre_m(i) != pre_m(j)) {
        ++count;
        afegim.push_back({i, j});
        pare_d[pre_d(i)] = pre_d(j);
        pare_m[pre_m(i)] = pre_m(j);
      }
    }
  }
  cout << count << endl;
  for (int i = 0; i < count; ++i)
    cout << afegim[i].first + 1 << " " << afegim[i].second + 1 << endl;
}
