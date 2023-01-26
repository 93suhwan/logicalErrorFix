#include <bits/stdc++.h>
using namespace std;
bool com(pair<long long int, long long int> p1,
         pair<long long int, long long int> p2) {
  if (p1.first == p2.first) return p1.second > p2.second;
  return p1.first < p2.first;
}
bool com2(pair<long long int, long long int> p1,
          pair<long long int, long long int> p2) {
  if (p1.second == p2.second) return p1.first < p2.first;
  return p1.second < p2.second;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  map<long long int, long long int> mp;
  set<long long int> st;
  vector<pair<long long int, long long int> > v1, v2, v;
  string str1, str2, str;
  long long int i, n, t, l, r, j;
  cin >> t;
  while (t--) {
    queue<pair<long long int, long long int> > q;
    v1.clear();
    v2.clear();
    cin >> n;
    long long int cnt[n + 2];
    memset(cnt, 0, sizeof(cnt));
    for (i = 1; i <= n; i++) {
      cin >> l >> r;
      v1.push_back({l, r});
    }
    sort(v1.begin(), v1.end(), com);
    for (i = 1; i <= n; i++) {
      for (j = 0; j < n; j++) {
        l = v1[j].first;
        r = v1[j].second;
        if (l <= i && i <= r) cnt[i]++;
      }
    }
    for (i = 1; i <= n; i++) {
      v2.push_back({i, cnt[i]});
    }
    sort(v2.begin(), v2.end(), com2);
    q.push({1, n});
    i = 0;
    l = 1;
    r = n;
    long long int l1, r1, l2, r2;
    while (!q.empty()) {
      pair<long long int, long long int> f = q.front();
      l = f.first;
      r = f.second;
      cout << f.first << " " << f.second << " " << v2[i].first << endl;
      q.pop();
      l1 = l;
      r1 = v2[i].first - 1;
      l2 = v2[i].first + 1;
      ;
      r2 = r;
      if (l1 <= r1 && 0 < l1 && l1 <= n && 0 < r1 && r1 <= n) q.push({l1, r1});
      if (l2 <= r2 && 0 < l2 && l2 <= n && 0 < r2 && r2 <= n) q.push({l2, r2});
      i++;
    }
  }
  return 0;
}
