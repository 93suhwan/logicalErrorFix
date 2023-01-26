#include <bits/stdc++.h>
using namespace std;
vector<long long> ufds(200050);
vector<long long> mini(200050);
long long find(long long k) {
  if (ufds[k] != k) {
    ufds[k] = find(ufds[k]);
  }
  return ufds[k];
}
void merge(long long a, long long b) {
  long long temp1 = find(a);
  long long temp2 = find(b);
  if (temp1 == temp2) {
    return;
  }
  ufds[temp1] = temp2;
  mini[temp2] = min(mini[temp2], mini[temp1]);
}
void find() {
  vector<pair<long long, pair<long long, long long> > > xs, ys;
  long long n, d;
  long long x, y, z;
  cin >> n >> d;
  for (long long i = 0; i < n; i++) {
    ufds[i] = i;
    mini[i] = INT_MAX;
  }
  for (long long i = 0; i < n; i++) {
    cin >> x >> y >> z;
    xs.push_back({x, {y, i}});
    ys.push_back({y, {x, i}});
    mini[i] = z;
  }
  sort(xs.begin(), xs.end());
  sort(ys.begin(), ys.end());
  for (long long i = 1; i < n; i++) {
    if (xs[i].first == xs[i - 1].first &&
        abs(xs[i].second.first - xs[i - 1].second.first) <= d) {
      merge(xs[i].second.second, xs[i - 1].second.second);
    }
  }
  for (long long i = 1; i < n; i++) {
    if (ys[i].first == ys[i - 1].first &&
        abs(ys[i].second.first - ys[i - 1].second.first) <= d) {
      merge(ys[i].second.second, ys[i - 1].second.second);
    }
  }
  vector<long long> times;
  for (long long i = 0; i < n; i++) {
    long long rn = find(i);
    if (rn == i) {
      times.push_back(mini[i]);
    }
  }
  long long ans = (long long)times.size() - 1;
  sort(times.begin(), times.end());
  for (long long i = 0; i < times.size(); i++) {
    long long dealt = i + times[i] + 2;
    ans =
        min(ans, times[i] + max((long long)0, (long long)times.size() - dealt));
  }
  cout << ans << "\n";
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    find();
  }
}
