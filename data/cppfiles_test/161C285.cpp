#include <bits/stdc++.h>
using namespace std;
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.second < b.second);
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
      int x, y;
      cin >> x >> y;
      v.push_back({x, y});
    }
    sort(v.begin(), v.end(), sortbysec);
    unordered_set<int> isAvailable;
    for (int i = 1; i <= n; i++) {
      isAvailable.insert(i);
    }
    for (int i = 0; i < n; i++) {
      for (int j = v[i].first; j <= v[i].second; j++) {
        if (isAvailable.find(j) != isAvailable.end()) {
          cout << v[i].first << " " << v[i].second << " " << j << "\n";
          isAvailable.erase(j);
          break;
        }
      }
    }
    cout << "\n";
  }
}
