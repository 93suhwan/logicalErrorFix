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
  if (v == vv) {
    cout << "YES\n";
    return;
  }
  if (n <= 2) {
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
  vector<int> done(n + 1);
  for (int i = 0; i < n; i++) {
    if (vv[vv[i] - 1] - 1 == i) {
      cnt++;
    }
  }
  cnt /= 2;
  if (cnt == 1) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
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
