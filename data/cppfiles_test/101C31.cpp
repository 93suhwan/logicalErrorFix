#include <bits/stdc++.h>
using namespace std;
void fastio() {
  ios::sync_with_stdio(0);
  cin.tie(0);
}
int main() {
  fastio();
  long long int t;
  cin >> t;
  while (t--) {
    long long int a, b, n;
    cin >> a >> b >> n;
    map<long long int, long long int> x, y, mxx, myy;
    map<long long int, map<long long int, long long int>> mx, my;
    long long int d[a], f[b];
    long long int ind = 1;
    for (long long int i = 0; i < a; i++) {
      long long int r;
      cin >> r;
      x[r] = ind++;
      d[i] = r;
    }
    ind = 1;
    for (long long int i = 0; i < b; i++) {
      long long int r;
      cin >> r;
      y[r] = ind++;
      f[i] = r;
    }
    vector<pair<long long int, long long int>> p;
    for (long long int i = 0; i < n; i++) {
      long long int q, r;
      cin >> q >> r;
      p.push_back({q, r});
    }
    for (long long int i = 0; i < n; i++) {
      long long int q = p[i].first;
      long long int r = p[i].second;
      if (x[q] != 0 && y[r] == 0) {
        long long int j = upper_bound(f, f + b, r) - f;
        myy[j]++;
        my[j][q]++;
      } else if (x[q] == 0 && y[r] != 0) {
        long long int j = upper_bound(d, d + a, q) - d;
        mxx[j]++;
        mx[j][r]++;
      }
    }
    long long int ans = 0;
    for (auto i : myy) {
      if (i.second > 1) ans += (i.second * (i.second - 1)) / 2;
      for (auto j : my[i.first]) {
        if (j.second > 1) {
          ans -= (j.second * (j.second - 1)) / 2;
        }
      }
    }
    for (auto i : mxx) {
      if (i.second > 1) ans += (i.second * (i.second - 1)) / 2;
      for (auto j : mx[i.first]) {
        if (j.second > 1) {
          ans -= (j.second * (j.second - 1)) / 2;
        }
      }
    }
    cout << ans;
    cout << "\n";
    ;
  }
  return 0;
}
