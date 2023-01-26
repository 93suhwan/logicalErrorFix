#include <bits/stdc++.h>
using namespace std;
int query(int i, int j, int k) {
  cout << "? " << i << " " << j << " " << k << endl;
  int ans;
  cin >> ans;
  return ans;
}
int32_t main() {
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    vector<int> ones, zeros;
    for (int i = 1; i < n; i += 3) {
      int que = query(i, i + 1, i + 2);
      if (que == 0)
        zeros.push_back(i);
      else
        ones.push_back(i);
    }
    set<int> impos, crew;
    int sav = -1;
    for (int first0 : zeros) {
      if (!crew.empty() && !impos.empty()) break;
      int first1 = ones.front();
      vector<int> a = {first0, first0 + 1, first0 + 2},
                  b = {first1, first1 + 1, first1 + 2};
      vector<int> left;
      vector<vector<int>> hero(3);
      for (int i = 0; i < 3; i++) {
        if (!crew.empty() && !impos.empty()) break;
        int a1 = a[(i + 1) % 3], a2 = a[(i + 2) % 3];
        for (int j = 0; j < 3; j++) {
          if (hero[i].size() == 2) {
            hero[i].push_back(j);
            break;
          }
          int que = query(a1, a2, b[j]);
          if (que == 0) hero[i].push_back(j);
        }
        if (hero[i].size() == 3) {
          impos.insert(a1);
          impos.insert(a2);
          left.push_back(a[i]);
        } else if (hero[i].size() == 1) {
          crew.insert(b[(hero[i][0] + 1) % 3]);
          crew.insert(b[(hero[i][0] + 2) % 3]);
          impos.insert(b[hero[i][0]]);
          break;
        } else if (hero[i].empty()) {
          crew.insert(first1);
        }
      }
      if (!crew.empty() && !impos.empty()) break;
      if (left.size() == 3) {
        sav = first1;
        if (n == 6) break;
        for (int i = 0; i < 3; i++) {
          int b1 = b[(i + 1) % 3], b2 = b[(i + 2) % 3];
          int que = query(first0, b1, b2);
          if (que == 0)
            continue;
          else {
            crew.insert(b1);
            crew.insert(b2);
            break;
          }
        }
      } else {
        crew.insert(left[0]);
        break;
      }
      break;
    }
    if (crew.empty()) {
      crew.insert(sav);
      crew.insert(sav + 1);
      crew.insert(sav + 2);
    }
    for (int i = 1; i <= n; i++) {
      if (impos.find(i) != impos.end() || crew.find(i) != crew.end()) continue;
      int que = query(*impos.begin(), *crew.begin(), i);
      if (que == 0) impos.insert(i);
    }
    cout << "! ";
    cout << impos.size() << " ";
    for (auto &ele : impos) cout << ele << " ";
    cout << endl;
  }
  return 0;
}
