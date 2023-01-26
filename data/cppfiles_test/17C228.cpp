#include <bits/stdc++.h>
using namespace std;
bool func(pair<long long, vector<long long>> p1,
          pair<long long, vector<long long>> p2) {
  long long c1 = 0, c2 = 0;
  for (long long i = 0; i < 5; i++) {
    if (p1.second[i] > p2.second[i]) c2++;
    if (p1.second[i] < p2.second[i]) c1++;
  }
  return c1 >= c2;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<pair<long long, vector<long long>>> v;
    for (long long i = 0; i < n; i++) {
      vector<long long> win(5);
      for (long long j = 0; j < 5; j++) {
        cin >> win[j];
      }
      v.push_back({i, win});
    }
    if (n == 1) {
      cout << "1" << endl;
      continue;
    }
    sort(v.begin(), v.end(), func);
    long long ans = v[0].first;
    long long flag = 0;
    for (long long i = 1; i < n; i++) {
      long long cnt = 0;
      for (long long j = 0; j < 5; j++) {
        if (v[0].second[j] < v[i].second[j]) cnt++;
      }
      if (cnt < 3) {
        cout << "-1" << endl;
        flag = 1;
        break;
      }
    }
    if (flag == 0) cout << ans + 1 << endl;
  }
  return 0;
}
