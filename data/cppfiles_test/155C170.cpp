#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int arr[n];
    int ans[n];
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    string s;
    cin >> s;
    vector<pair<int, int>> bad, good;
    for (int i = 0; i < (int)s.size(); i++) {
      if (s[i] == '1')
        good.push_back({arr[i], i});
      else
        bad.push_back({arr[i], i});
    }
    sort(bad.begin(), bad.end());
    sort(good.begin(), good.end());
    sort(arr, arr + n);
    int id = 0;
    for (int i = 0; i < bad.size(); i++) {
      ans[bad[i].second] = arr[id];
      id++;
    }
    for (int i = 0; i < good.size(); i++) {
      ans[good[i].second] = arr[id];
      id++;
    }
    for (auto xx : ans) cout << xx << " ";
    cout << "\n";
  }
}
