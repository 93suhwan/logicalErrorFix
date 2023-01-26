#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int tests;
  tests = 1;
  while (tests--) {
    int n, m;
    cin >> n >> m;
    string second[n];
    vector<pair<long long int, long long int>> vp;
    for (int i = 0; i < n; i++) {
      cin >> second[i];
      long long int val = 0;
      for (int j = 0; j < second[i].size(); j++) {
        if (j % 2 == 0) {
          val += ('Z' - second[i][j]) * (-1) * (n - i);
        } else {
          val += ('Z' - second[i][j]) * (n - i);
        }
      }
      vp.push_back({val, i + 1});
    }
    sort(vp.begin(), vp.end());
    for (auto u : vp) cout << u.second << " ";
    cout << "\n";
  }
  return 0;
}
