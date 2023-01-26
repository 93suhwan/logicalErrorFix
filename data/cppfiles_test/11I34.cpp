#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    v[i] = (i + 1) - v[i];
  }
  vector<int> pos;
  for (int i : v) {
    if (i >= 0) {
      pos.push_back(i);
    }
  }
  vector<int> ans;
  n = v.size();
  for (int i = 0; i < n; i++) {
    auto it = lower_bound(ans.begin(), ans.end(), v[i]);
    if (it == ans.end()) {
      ans.push_back(v[i]);
    } else {
      *it = v[i];
    }
  }
  cout << ans.size() - 1 << endl;
}
