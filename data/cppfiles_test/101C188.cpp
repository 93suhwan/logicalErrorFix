#include <bits/stdc++.h>
using namespace std;
void testCase() {
  int n, m, k;
  cin >> n >> m >> k;
  map<long long, long long> X, Y;
  vector<long long> Xs(n), Ys(m);
  vector<pair<long long, long long>> points(k);
  for (int i = 0; i < n; i++) cin >> Xs[i], X[Xs[i]] = 1;
  for (int i = 0; i < m; i++) cin >> Ys[i], Y[Ys[i]] = 1;
  for (int i = 0; i < k; i++) cin >> points[i].first >> points[i].second;
  map<pair<long long, long long>, map<long long, long long>> counterX, counterY;
  for (auto i : points) {
    if (X[i.first] && Y[i.second]) continue;
    if (X[i.first]) {
      auto low = lower_bound(Ys.begin(), Ys.end(), i.second);
      long long t = *low, b = *(--low);
      counterX[{t, b}][i.first]++;
    } else if (Y[i.second]) {
      auto low = lower_bound(Xs.begin(), Xs.end(), i.first);
      long long t = *low, b = *(--low);
      counterY[{t, b}][i.second]++;
    }
  }
  long long sol = 0;
  for (auto i : counterX) {
    long long curSol = 0;
    for (auto j : i.second)
      sol -= j.second * (j.second - 1) / 2, curSol += j.second;
    sol += curSol * (curSol - 1) / 2;
  }
  for (auto i : counterY) {
    long long curSol = 0;
    for (auto j : i.second)
      sol -= j.second * (j.second - 1) / 2, curSol += j.second;
    sol += curSol * (curSol - 1) / 2;
  }
  cout << sol << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T = 1;
  cin >> T;
  while (T--) {
    testCase();
  }
  return 0;
}
