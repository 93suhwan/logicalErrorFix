#include <bits/stdc++.h>
using namespace std;
const long long N = 1e18;
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<vector<long long>> two;
  long long tt = 1;
  for (long long rep = 0; rep < (62); ++rep) {
    long long num = tt;
    vector<long long> a;
    while (num) {
      a.push_back(num % 10);
      num /= 10;
    }
    reverse(a.begin(), a.end());
    two.push_back(a);
    tt *= 2;
  }
  map<long long, long long> ans;
  long long T;
  cin >> T;
  while (T--) {
    long long n;
    cin >> n;
    if (ans.count(n)) {
      cout << ans[n] << '\n';
      continue;
    }
    long long num = n, len = 0;
    vector<long long> a;
    while (num) {
      len++;
      a.push_back(num % 10);
      num /= 10;
    }
    long long val = len + 1;
    reverse(a.begin(), a.end());
    for (auto &v : two) {
      long long i = 0, j = 0;
      while (i < (long long)a.size() and j < (long long)v.size()) {
        if (v[j] == a[i])
          j++, i++;
        else
          i++;
      }
      val = min(val, len - j + ((long long)v.size() - j));
    }
    ans[n] = val;
    cout << val << '\n';
  }
  return 0;
}
