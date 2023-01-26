#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  while (n--) {
    priority_queue<pair<int, int>> heap;
    int x;
    cin >> x;
    for (int i = 1; i <= x; i++) {
      int t;
      cin >> t;
      if (t > 0) heap.push({t, i});
    }
    vector<pair<int, int>> ve;
    int ans = 0;
    while (heap.size() > 1) {
      pair<int, int> fi, se;
      fi = heap.top();
      heap.pop();
      se = heap.top();
      heap.pop();
      ve.push_back({fi.second, se.second});
      if (fi.first - 1 > 0) {
        fi.first = fi.first - 1;
        heap.push(fi);
      }
      if (se.first - 1 > 0) {
        se.first = se.first - 1;
        heap.push(se);
      }
    }
    cout << ve.size() << endl;
    for (int i = 0; i < ve.size(); i++) {
      cout << ve[i].first << " " << ve[i].second << endl;
    }
  }
  return 0;
}
