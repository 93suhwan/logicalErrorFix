#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    map<int, vector<int> > mp;
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
      cin >> a[i] >> b[i];
      mp[a[i]].push_back(b[i]);
      cnt[b[i]]++;
    }
    long long N = (long long)n;
    long long ans = (N * (N - 1) * (N - 2)) / 6;
    for (auto &u : mp) {
      vector<int> vv = u.second;
      long long r = (long long)vv.size(), l;
      r--;
      for (auto &j : vv) {
        l = cnt[j] - 1;
        ans -= l * r;
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
