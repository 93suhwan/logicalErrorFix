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
      if (!ones.empty() && !zeros.empty()) break;
      int que = query(i, i + 1, i + 2);
      if (que == 0)
        zeros.push_back(i);
      else
        ones.push_back(i);
    }
    set<int> impos, crew;
    int sav = -1;
    int first0 = zeros.front();
    int first1 = ones.front();
    vector<int> a = {first0, first0 + 1, first0 + 2},
                b = {first1, first1 + 1, first1 + 2};
    int cnt = 0;
    for (int i = 0; i < 2; i++) {
      int que = query(a[1], a[2], b[i]);
      if (que == 0) cnt++;
    }
    if (cnt == 2) {
      impos.insert(a[1]);
      impos.insert(a[2]);
    } else if (cnt == 1) {
      impos.insert(a[0]);
    } else {
      crew.insert(b[0]);
      crew.insert(b[1]);
    }
    if (crew.empty()) {
      for (int j = 0; j < 3; j++) {
        int b1 = b[(j + 1) % 3], b2 = b[(j + 2) % 3];
        int que = query(b1, b2, *impos.begin());
        if (que == 1) {
          crew.insert(b1);
          crew.insert(b2);
          break;
        }
      }
    } else if (impos.empty()) {
      for (int j = 0; j < 3; j++) {
        int a1 = a[(j + 1) % 3], a2 = a[(j + 2) % 3];
        int que = query(a1, a2, *crew.begin());
        if (que == 0) {
          impos.insert(a1);
          impos.insert(a2);
          break;
        }
      }
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
