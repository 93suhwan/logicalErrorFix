#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    string colored;
    cin >> colored;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
      if (colored[i] == 'R') {
        v.push_back({a[i], INT_MAX});
      } else {
        v.push_back({INT_MIN, a[i]});
      }
    }
    sort(v.begin(), v.end());
    bool allCovered = 1;
    int i = 0, currNumber = 1;
    while (i < n) {
      if (currNumber >= v[i].first && currNumber <= v[i].second) {
        currNumber++;
        i++;
      } else {
        allCovered = 0;
        break;
      }
    }
    if (allCovered) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
