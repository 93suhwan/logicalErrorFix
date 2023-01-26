#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long N = 2e5 + 10;
void test_case() {
  long long n;
  cin >> n;
  vector<long long> v(n), vv;
  map<int, int> mm;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    mm[v[i]]++;
  }
  vv = v;
  sort(v.begin(), v.end());
  if (n <= 3 and v == vv) {
    cout << "YES\n";
    return;
  }
  if (v != vv and v.size() < 2) {
    cout << "NO\n";
    return;
  }
  for (auto u : mm) {
    if (u.second > 1) {
      cout << "YES\n";
      return;
    }
  }
  long long cnt = 0;
  for (int i = 0; i < n; i++) {
    if (v[i] != vv[i]) {
      cnt++;
    }
  }
  if (n >= 4 or cnt >= 3) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int tc = 1;
  cin >> tc;
  while (tc--) {
    test_case();
  }
  return 0;
}
