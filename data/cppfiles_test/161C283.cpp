#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b) {
  return a.second - a.first < b.second - b.first;
}
int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<pair<int, int> > a;
    vector<bool> ans(n);
    for (int i = 0; i < n; i++) {
      int x, y;
      cin >> x >> y;
      a.push_back(make_pair(x, y));
    }
    sort(a.begin(), a.end(), cmp);
    for (int i = 0; i < n; i++) {
      int j = a[i].first;
      for (; j <= a[i].second; j++) {
        if (!ans[j]) {
          ans[j] = true;
          break;
        }
      }
      cout << a[i].first << " " << a[i].second << " " << j << "\n";
    }
    cout << endl;
  }
  return 0;
}
