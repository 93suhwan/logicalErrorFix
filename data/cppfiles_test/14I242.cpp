#include <bits/stdc++.h>
const long long M = 1e9 + 7;
using namespace std;
long long dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
void test_cases() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<pair<pair<long long, long long>, long long>> ans;
  for (long long i = 0; i < n; i++) {
    long long id = min_element(a.begin() + i, a.end()) - a.begin();
    if (id == i) {
      continue;
    }
    ans.push_back({{i + 1, id + 1}, 1});
    long long tmp = a[id];
    for (long long j = i + 1; j <= id; j++) {
      a[j] = a[j - 1];
      a[id] = tmp;
    }
  }
  cout << (long long)ans.size() << '\n';
  ;
  for (auto x : ans) {
    cout << x.first.first << ' ' << x.first.second << ' ' << x.second << '\n';
    ;
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ;
  long long t;
  cin >> t;
  while (t--) {
    test_cases();
  }
}
