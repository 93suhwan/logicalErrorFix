#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      v.push_back({x, i});
    }
    sort((v).begin(), (v).end());
    int a[n + 1];
    int i = 1;
    for (i = 1; i < n; i++) {
      if (v[i].first == v[i - 1].first) {
        cout << "YES\n";
        break;
      }
      a[v[i].first] = v[i].second;
    }
    a[v[0].first] = v[0].second;
    if (i != n) continue;
    int cycle = 0;
    for (int i = 0; i < n; i++) {
      int x = v[i].first;
      int value = 0;
      while (a[x] >= 0) {
        value++;
        int temp = x;
        x = v[a[x]].first;
        a[temp] = INT_MIN;
      }
      if (value) cycle += value - 1;
    }
    if (cycle % 2 == 0) {
      cout << "YES\n";
    } else
      cout << "NO\n";
  }
}
