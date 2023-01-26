#include <bits/stdc++.h>
using namespace std;
vector<int> x;
int sq;
vector<vector<int> > matr;
vector<int> pref;
void solve() {
  int n, m;
  cin >> n >> m;
  sq = sqrt(m);
  vector<pair<int, int> > z;
  matr = vector<vector<int> >(sq + 1, vector<int>(sq + 1, 0));
  pref = vector<int>(m + 1);
  for (int j = 0; j < n; j++) {
    int x, y;
    cin >> x >> y;
    z.push_back({x, y});
  }
  int sum = 0;
  vector<int> f(n);
  for (int j = 0; j < m; j++) {
    int op, k;
    cin >> op >> k;
    k--;
    if (op == 1) {
      f[k] = j;
      int x = z[k].first, y = z[k].second;
      if ((x + y) < sq) {
        int q = (x + y);
        for (int i = x; i < x + y; i++) {
          matr[q][(i + f[k]) % q]++;
        }
      } else {
        for (int i = j + x; i < m; i += (x + y)) {
          pref[i]++;
          pref[min(m, i + y)]--;
        }
      }
    } else {
      int x = z[k].first, y = z[k].second;
      if ((x + y) < sq) {
        int q = (x + y);
        int r = f[k];
        for (int i = x; i < x + y; i++) {
          matr[q][(i + f[k]) % q]--;
        }
      } else {
        for (int i = f[k] + x; i < m; i += (x + y)) {
          if ((i + y) <= j) {
            continue;
          }
          pref[max(i, j)]--;
          pref[min(m, i + y)]++;
        }
      }
    }
    sum += pref[j];
    int q = sum;
    for (int i = 1; i < sq + 1; i++) {
      q += matr[i][j % i];
    }
    cout << q << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
  return 0;
}
