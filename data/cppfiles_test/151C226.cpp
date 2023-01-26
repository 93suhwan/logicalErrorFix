#include <bits/stdc++.h>
using namespace std;
void init_code() {}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  init_code();
  vector<pair<long long int, long long int>> vp;
  map<long long int, long long int> m;
  for (long long int i = 0; i < 500001; i++) {
    m[i] = i;
  }
  vector<long long int> ans;
  long long int t;
  cin >> t;
  long long int y = t;
  while (t--) {
    long long int n;
    cin >> n;
    if (n == 1) {
      long long int tt;
      cin >> tt;
      vp.push_back({0ll, tt});
    } else {
      long long int a, b;
      cin >> a >> b;
      vp.push_back({a, b});
    }
  }
  for (long long int i = y - 1; i >= 0; i--) {
    if (vp[i].first == 0) {
      ans.push_back(m[vp[i].second]);
    } else {
      m[vp[i].first] = m[vp[i].second];
    }
  }
  reverse((ans).begin(), (ans).end());
  ;
  for (auto n : ans) {
    cout << n << " ";
  }
  cout << "\n";
  ;
  return 0;
}
