#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    set<int> list;
    set<pair<int, int>> y;
    int count;
    cin >> count;
    for (int i = 0; i < count; i++) {
      int x;
      cin >> x;
      list.insert(x);
    }
    int count2 = count / 2;
    auto end = list.end();
    for (auto i = list.begin(); i != end; ++i) {
      for (auto j = i; j != end; ++j) {
        if ((*j > *i) && (list.count(*j % *i) == 0)) {
          y.insert(pair<int, int>(*j, *i));
          count2--;
        }
        if (count2 == 0) break;
        if ((*j > *i) && (list.count(*i % *j) == 0)) {
          y.insert(pair<int, int>(*i, *j));
          count2--;
        }
        if (count2 == 0) break;
      }
      if (count2 == 0) break;
    }
    auto end2 = y.end();
    for (auto i = y.begin(); i != end2; ++i) {
      cout << (*i).first << ' ' << (*i).second << "\n";
    }
  }
}
