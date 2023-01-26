#include <bits/stdc++.h>
using namespace std;
int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (auto &i : (a)) cin >> i;
    ;
    vector<pair<long long, long long>> b;
    for (int i = 0; i < n; i++) {
      b.push_back({a[i], i});
    }
    sort(b.begin(), b.end());
    vector<vector<long long>> ans;
    for (long long i = n - 1; i >= 0; i--) {
      long long ind = 0;
      for (ind = 0; ind < n - 1; ind++) {
        if (a[ind] == b[i].first) break;
      }
      if (i > ind)
        ans.push_back({min(ind + 1, i + 1), max(ind + 1, i + 1), 1});
      else if (i < ind)
        ans.push_back({min(ind + 1, i + 1), max(ind + 1, i + 1), ind - i});
      else
        continue;
      long long s = abs(ind - i);
      long long m = max(ind, i);
      long long temp = a[m];
      for (int j = 0; j < s + 1; j++) {
        long long mm = m - 1;
        if (mm < min(ind, i)) mm = max(ind, i);
        swap(a[mm], temp);
        m--;
      }
    }
    cout << ans.size() << endl;
    for (auto i : ans) {
      for (auto j : i) cout << j << " ";
      cout << endl;
    }
  }
}
