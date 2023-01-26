#include <bits/stdc++.h>
using namespace std;
vector<long long> x;
long long sq;
vector<vector<long long> > matr;
vector<long long> pref;
void solve() {
  long long n, m;
  cin >> n >> m;
  sq = sqrt(m);
  vector<pair<long long, long long> > z;
  matr = vector<vector<long long> >(sq + 1, vector<long long>(sq + 1, 0));
  pref = vector<long long>(m + 1);
  for (long long j = 0; j < n; j++) {
    long long x, y;
    cin >> x >> y;
    z.push_back({x, y});
  }
  long long sum = 0;
  vector<long long> f(n);
  for (long long j = 0; j < m; j++) {
    long long op, k;
    cin >> op >> k;
    k--;
    if (op == 1) {
      f[k] = j;
      long long x = z[k].first, y = z[k].second;
      if ((x + y) <= sq) {
        long long q = (x + y);
        long long r = j;
        for (long long i = j + x; i < j + x + y; i++) {
          if (((i - r + q) % q) >= x) {
            matr[q][i % q]++;
          }
        }
      } else {
        for (long long i = j + x; i < m; i += (x + y)) {
          pref[i]++;
          if ((i + y) < m) {
            pref[i + y]--;
          }
        }
      }
    } else {
      long long x = z[k].first, y = z[k].second;
      if ((x + y) <= sq) {
        long long q = (x + y);
        long long r = f[k];
        for (long long i = f[k] + x; i < f[k] + x + y; i++) {
          if (((i - r + q) % q) >= x) {
            matr[q][i % q]--;
          }
        }
      } else {
        for (long long i = f[k] + x; i < m; i += (x + y)) {
          pref[i]--;
          if ((i + y) < m) {
            pref[i + y]++;
          }
        }
      }
    }
    sum += pref[j];
    long long q = sum;
    for (long long i = 1; i < sq + 1; i++) {
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
