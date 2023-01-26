#include <bits/stdc++.h>
using namespace std;
map<vector<int>, int> mp;
int query(int i, int j, int k) {
  vector<int> que = {i, j, k};
  sort(que.begin(), que.end());
  if (mp.find(que) != mp.end()) return mp[que];
  cout << "? " << i << " " << j << " " << k << endl;
  int ans;
  cin >> ans;
  return ans;
}
int32_t main() {
  int tc;
  cin >> tc;
  while (tc--) {
    mp.clear();
    int n;
    cin >> n;
    set<int> impos, crew;
    int prev = query(1, 2, 3);
    for (int i = 2; i + 2 <= n; i++) {
      int que = query(i, i + 1, i + 2);
      if (que != prev) {
        if (que == 0) {
          impos.insert(i + 2);
          crew.insert(i - 1);
        } else {
          impos.insert(i - 1);
          crew.insert(i + 2);
        }
        break;
      }
    }
    for (int i = 1; i <= n; i++) {
      if (impos.find(i) != impos.end() || crew.find(i) != crew.end()) continue;
      auto near_impos = impos.lower_bound(i - 2);
      auto near_crew = crew.lower_bound(i - 2);
      if (near_impos == impos.end()) {
        near_impos = impos.begin();
      }
      if (near_crew == crew.end()) {
        near_crew = crew.begin();
      }
      int que = query(*near_crew, *near_impos, i);
      if (que == 0)
        impos.insert(i);
      else
        crew.insert(i);
    }
    cout << "! ";
    cout << impos.size() << " ";
    for (auto &ele : impos) cout << ele << " ";
    cout << endl;
  }
  return 0;
}
