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
    map<int, int> mp;
    for (auto x : arr) mp[x]++;
    vector<int> res(n, -1);
    map<int, int> fullyColored;
    int remainingElems = 0;
    for (auto x : mp) {
      int ele = x.first;
      int freq = x.second;
      if (freq >= k) {
        fullyColored[ele] = k;
        mp[ele] = 0;
      } else {
        remainingElems += freq;
      }
    }
    for (int i = 0; i < n; i++) {
      if (fullyColored.find(arr[i]) != fullyColored.end()) {
        if (fullyColored[arr[i]] > 0) {
          res[i] = fullyColored[arr[i]];
          fullyColored[arr[i]]--;
        }
      }
    }
    int factor = remainingElems / k;
    remainingElems = factor * k;
    int currColor = 0;
    for (int i = 0; i < n && remainingElems > 0; i++) {
      if (mp[arr[i]] > 0) {
        res[i] = currColor + 1;
        currColor = (currColor + 1) % k;
        mp[arr[i]]--;
        remainingElems--;
      }
    }
    for (int i = 0; i < n; i++) {
      if (res[i] == -1) res[i] = 0;
    }
    for (int i = 0; i < n; i++) {
      cout << res[i] << " ";
    }
    cout << "\n";
  }
  return 0;
}
