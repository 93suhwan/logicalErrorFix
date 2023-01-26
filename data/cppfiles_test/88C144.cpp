#include <bits/stdc++.h>
using namespace std;
const long long int MOD = 1e9 + 7;
bool compare(pair<long long int, long long int> a,
             pair<long long int, long long int> b) {
  if (a.first == b.first) return (a.second > b.second);
  return (a.first < b.first);
}
bool comapre1(pair<long long int, long long int> a,
              pair<long long int, long long int> b) {
  return a.second < b.second;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t = 1, testcases = 1;
  cin >> t;
  while (t >= testcases) {
    long long int n, m;
    cin >> n >> m;
    long long int a[m * n];
    for (long long int i = 0; i < n * m; i++) cin >> a[i];
    std::vector<pair<long long int, long long int>> v;
    for (long long int i = 0; i < n * m; i++) v.push_back({a[i], i});
    sort(v.begin(), v.end());
    vector<vector<pair<long long int, long long int>>> v1;
    for (long long int i = 0; i < n * m; i += m) {
      vector<pair<long long int, long long int>> t;
      for (long long int j = i; j < i + m; j++) {
        t.push_back(v[j]);
      }
      v1.push_back(t);
    }
    long long int ans1 = 0;
    for (auto j : v1) {
      vector<pair<long long int, long long int>> v = j;
      sort(v.begin(), v.end(), compare);
      map<long long int, long long int> ma;
      for (long long int i = 0; i < m; i++) {
        ma[v[i].second] = i;
      }
      sort(v.begin(), v.end(), comapre1);
      long long int f[m];
      long long int ans = 0;
      fill(f, f + m, 0ll);
      for (auto k : v) {
        long long int i = k.second;
        for (long long int j = 0; j < ma[i]; j++) {
          if (f[j]) ans++;
        }
        f[ma[i]]++;
      }
      ans1 += ans;
    }
    cout << ans1 << "\n";
    testcases++;
  }
  cerr << "Time Taken:" << (float)clock() / CLOCKS_PER_SEC * 1000 << "ms"
       << "\n";
  return 0;
}
