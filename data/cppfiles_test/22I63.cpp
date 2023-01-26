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
      if ((x + y) < sq) {
        long long q = (x + y);
        long long r = j % q;
        for (long long j = 0; j < q; j++) {
          if (((j - r + q) % q) >= x) {
            matr[q][j]++;
          }
        }
      } else {
        for (long long i = j + x; i < m; i += (x + y)) {
          pref[i]++;
        }
        for (long long i = j + x + y; i < m; i += (x + y)) {
          pref[i]--;
        }
      }
    } else {
      long long x = z[k].first, y = z[k].second;
      if ((x + y) < sq) {
        long long q = (x + y);
        long long r = f[k] % q;
        for (long long j = 0; j < q; j++) {
          if (((j - r + q) % q) >= x) {
            matr[q][j]--;
          }
        }
      } else {
        for (long long i = f[k] + x; i < m; i += (x + y)) {
          pref[i]--;
        }
        for (long long i = f[k] + x + y; i < m; i += (x + y)) {
          pref[i]++;
        }
      }
    }
    sum += pref[j];
    for (long long i = 1; i < sq; i++) {
      sum += matr[i][j % i];
    }
    cout << sum << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
  return 0;
}
