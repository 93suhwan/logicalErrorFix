#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 7;
const int MAXB = 300;
vector<pair<int, int> > oc[MAXN];
int xx[MAXN], yy[MAXN];
int light[MAXN];
int jog[MAXN];
vector<int> starts[MAXN];
vector<int> finishes[MAXN];
int routine[MAXB][MAXB];
int md[MAXB];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> xx[i] >> yy[i];
    light[i] = xx[i] + yy[i] < MAXB;
  }
  map<int, int> inside;
  for (int i = 1; i <= m; i++) {
    int op, k;
    cin >> op >> k;
    if (op == 1) {
      inside[k] = i;
    } else {
      auto it = inside.find(k);
      oc[k].emplace_back(it->second, i - 1);
      inside.erase(it);
    }
  }
  for (auto p : inside) {
    oc[p.first].emplace_back(p.second, m);
  }
  for (int i = 1; i <= n; i++) {
    for (pair<int, int> p : oc[i]) {
      int inside = p.second - p.first + 1;
      int times = inside / (xx[i] + yy[i]);
      int rem = inside % (xx[i] + yy[i]);
      int blocked = times * (xx[i] + yy[i]);
      if (rem >= xx[i]) {
        jog[p.first + blocked + xx[i]]++;
        jog[p.second + 1]--;
      }
      if (light[i]) {
        starts[p.first].push_back(i);
        finishes[p.first + blocked].push_back(i);
      } else {
        for (int z = 0; z < blocked; z += xx[i] + yy[i]) {
          jog[p.first + z + xx[i]]++;
          jog[p.first + z + xx[i] + yy[i]]--;
        }
      }
    }
  }
  for (int i = 1; i <= m; i++) {
    for (int k : starts[i]) {
      int r = xx[k] + yy[k];
      int at = (i + xx[k]) % r;
      routine[r][at]++;
    }
    for (int k : finishes[i]) {
      int r = xx[k] + yy[k];
      int at = (i + xx[k]) % r;
      routine[r][at]--;
    }
    for (int r = 1; r < MAXB; r++) {
      md[r]++;
      if (md[r] == r) md[r] = 0;
      jog[i] += routine[r][md[r]];
    }
    for (int k : starts[i]) {
      int r = xx[k] + yy[k];
      int at = (i + xx[k] + yy[k]) % r;
      routine[r][at]--;
    }
    for (int k : finishes[i]) {
      int r = xx[k] + yy[k];
      int at = (i + xx[k] + yy[k]) % r;
      routine[r][at]++;
    }
    jog[i] += jog[i - 1];
  }
  for (int i = 1; i <= m; i++) cout << jog[i] << "\n";
  return 0;
}
