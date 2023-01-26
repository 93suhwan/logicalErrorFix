#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n];
    vector<pair<int, int>> res;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
      int m = a[i];
      int ind = i;
      for (int j = i + 1; j < n; j++) {
        if (a[j] < a[i]) {
          m = a[j];
          ind = j;
        }
      }
      int k = a[ind];
      for (int j = ind; j > i; j--) {
        a[j] = a[j - 1];
      }
      a[i] = k;
      if (i != ind) res.push_back({i + 1, ind + 1});
    }
    cout << res.size() << endl;
    for (auto x : res) {
      cout << x.first << " " << x.second << " 1" << endl;
    }
  }
}
