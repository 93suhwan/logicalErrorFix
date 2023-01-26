#include <bits/stdc++.h>
const long long M = 1e9 + 7;
using namespace std;
long long dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
void test_cases() {
  long long n;
  cin >> n;
  vector<long long> arr(n);
  for (long long i = 0; i < n; i++) {
    cin >> arr[i];
  }
  vector<long long> s = arr;
  sort(s.begin(), s.end());
  long long cnt = 0;
  vector<pair<pair<long long, long long>, long long>> ans;
  for (long long i = 0; i < n; i++) {
    if (arr[i] == s[i]) {
      continue;
    }
    for (long long j = i + 1; j < n; j++) {
      if (arr[j] == s[i]) {
        cnt++;
        ans.push_back({{i + 1, j + 1}, j - i});
        for (long long k = j; k > i; k--) {
          arr[k] = arr[k - 1];
        }
        arr[i] = arr[i];
        break;
      }
    }
  }
  cout << cnt << '\n';
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
