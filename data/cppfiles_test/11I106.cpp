#include <bits/stdc++.h>
using namespace std;
bool grt(pair<long long, long long> p1, pair<long long, long long> p2) {
  return (p1.first < p2.first and p1.second <= p2.second);
}
long long binsrc(vector<pair<long long, long long> > &vec,
                 pair<long long, long long> val) {
  long long l = -1, r = vec.size() - 1;
  long long mid = (l + r) / 2;
  while (l < r - 1) {
    if (!grt(vec[mid], val))
      r = mid;
    else
      l = mid;
    mid = (l + r) / 2;
  }
  return r;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (auto &x : a) cin >> x;
  ;
  vector<pair<long long, long long> > p;
  for (long long i = 0; (1 > 0 and i < n) or (1 < 0 and i > n); i += 1)
    if (a[i] <= i + 1) p.push_back({a[i], i - a[i]});
  if (p.empty()) {
    cout << 0 << endl;
    return 0;
  }
  vector<pair<long long, long long> > vec(1);
  vec[0] = p[0];
  for (long long i = 1; (1 > 0 and i < p.size()) or (1 < 0 and i > p.size());
       i += 1) {
    if (grt(p[i], vec[0]))
      vec[0] = p[i];
    else if (grt(vec.back(), p[i]))
      vec.push_back(p[i]);
    else {
      ;
      vec[binsrc(vec, p[i])] = p[i];
    };
  }
  cout << vec.size() << endl;
  return 0;
}
