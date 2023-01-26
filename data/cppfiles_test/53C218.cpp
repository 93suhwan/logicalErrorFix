#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> vec(n);
    for (int i = 0; i < n; i++) {
      cin >> vec[i].first;
      vec[i].second = i;
    }
    sort(vec.begin(), vec.end());
    int ans = 1;
    for (int i = 1; i < n; i++) {
      if (vec[i - 1].second + 1 != vec[i].second) ans++;
    }
    if (ans <= k)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
  return 0;
}
