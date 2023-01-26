#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> v;
  unordered_map<int, vector<int>> myNums;
  long long int mean = 0;
  for (int i = 0; i < n; i++) {
    int el;
    cin >> el;
    mean += el;
    v.push_back(el);
  }
  if (2 * mean % n != 0) {
    cout << "0\n";
    return;
  }
  for (int i = 0; i < n; i++) {
    int el = v[i];
    if (myNums.count(el) > 0) {
      myNums[el].push_back(i);
    } else {
      vector<int> soloV{i};
      myNums[el] = soloV;
    }
  }
  double f_mean = (double)mean / n;
  int ans = 0;
  for (int i = 0; i < v.size() - 1; i++) {
    long long int target = 2 * f_mean - v[i];
    if (myNums.count(target) > 0) {
      vector<int> listIndices = myNums[target];
      int step = listIndices.size();
      int mapIndex = -1;
      for (int j = step; j >= 1; j /= 2) {
        while (listIndices[j + mapIndex] <= i) mapIndex += j;
      }
      mapIndex++;
      if (mapIndex < listIndices.size()) ans += listIndices.size() - mapIndex;
    }
  }
  cout << ans << '\n';
}
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    solve();
  }
  return 0;
}
