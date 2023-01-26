#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    priority_queue<pair<int, int>> mxheap;
    for (int i = 0; i < n; i++) {
      int person, pts;
      person = i + 1;
      cin >> pts;
      mxheap.push({pts, person});
    }
    vector<pair<int, int>> sol;
    while (1) {
      int p1, p1pts, p2, p2pts;
      p1pts = mxheap.top().first;
      p1 = mxheap.top().second;
      mxheap.pop();
      p2pts = mxheap.top().first;
      p2 = mxheap.top().second;
      mxheap.pop();
      if (p1pts == 0 || p2pts == 0) {
        break;
      } else {
        sol.push_back({p1, p2});
        mxheap.push({--p1pts, p1});
        mxheap.push({--p2pts, p2});
      }
    }
    cout << sol.size() << endl;
    for (auto pr : sol) cout << pr.first << " " << pr.second << endl;
  }
  return 0;
}
