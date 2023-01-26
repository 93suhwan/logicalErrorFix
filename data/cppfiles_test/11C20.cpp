#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> vec(n, 0);
  for (int i = 0; i < n; i++) {
    cin >> vec[i];
    vec[i]--;
  }
  vector<int> diff(n, 0);
  for (int i = 0; i < n; i++) {
    diff[i] = i - vec[i];
  }
  vector<pair<int, int>> pv;
  for (int i = 0; i < n; i++) {
    if (diff[i] >= 0) pv.push_back({diff[i], vec[i]});
  }
  sort(pv.begin(), pv.end());
  vector<int> v;
  for (auto p : pv) {
    if (v.empty())
      v.push_back(p.second);
    else {
      auto it = lower_bound(v.begin(), v.end(), p.second);
      if (it == v.end()) {
        v.push_back(p.second);
      } else {
        *it = p.second;
      }
    }
  }
  cout << v.size() << endl;
  return 0;
}
