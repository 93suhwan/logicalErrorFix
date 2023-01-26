#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  while (t--) {
    long long q;
    cin >> q;
    vector<long long> ans;
    unordered_map<long long, vector<pair<long long, long long>>> mp;
    long long x = 0;
    while (q--) {
      long long m;
      cin >> m;
      if (m == 1) {
        long long n;
        cin >> n;
        ans.push_back(n);
        x++;
      } else {
        long long p, q;
        cin >> p >> q;
        mp[p].push_back({q, x});
      }
    }
    for (long long i = 0; i < ans.size(); i++) {
      long long k = ans[i];
      long long j = 0;
      while (j < mp[k].size() && mp[k][j].second < i) {
        j++;
      }
      if (j < mp[k].size() && mp[k][j].second > i) {
        k = mp[k][j].first;
      }
      cout << k << " ";
    }
  }
  return 0;
}
