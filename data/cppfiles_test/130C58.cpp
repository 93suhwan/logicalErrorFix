#include <bits/stdc++.h>
using namespace std;
int n;
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
    cin >> n;
    set<int> impos, crew;
    vector<int> ans(n + 1);
    for (int i = 1; i <= n; i += 3) {
      ans[i] = query(i, i + 1, i + 2);
    }
    int i1;
    for (int i = 1; i <= n; i += 3) {
      if (ans[i] != ans[i + 3]) {
        i1 = i;
        break;
      }
    }
    ans[i1 + 1] = query(i1 + 1, i1 + 2, i1 + 3);
    ans[i1 + 2] = query(i1 + 2, i1 + 3, i1 + 4);
    for (int i = i1; i < i1 + 3; i++) {
      if (ans[i] != ans[i + 1]) {
        if (ans[i] == 0) {
          impos.insert(i);
          crew.insert(i + 3);
        } else {
          crew.insert(i);
          impos.insert(i + 3);
        }
        for (int j = i1; j < i1 + 6; j++) {
          if (impos.find(j) != impos.end() || crew.find(j) != crew.end())
            continue;
          int que = query(*impos.begin(), *crew.begin(), j);
          if (que == 0)
            impos.insert(j);
          else
            crew.insert(j);
        }
        break;
      }
    }
    for (int i = 1; i <= n; i += 3) {
      if (i == i1 || i == i1 + 3) continue;
      if (ans[i] == 0) {
        int que1 = query(i, i + 1, *crew.begin());
        if (que1 == 1) {
          int que2 = query(i, i + 2, *crew.begin());
          if (que2 == 1) {
            crew.insert(i);
            impos.insert(i + 1);
            impos.insert(i + 2);
          } else {
            crew.insert(i + 1);
            impos.insert(i);
            impos.insert(i + 2);
          }
        } else {
          int que2 = query(i, i + 2, *crew.begin());
          if (que2 == 1) {
            crew.insert(i + 2);
            impos.insert(i);
            impos.insert(i + 1);
          } else {
            impos.insert(i);
            impos.insert(i + 1);
            impos.insert(i + 2);
          }
        }
      } else {
        int que1 = query(i, i + 1, *impos.begin());
        if (que1 == 1) {
          int que2 = query(i, i + 2, *impos.begin());
          if (que2 == 1) {
            crew.insert(i);
            crew.insert(i + 1);
            crew.insert(i + 2);
          } else {
            crew.insert(i + 1);
            crew.insert(i);
            impos.insert(i + 2);
          }
        } else {
          int que2 = query(i, i + 2, *impos.begin());
          if (que2 == 1) {
            crew.insert(i + 2);
            crew.insert(i);
            impos.insert(i + 1);
          } else {
            impos.insert(i);
            crew.insert(i + 1);
            crew.insert(i + 2);
          }
        }
      }
    }
    cout << "! ";
    cout << impos.size() << " ";
    for (auto &ele : impos) cout << ele << " ";
    cout << endl;
  }
  return 0;
}
