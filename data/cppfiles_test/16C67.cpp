#include <bits/stdc++.h>
using namespace std;
int t;
int main() {
  scanf("%d", &t);
  while (t--) {
    vector<pair<int, int> > v;
    priority_queue<pair<int, int> > q;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      int temp;
      scanf("%d", &temp);
      if (temp != 0) q.push({temp, i + 1});
    }
    while (q.size() > 1) {
      pair<int, int> temp1, temp2;
      temp1 = q.top();
      q.pop();
      temp2 = q.top();
      q.pop();
      temp1.first--;
      temp2.first--;
      v.push_back({temp1.second, temp2.second});
      if (temp1.first > 0) q.push({temp1.first, temp1.second});
      if (temp2.first > 0) q.push({temp2.first, temp2.second});
    }
    cout << v.size() << endl;
    for (int i = 0; i < v.size(); i++) {
      cout << v[i].first << " " << v[i].second << endl;
    }
  }
  return 0;
}
