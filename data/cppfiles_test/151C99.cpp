#include <bits/stdc++.h>
using namespace std;
int main() {
  int q;
  std::cin >> q;
  vector<vector<int>> pr;
  vector<int> res;
  unordered_map<int, int> mp;
  for (int t = 0; t < q; ++t) {
    int query;
    cin >> query;
    if (query == 1) {
      int x;
      cin >> x;
      res.push_back(x);
      vector<int> temp = {0, x};
      pr.push_back(temp);
    } else {
      int x, y;
      cin >> x >> y;
      vector<int> temp = {x, y};
      pr.push_back(temp);
    }
  }
  int k = res.size() - 1;
  for (int i = pr.size() - 1; i >= 0; --i) {
    int x = pr[i][0], y = pr[i][1];
    if (x > 0) {
      if (mp.count(y)) {
        mp[x] = mp[y];
      } else {
        mp[x] = y;
      }
    } else {
      int t = res[k];
      if (mp.count(t)) res[k] = mp[t];
      --k;
    }
  }
  for (int a : res) {
    cout << a << " ";
  }
  cout << endl;
  return 0;
}
