#include <bits/stdc++.h>
using namespace std;
int t;
int main() {
  scanf("%d", &t);
  while (t--) {
    vector<pair<int, pair<int, int>>> v;
    priority_queue<pair<int, int>> q;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      int temp;
      scanf("%d", &temp);
      q.push({temp, i + 1});
    }
    while (q.size() > 1) {
      pair<int, int> temp1, temp2;
      temp1 = q.top();
      q.pop();
      temp2 = q.top();
      q.pop();
      if (temp1.first > temp2.first) {
        v.push_back({temp2.first, {temp1.second, temp2.second}});
        q.push({temp1.first - temp2.first, temp1.second});
      } else if (temp1.first < temp2.first) {
        v.push_back({temp1.first, {temp1.second, temp2.second}});
        q.push({temp2.first - temp1.first, temp2.second});
      } else {
        v.push_back({temp1.first, {temp1.second, temp2.second}});
      }
    }
    int res = 0;
    for (int i = 0; i < v.size(); i++) {
      res += v[i].first;
    }
    cout << res << endl;
    for (int i = 0; i < v.size(); i++) {
      for (int j = 0; j < v[i].first; j++)
        cout << v[i].second.first << " " << v[i].second.second << endl;
    }
  }
  return 0;
}
