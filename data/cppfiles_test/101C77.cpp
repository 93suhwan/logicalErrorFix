#include <bits/stdc++.h>
using namespace std;
long long n, m, k;
long long x[200001], y[200001];
set<long long> sx, sy;
long long indx[200001], indy[200001];
long long find_indx(long long a) {
  long long l = 0, r = n - 1;
  long long ind = -1;
  while (l <= r) {
    long long mid = (l + r) / 2;
    if (x[mid] >= a) {
      ind = mid;
      r = mid - 1;
    } else
      l = mid + 1;
  }
  assert(ind != -1);
  return ind;
}
long long find_indy(long long b) {
  long long l = 0, r = m - 1;
  long long ind = -1;
  while (l <= r) {
    long long mid = (l + r) / 2;
    if (y[mid] >= b) {
      ind = mid;
      r = mid - 1;
    } else
      l = mid + 1;
  }
  assert(ind != -1);
  return ind;
}
void solv() {
  long long res = 0;
  cin >> n >> m >> k;
  sx.clear();
  sy.clear();
  for (long long i = 0; i < n; i++) {
    indx[i] = 0;
    cin >> x[i];
    sx.insert(x[i]);
  }
  for (long long i = 0; i < m; i++) {
    indy[i] = 0;
    cin >> y[i];
    sy.insert(y[i]);
  }
  vector<pair<long long, long long>> onx, ony;
  for (long long i = 0; i < k; i++) {
    long long a, b;
    cin >> a >> b;
    if (sx.count(a) && sy.count(b)) continue;
    if (sx.count(a))
      onx.push_back({a, b});
    else
      ony.push_back({b, a});
  }
  pair<long long, long long> las = {-1, -1};
  long long cnt = 0;
  sort(onx.begin(), onx.end());
  sort(ony.begin(), ony.end());
  for (long long i = 0; i < onx.size(); i++) {
    long long xx = find_indx(onx[i].first), yy = find_indy(onx[i].second);
    if (make_pair(xx, yy) != las)
      cnt = 0, las = {xx, yy};
    else
      cnt++;
    res += indy[yy] - cnt;
    indy[yy]++;
  }
  las = {-1, -1}, cnt = 0;
  for (long long i = 0; i < ony.size(); i++) {
    long long xx = find_indx(ony[i].second), yy = find_indy(ony[i].first);
    if (make_pair(xx, yy) != las)
      cnt = 0, las = {xx, yy};
    else
      cnt++;
    res += indx[xx] - cnt;
    indx[xx]++;
  }
  cout << res << '\n';
}
signed main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);
  long long t;
  cin >> t;
  while (t--) solv();
}
