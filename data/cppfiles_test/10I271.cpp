#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    map<int, int> no;
    int x[n];
    for (int i = 0; i < n; i++) {
      cin >> x[i];
      no[x[i]]++;
    }
    vector<int> full;
    vector<int> part;
    map<int, set<int>> values;
    int count = 0;
    for (auto i : no) {
      if (i.second >= k) {
        full.push_back(i.first);
      } else {
        part.push_back(i.first);
        count += i.second;
      }
    }
    for (auto i : full) {
      for (int j = 1; j <= k; j++) values[i].insert(j);
    }
    int c = 0;
    for (auto i : part) {
      for (int j = 0; j < no[i]; j++) {
        c++;
        values[i].insert(c);
        c = c % k;
        if (c == 0) c = 1;
      }
    }
    for (int i = 0; i < n; i++) {
      if (values[x[i]].size() == 0)
        cout << "0"
             << " ";
      else {
        cout << *values[x[i]].begin() << " ";
        values[x[i]].erase(values[x[i]].begin());
      }
    }
    cout << endl;
  }
  return 0;
}
