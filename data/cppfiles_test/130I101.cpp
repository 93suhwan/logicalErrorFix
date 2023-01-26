#include <bits/stdc++.h>
using namespace std;
int n;
map<vector<int>, int> mp;
int query_cnt = 0;
int query(int i, int j, int k) {
  vector<int> que = {i, j, k};
  sort(que.begin(), que.end());
  if (mp.find(que) != mp.end()) return mp[que];
  query_cnt++;
  assert(query_cnt <= n + 6);
  cout << "? " << i << " " << j << " " << k << endl;
  int ans;
  cin >> ans;
  mp[que] = ans;
  return ans;
}
int32_t main() {
  int tc;
  cin >> tc;
  while (tc--) {
    query_cnt = 0;
    mp.clear();
    cin >> n;
    set<int> impos, crew;
    int nby2 = n >> 1;
    int prev = query(nby2 - 1, nby2, nby2 + 1);
    for (int i = 1; nby2 + i + 1 <= n && nby2 - 1 - i >= 1; i++) {
      int que1 = query(nby2 - 1 + i, nby2 + i, (nby2 + i + 1));
      if (prev != que1) {
        if (que1 == 0) {
          impos.insert(nby2 + i + 1);
          crew.insert(nby2 + i - 2);
        } else {
          crew.insert(nby2 + i + 1);
          impos.insert(nby2 + i - 2);
        }
        break;
      }
      int que2 = query(nby2 - 1 - i, nby2 - i, nby2 - i + 1);
      if (prev != que1) {
        if (que1 == 0) {
          impos.insert(nby2 - i - 1);
          crew.insert(nby2 - i + 2);
        } else {
          crew.insert(nby2 - i - 1);
          impos.insert(nby2 - i + 2);
        }
        break;
      }
    }
    for (int i = 1; i <= n; i++) {
      if (impos.find(i) != impos.end() || crew.find(i) != crew.end()) continue;
      int que = query(*crew.begin(), *impos.begin(), i);
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
