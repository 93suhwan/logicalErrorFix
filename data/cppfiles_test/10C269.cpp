#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) {
      mp[arr[i]].push_back(i);
    }
    vector<int> res(n, 0);
    int remainingElems = 0;
    for (auto x : mp) {
      int ele = x.first;
      vector<int> temp = x.second;
      if (temp.size() >= k) {
        for (int i = 0; i < k; i++) {
          res[temp[i]] = i + 1;
        }
        mp[ele] = {};
      } else {
        remainingElems += temp.size();
      }
    }
    int factor = remainingElems / k;
    remainingElems = factor * k;
    int currColor = 0;
    for (auto x : mp) {
      int ele = x.first;
      vector<int> curr = x.second;
      bool flag = true;
      if (remainingElems == 0) break;
      if (curr.size() > 0) {
        for (int i = 0; i < curr.size(); i++) {
          res[curr[i]] = currColor + 1;
          currColor = (currColor + 1) % k;
          remainingElems--;
          if (remainingElems == 0) {
            flag = false;
            break;
          }
        }
      }
      if (flag == false) break;
    }
    for (auto x : res) cout << x << " ";
    cout << '\n';
  }
  return 0;
}
