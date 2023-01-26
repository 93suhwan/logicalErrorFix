#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, j, k, t, x, temp;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<pair<int, int>> v;
    for (i = 0; i < n; i++) {
      cin >> k;
      temp = 0;
      for (j = 0; j < k; j++) {
        cin >> x;
        if (j == 0) temp = x + 1;
        if (temp + j + 1 < x) temp = x - j + 1;
      }
      v.push_back(make_pair(temp, temp + k));
    }
    sort(v.begin(), v.end());
    temp = 0;
    for (i = 1; i < n; i++) {
      if (v[i].first > v[i - 1].second) temp += v[i].first - v[i - 1].second;
    }
    cout << temp + v[0].first << endl;
  }
  return 0;
}
