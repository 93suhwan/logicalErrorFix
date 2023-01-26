#include <bits/stdc++.h>
using namespace std;
int comp(pair<int, int> p, pair<int, int> q) {
  if (p.second - p.first <= q.second - q.first) {
    return 1;
  } else
    return 0;
}
int solver() {
  int n;
  cin >> n;
  pair<int, int> p[n];
  for (int i = 0; i < n; ++i) {
    cin >> p[i].first >> p[i].second;
  }
  sort(p, p + n, comp);
  set<int> s;
  for (int i = 0; i < n; ++i) {
    int t = p[i].first;
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
  int t = 1;
  cin >> t;
  while (t--) solver();
  return 0;
}
