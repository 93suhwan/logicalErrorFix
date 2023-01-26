#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    vector<long long int> v;
    for (long long int i = 0; i < n; i++) {
      long long int a;
      cin >> a;
      v.push_back(a);
    }
    string s;
    cin >> s;
    vector<tuple<long long int, long long int, long long int>> arr;
    for (long long int i = 0; i < n; i++) {
      long long int like = s[i] == '1' ? 1 : 0;
      arr.push_back({v[i], i, like});
    }
    sort(arr.begin(), arr.end(),
         [](tuple<long long int, long long int, long long int> a,
            tuple<long long int, long long int, long long int> b) {
           auto [v1, i1, l1] = a;
           auto [v2, i2, l2] = b;
           if (l1 == l2) return v1 < v2;
           return l1 < l2;
         });
    vector<long long int> ans(n, 0);
    for (long long int i = 0; i < n; i++) {
      auto [v1, i1, l1] = arr[i];
      ans[i1] = i + 1;
    }
    for (auto &x : ans) {
      cout << x << " ";
    }
    cout << "\n";
  }
  return 0;
}
