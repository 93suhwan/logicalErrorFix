#include <bits/stdc++.h>
using namespace std;
int comp(pair<long long, long long> p, pair<long long, long long> q) {
  if (p.second - p.first < q.second - q.first) {
    return 1;
  } else
    return 0;
}
int solver() {
  long long n;
  cin >> n;
  pair<long long, long long> p[n];
  for (long long i = 0; i < n; ++i) {
    cin >> p[i].first >> p[i].second;
  }
  sort(p, p + n, comp);
  set<long long> s;
  for (long long i = 0; i < n; ++i) {
    long long t = p[i].first;
    while (t <= p[i].second) {
      if (s.count(t) == 0) {
        cout << p[i].first << " " << p[i].second << " " << t << '\n';
        s.insert(t);
        break;
      }
      t++;
    }
  }
  cout << '\n';
  return 0;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) solver();
  return 0;
}
