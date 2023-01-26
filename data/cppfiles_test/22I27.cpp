#include <bits/stdc++.h>
using namespace std;
const long long gr = 440;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, m;
  cin >> n >> m;
  vector<long long> x(n), y(n);
  for (long long i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }
  vector<long long> bal(n);
  vector<vector<long long>> mass(gr + 1, vector<long long>(gr));
  long long sum = 0;
  vector<pair<long long, long long>> zap(m);
  for (long long i = 0; i < m; i++) {
    cin >> zap[i].first >> zap[i].second;
    --zap[i].second;
  }
  vector<long long> next(m, m);
  vector<long long> prev(m, m);
  map<long long, long long> now;
  for (long long i = m - 1; i >= 0; i--) {
    if (now.find(zap[i].second) != now.end()) {
      next[i] = now[zap[i].second];
    }
    now[zap[i].second] = i;
  }
  now.clear();
  for (long long i = 0; i < m; i++) {
    if (now.find(zap[i].second) != now.end()) {
      prev[i] = now[zap[i].second];
    }
    now[zap[i].second] = i;
  }
  for (long long i = 0; i < m; i++) {
    sum += bal[i];
    long long here = sum;
    for (long long j = 2; j <= gr; ++j) {
      here += mass[j][i % j];
    }
    long long k = zap[i].second;
    long long op = zap[i].first;
    if (op == 1) {
      if (x[k] + y[k] <= gr) {
        for (long long j = (long long)i + x[k]; j < (long long)i + x[k] + y[k];
             j++) {
          ++mass[x[k] + y[k]][j % (x[k] + y[k])];
        }
      } else {
        long long max1 = 0;
        long long max2 = 0;
        for (long long j = (long long)i + x[k]; j < next[i];
             j += (long long)x[k] + y[k]) {
          ++bal[j];
          max1 = j;
        }
        for (long long j = i; j <= next[i]; j += (long long)x[k] + y[k]) {
          max2 = j;
          --bal[j];
        }
        if (max1 > max2) {
          --bal[next[i]];
        }
      }
    } else {
      if (x[k] + y[k] <= gr) {
        for (long long j = (long long)prev[i] + x[k];
             j < (long long)prev[i] + x[k] + y[k]; j++) {
          --mass[x[k] + y[k]][j % (x[k] + y[k])];
          if (i % (x[k] + y[k]) == j % (x[k] + y[k])) {
            --here;
          }
        }
      }
    }
    cout << here << '\n';
  }
}
