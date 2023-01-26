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
    for (i = 0; i < n; i++) {
      cout << v1[i].first << " " << v1[i].second << " " << v2[i].first << endl;
    }
  }
  return 0;
}
