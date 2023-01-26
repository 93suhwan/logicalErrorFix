#include <bits/stdc++.h>
using namespace std;
long long t, n, m, k, x[300005], y[300005], a, b;
vector<pair<long long, long long>> v, v1;
multiset<long long> s;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> t;
  while (t--) {
    cin >> n >> m >> k;
    v = v1 = vector<pair<long long, long long>>();
    for (int i = 1; i <= n; i++) {
      cin >> x[i];
    }
    x[0] = y[0] = 0;
    x[n] = y[m] = 1000000;
    for (int i = 1; i <= m; i++) {
      cin >> y[i];
    }
    for (int i = 0; i < k; i++) {
      cin >> a >> b;
      v.push_back(make_pair(a, b));
      v1.push_back(make_pair(b, a));
    }
    sort(v.begin(), v.end());
    sort(v1.begin(), v1.end());
    long long cnt = 0, ans = 0, ptr = 0;
    s = multiset<long long>();
    for (int i = 0; i < n; i++) {
      if (x[i] == x[i + 1])
        continue;
      else {
        while (v[ptr].first == x[i]) ++ptr;
        while ((v[ptr].first > x[i]) && (v[ptr].first < x[i + 1])) {
          ans += s.size() - s.count(v[ptr].second);
          s.insert(v[ptr].second);
          ++ptr;
          if (ptr >= v.size()) break;
        }
        s = multiset<long long>();
      }
    }
    s = multiset<long long>();
    cnt = ptr = 0;
    for (int i = 0; i < m; i++) {
      if (y[i] == y[i + 1])
        continue;
      else {
        while (v1[ptr].first == y[i]) ++ptr;
        while ((v1[ptr].first > y[i]) && (v1[ptr].first < y[i + 1])) {
          ans += s.size() - s.count(v1[ptr].second);
          s.insert(v1[ptr].second);
          ++ptr;
          if (ptr >= v1.size()) break;
        }
        s = multiset<long long>();
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
