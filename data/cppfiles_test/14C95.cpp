#include <bits/stdc++.h>
using namespace std;
void func(vector<long long> &vec, long long i, long long j, long long &x) {
  long long temp = vec[j];
  for (long long k = j; k > i; k--) {
    x++;
    vec[k] = vec[k - 1];
  }
  vec[i] = temp;
}
int32_t main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> vec(n);
    vector<long long> temp(n);
    for (long long i = 0; i < n; i++) {
      cin >> vec[i];
      temp[i] = vec[i];
    }
    long long cnt = 0;
    vector<pair<pair<long long, long long>, long long>> ans;
    sort(temp.begin(), temp.end());
    for (long long i = 0; i < n; i++) {
      if (vec[i] != temp[i]) {
        for (long long j = i + 1; j < n; j++) {
          if (vec[j] == temp[i]) {
            cnt++;
            long long x = 0;
            func(vec, i, j, x);
            ans.push_back({{i + 1, j + 1}, x});
          }
        }
      }
    }
    cout << cnt << endl;
    for (long long i = 0; i < ans.size(); i++) {
      cout << ans[i].first.first << " " << ans[i].first.second << " "
           << ans[i].second << endl;
    }
  }
}
